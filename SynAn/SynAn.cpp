#include "Output.h"
#include <stdio.h>


int main()
{
    setlocale(LC_ALL, "Russian");
	
	int com = 0;

	while (1) {
		Output Yo;
		//Yo.loading(1);
		Yo.print_menu(&com);
		
		switch (com)
		{

		case 1: // Чек
		{    
			//Yo.loading(2);
			system("cls");
			char c[20] = "0_0.txt";
			Yo.Out(c);
			break;
		}

		case 2: // Открыть файл
		{
			system("0_0.txt");
			break;
		}
		case 3:   // Выход
		{
			exit(0);
		}
		default: {

			printf("Error!\n");
			exit(0);
			break;
		}

		}
		system("cls");
	}

}

