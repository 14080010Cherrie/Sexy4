// Sexy4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "minijson_reader.hpp"
#include "paraser.h"
#include "Pos.h"
using namespace std;
using namespace minijson;

int main()
{
	//ifstream ifs("in.json", ios::in);	//����1
	ifstream ifs("in2.json", ios::in);	//����2
	istreambuf_iterator<char> beg(ifs), end;
	string source(beg, end);
	ifs.close();

	char * a = (char*)source.data();
	Items items = Decode(a);

	Pos pos(items);
	pos.Display();

	return 0;
}

