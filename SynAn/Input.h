#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

#pragma once
class Input
{
protected:
	char OneStr[1000];
	string ArrStr[1000]; //все
	string ArrNoSpace[1000]; //все без табов и пробелов
	int N = 0; //кол-во слов без разделителей
public:

	int Import(char file[20]);

	int WordSeparating(char c[20]);

};

