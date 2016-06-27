#pragma once
#include <vector>
#include <map>
#include "Items.h"
#include "Report.h"
using namespace std;
class Pos
{
private:
	Items items;
public:
	Pos(Items itm)
	{
		items = itm;
	}

	Pos(map<string, Item> indexes, vector<string> items)
	{
		Items list;
		for (string item : items)
		{
			list.Add(indexes[item]);
		}
		this->items = list;
	}

	void Display()
	{
		vector<Item> list = items.getlist();
		Report report(list);
		cout << "***商店购物清单***" << endl;
		for (Items itemGroup : report.getItemGroupies()) {
			cout << "名称：" << itemGroup.groupName() << "，" <<
				"数量：" << itemGroup.groupSize() << itemGroup.groupUnit() << "，" <<
				"单价：" << itemGroup.groupPrice() << "(元)" << "，" <<
				"小计：" << itemGroup.subTotal() << "(元)" << endl;
		}
		if (report.hasPromotion()) {
			cout << "----------------------" << endl;
			cout << "挥泪赠送商品：" << endl;
			for (Items itemGroup : report.getItemGroupies()){
				if (itemGroup.groupPromotion()){
					cout << "名称：" << itemGroup.groupName() << "，" << "数量：" << 1 << itemGroup.groupUnit() << endl;
				}
			}
		}
		cout << "----------------------" << endl;
		cout << "总计：" << report.getTotal() << "(元)" << endl;

		double saving = report.getSaving();
		if (saving > 0) {
			cout << "节省：" << saving << "(元)" << endl;
		}
		cout << "**********************" << endl;
	}
};
