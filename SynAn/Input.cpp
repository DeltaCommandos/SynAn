#include "Input.h"

int Input::Import(char file[20]) {

	FILE* f;
	char c;
	int i = 0;
	f = fopen(file, "r");
	while ((c = getc(f)) != EOF) {
		OneStr[i] = c;
		i++;
	}
	fclose(f);
	return i;
}

int Input::WordSeparating(char c[20]) {

	int i = Import(c);
	int i1 = 0, i2 = 0;

	char Seps[]{ ' ',';','(',')','{','}','\n','\t','"',',','//' }; //разделители
	while (i1 < i) {
		int a = 52;
		for (int k = 0; k < 10; k++) {
			if (OneStr[i1] == Seps[k]) {
				a = 0;
				break;
			}
		}
		switch (a) { //ввод в массив со всем
		case 0:
			i2++;
			ArrStr[i2] += OneStr[i1];
			i2++;
			break;
		default:
			ArrStr[i2] += OneStr[i1];
		}
		i1++;
	}

	for (int i = 0; i < i2; i++) {

		if (ArrStr[i] != " " && ArrStr[i] != "" && ArrStr[i] != "\t") {
			ArrNoSpace[N] = ArrStr[i];
			N++;
		}
	}
	return i2;
}
