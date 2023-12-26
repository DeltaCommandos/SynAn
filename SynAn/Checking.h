#pragma once
#include "Input.h"
#include <vector>
#include <string>
using namespace std;

class Checking: public Input
{
private:
	string Vars[7] = { "int", "char", "string", "bool", "float", "double","void" };
	string Names[17] = { "int", "char", "string", "bool", "float", "double", "for","while","break","continue","do","#define","#include","using","namespace","printf","//"};
	string Opers[19] = { "=", "<", ">", ">=", "<=", "!=", "+", "-", "+=", "-=", "++", "--", "(", ")", "{", "}", ";", "," };
	struct Errors {
		vector <string> Description{};
		vector <int> StrNum{};
	};
	struct Init {
		vector <string> Type{};
		vector <string> Name{};
		vector <string> Data{};

	};

protected:
	Errors ErrStrAndNum;
	Errors ErrBr;
	vector <string> ErrOnlyStr{};
	vector <string> namesint{};
	Init IniList;
public:

	void bracketCheck();

	void conBreCheck(int a);


	void IniCheck();

	void mainCheck();

	

};

