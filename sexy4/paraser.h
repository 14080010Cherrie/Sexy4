#pragma once
#include <map>
using namespace std;
using namespace minijson;
#include "Items.h"

Items Decode(char * source)
{
	Items obj;
	buffer_context ctx(source, strlen(source));
	parse_array(ctx, [&](value v)
	{
		Item item;
		minijson::parse_object(ctx, [&](const char* name, value v)
		{
			minijson::dispatch(name)
			<< "barcode" >> [&] { item.setBarcode(v.as_string()); }
			<< "name" >> [&] { item.setName(v.as_string()); }
			<< "unit" >> [&] { item.setUnit(v.as_string()); }
			<< "price" >> [&] { item.setPrice(v.as_double()); }
			<< "discount" >> [&] { item.setDiscount(v.as_double()); }
			<< minijson::any >> [&] { minijson::ignore(ctx); /* or throw */ };
		});
		obj.Add(item);
	});
	return obj;
}

map<string, Item> DecodeIndex(char * source)
{
	map<string, Item> indexes;
	Item item;
	buffer_context ctx(source, strlen(source));
	minijson::parse_object(ctx, [&](const char* name, value v)
	{
		minijson::dispatch(name)
		<< minijson::any >> [&]
		{
			string barcode = name;
			item.setBarcode(barcode);
			parse_object(ctx, [&](const char* k, value v)
			{
				dispatch(k)
					<< "name" >> [&] { item.setName(v.as_string()); }
					<< "unit" >> [&] {item.setUnit(v.as_string()); }
					<< "price" >> [&] {item.setPrice(v.as_double()); }
					<< "discount" >> [&] {item.setDiscount(v.as_double()); }
					<< "promotion" >> [&] {item.setPromotion(v.as_bool()); }
					<< minijson::any >> [&] { minijson::ignore(ctx); };
			});
			indexes.insert(pair<string,Item>(barcode,item));
			minijson::ignore(ctx);
		};
	});
	return indexes;
}

vector<string> DecodeItems(char *source)
{
	vector<string> barcodes;
	buffer_context ctx(source, strlen(source));
	parse_array(ctx, [&](value v)
	{
		barcodes.push_back(v.as_string());
	});
	return barcodes;
}
