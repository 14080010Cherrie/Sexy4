#pragma once
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

