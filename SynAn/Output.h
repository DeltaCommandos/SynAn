#pragma once
#include <map>
#include "Checking.h"
#include "windows.h"
#include <iostream>
using namespace std;

class Output: protected Checking
{
protected:
	bool flag = 0;
public:
	std::map <string, string> ArrColors;

	//void loading(int count);
	void Coloring();
	void printErr();
	void mshkfrd();
	void Out(char c[20]);
	void print_menu(int* com);

};

