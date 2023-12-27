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
		case 3:
		{
			system("cls");
			printf("\n\t\x1b[38;5;040mУсловие задачи:\n\t12. Написать программу, определяющую корректность \n\tрасположения в коде операторов continue\n\x1b[1;0m");
			system("pause");
			break;
		}
		case 4:   // Выход
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

