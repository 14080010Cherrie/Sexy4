#pragma once
class Item
{
private:
	string barcode;
	string name;
	string unit;
	float price;
	float discount;
public:
	Item() {
		setDiscount(1);
	}

	Item(string barcode, string name, string unit, double price) {
		setBarcode(barcode);
		setName(name);
		setUnit(unit);
		setPrice(price);
		setDiscount(1);
	}

	Item(string barcode, string name, string unit, double price, double discount) {
		setBarcode(barcode);
		setName(name);
		setUnit(unit);
		setPrice(price);
		setDiscount(discount);
	}

	string getName() {
		return name;
	}
	string getUnit() {
		return unit;
	}

	double getPrice() {
		return price;
	}

	string getBarcode() {
		return barcode;
	}

	double getDiscount() {
		if (discount == 0.00)
			return 1.00;
		return discount;
	}

	void setBarcode(string s)
	{
		barcode = s;
	}

	void setName(string s)
	{
		name = s;
	}

	void setUnit(string s) {
		unit = s;
	}

	void setPrice(double v) {
		price = v;
	}

	void setDiscount(double v) {
		discount = v;
	}
};

class Items
{
private:
	vector<Item> list;
public:
	Items()
	{

	}

	Items(vector<Item> items)
	{
		list = items;
	}

	void Add(Item itm)
	{
		list.push_back(itm);
	}

	vector<Item> &getlist()
	{
		return list;
	}
	string groupName() {
		return list[0].getName();
	}

	int groupSize() {
		return list.size();
	}

	string groupUnit() {
		return list[0].getUnit();
	}

	double groupPrice() {
		return list[0].getPrice();
	}

	double subTotal() {
		double result = 0.00;
		for (Item item : list)
			result += item.getPrice() * item.getDiscount();
		return result;
	}

	double saving() {
		double result = 0.00;
		for (Item item : list)
			result += item.getPrice() * (1 - item.getDiscount());
		return result;
	}
};