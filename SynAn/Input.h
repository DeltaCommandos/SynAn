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
	string ArrStr[1000]; //���
	string ArrNoSpace[1000]; //��� ��� ����� � ��������
	int N = 0; //���-�� ���� ��� ������������
public:

	int Import(char file[20]);

	int WordSeparating(char c[20]);

};

