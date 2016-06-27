// Sexy4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "minijson_reader.hpp"
#include "paraser.h"
#include "Pos.h"
using namespace std;
using namespace minijson;

int main()
{
	/*//测试1
	ifstream ifs("in.json", ios::in);	
	istreambuf_iterator<char> beg(ifs), end;
	string source(beg, end);
	ifs.close();
	char * a = (char*)source.data();
	Items items = Decode(a);
	Pos pos(items);
	pos.Display();
	*/

	/*//测试2
	ifstream ifs("in2.json", ios::in);	
	istreambuf_iterator<char> beg(ifs), end;
	string source(beg, end);
	ifs.close();
	char * a = (char*)source.data();
	Items items = Decode(a);
	Pos pos(items);
	pos.Display();
	*/

	//测试3
	ifstream ifs("in3index.json", ios::in);
	istreambuf_iterator<char> beg(ifs), end;
	string source(beg, end);
	ifs.close();

	ifstream ifs2("in3items.json", ios::in);
	istreambuf_iterator<char> beg2(ifs2), end2;
	string source2(beg2, end2);
	ifs2.close();

	char * a = (char*)source.data();
	char * b = (char*)source2.data();

	map<string,Item> indexes =  DecodeIndex(a);
	vector<string> items = DecodeItems(b);

	Pos pos(indexes, items);
	pos.Display();
	
	/*//测试4
	ifstream ifs("in4index.json", ios::in);
	istreambuf_iterator<char> beg(ifs), end;
	string source(beg, end);
	ifs.close();

	ifstream ifs2("in4items.json", ios::in);
	istreambuf_iterator<char> beg2(ifs2), end2;
	string source2(beg2, end2);
	ifs2.close();

	char * a = (char*)source.data();
	char * b = (char*)source2.data();

	map<string, Item> indexes = DecodeIndex(a);
	vector<string> items = DecodeItems(b);

	Pos pos(indexes, items);
	pos.Display();
	*/
	system("pause");
	return 0;
}

