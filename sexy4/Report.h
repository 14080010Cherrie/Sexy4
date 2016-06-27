#pragma once
#include "Items.h"
#include <vector>
#include <map>
using namespace std;
class Report {
private:
	vector<Items> itemGroupies;
	map<string, vector<Item>> groupByItemBarCode(vector<Item> items)
	{
		map<string, vector<Item>> map;
		for (Item item : items) {
			string itemBarCode = item.getBarcode();
			map[itemBarCode].push_back(item);
		}
		return map;
	}
public :
	Report(vector<Items> items)
	{
		itemGroupies = items;
	}

	Report(vector<Item> items)
	{
		map<string, vector<Item>> mapper = groupByItemBarCode(items);
		map<string, vector<Item>>::iterator  iter;
		for (iter = mapper.begin(); iter != mapper.end(); iter++)
			itemGroupies.push_back(iter->second);
	}

	vector<Items> getItemGroupies()
	{
		return itemGroupies;
	}

	bool hasPromotion()
	{
		bool result = false;
		for (Items itemGroup : itemGroupies)
			result |= itemGroup.groupPromotion();
		return result;
	}

	double getTotal()
	{
		double result = 0.00;
		for (Items Items : itemGroupies)
			result += Items.subTotal();
		return result;
	}

	double getSaving()
	{
		double result = 0.00;
		for (Items Items : itemGroupies)
			result += Items.saving();
		return result;
	}
};
