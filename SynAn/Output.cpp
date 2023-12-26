#include "Output.h"

//void Output::loading(int count) {
//	for (int i = 0; i < count; i++) {
//		Sleep(100);
//		cout << "\b\\" << std::flush;
//		Sleep(100);
//		cout << "\b|" << std::flush;
//		Sleep(100);
//		cout << "\b/" << std::flush;
//		Sleep(100);
//		cout << "\b-" << std::flush;
//	}
//}

void Output::Coloring() {

	ArrColors["int"] = "\x1b[1;34mint\x1b[1;0m";
	ArrColors["double"] = "\x1b[1;34mdouble\x1b[1;0m";
	ArrColors["float"] = "\x1b[1;34mfloat\x1b[1;0m";
	ArrColors["string"] = "\x1b[38;5;043mstring\x1b[1;0m";
	ArrColors["char"] = "\x1b[1;34mchar\x1b[1;0m";
	ArrColors["void"] = "\x1b[1;94mvoid\x1b[1;0m";

	ArrColors["while"] = "\x1b[38;5;165mwhile\x1b[1;0m";
	ArrColors["for"] = "\x1b[38;5;165mfor\x1b[1;0m";
	ArrColors["printf"] = "\x1b[1;33mprintf\x1b[1;0m";

	ArrColors["if"] = "\x1b[38;5;135mif\x1b[1;0m";
	ArrColors["else"] = "\x1b[38;5;135melse\x1b[1;0m";

	ArrColors["#define"] = "\x1b[38;5;008m#define\x1b[1;0m";
	ArrColors["#include"] = "\x1b[38;5;008m#include\x1b[1;0m";

	ArrColors["using"] = "\x1b[1;34musing\x1b[1;0m";
	ArrColors["namespace"] = "\x1b[1;34mnamespace\x1b[1;0m";

	ArrColors["continue"] = "\x1b[38;5;165mcontinue\x1b[1;0m";
	ArrColors["break"] = "\x1b[38;5;165mbreak\x1b[1;0m";
	ArrColors["//"] = "\x1b[38;5;034m//\x1b[38;5;034m";
	ArrColors["\n"] = "\x1b[1;0m\n\x1b[1;0m";

}

void Output::printErr() {

	bracketCheck();
	int Elen = min(ErrBr.StrNum.size(), ErrBr.Description.size());
	for (int i = 0; i < Elen; i++) {
		int lines = ErrBr.StrNum[i];
		string des = ErrBr.Description[i];
		cout << "\nНе хватает " << lines << des << endl;
		flag = 1;
	}

	conBreCheck(8);
	conBreCheck(9);
	mainCheck();
	//IniCheck();
	Elen = min(ErrStrAndNum.StrNum.size(), ErrStrAndNum.Description.size());  // ConBreak & Ini
	for (int i = 0; i < Elen; i++) {
		int lines = ErrStrAndNum.StrNum[i];
		string des = ErrStrAndNum.Description[i];
		cout << "\nВ строке " << lines << des << endl;
		flag = 1;
	}

	for (string elem : ErrOnlyStr) {
		cout << "\n" << elem;
		flag = 1;
	}


}

void Output::mshkfrd() {    //print code
	Coloring();
	cout << "\x1b[38;5;034mo===o=======================================================================0\033[1;0m\n";
	cout << "\x1b[38;5;034m|1  |\033[1;0m";
	int n = 2;
	for (string elem : ArrStr) {
		int k = 0;

		if (elem == "\n") {
			if (n < 10)
				cout << "\x1b[38;5;034m\n|" << n << "  |\033[1;0m";

			else
				cout << "\x1b[38;5;034m\n|" << n << " |\033[1;0m";
			n++;
			continue;
		}
		int comment = 0;
		for (auto el : ArrColors) {
			
			if (elem == el.first) {

				if (elem == "\x1b[38;5;034m//\x1b[38;5;034m") {
					comment = 1;
				}
				if (elem == "\n")
					comment = 0;
				if (comment == 1)
					continue;

				cout << el.second;
				k = 1;
				break;
			}
		}

		for (string s : namesint)
		{
			if (elem == s) {
				cout << "\x1b[38;5;039m";
				cout << s;
				cout << "\x1b[1;0m";
				k = 1;
				break;
			}
		}

		if (k == 0)
			cout << elem;

	}
	cout << "\x1b[38;5;034m\no===o=======================================================================0\033[1;0m\n";

		printf("\n\033[1;31m0===========================================================================0\n");
		printErr();
		printf("\n\n0===========================================================================0\n\033[1;0m");
	
}   

void Output::Out(char c[20]) {
	WordSeparating(c);
	mshkfrd();
	system("pause");
}

void Output::print_menu(int* com) {

	//printf("\x1b[32mWelcome to super duper syntax analyzer!\n\n What do you want to do?\n ");
	//printf("Please, print one of nums:\n\n \t1. Check code \n \t2. Output on display\n \t3. Exit\n\n");
	//printf("Print here -> \x1b[0m");
	//scanf("%d", com);

	//loading(8);
	system("cls");
	printf("\n\t\t\x1b[38;5;046m0===================================================================================0\n");
	printf("\t\t\x1b[38;5;040m| @@@@ @   @ @   @ @@@@@   @   @   @      @   @   @   @   @    @   @ @@@@ @@@@ @@@  |\n");
	printf("\t\t\x1b[38;5;040m| @    @   @ @@  @   @    @ @   @ @      @ @  @@  @  @ @  @    @   @    @ @    @  @ |\n");
	printf("\t\t\x1b[38;5;034m| @@@@  @@@  @ @ @   @    @@@    @       @@@  @ @ @  @@@  @     @@@   @@  @@@@ @@@  |\n");
	printf("\t\t\x1b[38;5;034m|    @   @   @  @@   @   @   @  @ @     @   @ @  @@ @   @ @      @   @    @    @ @@ |\n");
	printf("\t\t\x1b[38;5;028m| @@@@   @   @   @   @   @   @ @   @    @   @ @   @ @   @ @@@@   @   @@@@ @@@@ @  @ |\n");
	printf("\t\t\x1b[38;5;028m0===================================================================================0\n");
	printf("\t\t\x1b[32m|                                                                                   |\n");
	printf("\t\t| Добро пожаловать в супер-дупер синтаксический анализатор!                         |\n");
	printf("\t\t| Эй, Брейн, чем мы будем заниматься сегодня?                                       |\n\t\t|                                                                                   |\n");
	printf("\t\t| Введите одно из чисел:                                                            |\n");
	printf("\t\t|                                                                                   |\n\t\t|                                                                                   |\n");
	printf("\t\t|\t1. Проверка кода                                                            | \n");
	printf("\t\t|\t2. Открыть файл                                                             | \n");
	printf("\t\t|\t3. Выход                                                                    | \n\t\t|                                                                                   |\n\t\t");
	printf("\x1b[38;5;028m0===================================================================================0\n");
	printf("\n\t\t\x1b[38;5;040m   Вводить здесь -> ");
	scanf("%d", com);
	printf("\033[1;0m");
}

