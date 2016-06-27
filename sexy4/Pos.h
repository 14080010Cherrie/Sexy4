#pragma once
#include <vector>
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
	void Display()
	{
		vector<Item> list = items.getlist();
		Report report(list);
		cout << "***�̵깺���嵥***" << endl;
		for (Items itemGroup : report.getItemGroupies()) {
			cout << "���ƣ�" << itemGroup.groupName() << "��" <<
				"������" << itemGroup.groupSize() << itemGroup.groupUnit() << "��" <<
				"���ۣ�" << itemGroup.groupPrice() << "(Ԫ)" << "��" <<
				"С�ƣ�" << itemGroup.subTotal() << "(Ԫ)" << endl;
		}
		cout << "----------------------" << endl;
		cout << "�ܼƣ�" << report.getTotal() << "(Ԫ)" << endl;

		double saving = report.getSaving();
		if (saving > 0) {
			cout << "��ʡ��" << saving << "(Ԫ)" << endl;
		}
		cout << "**********************" << endl;
	}
};