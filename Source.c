#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"structs.h"
#include"functions.h"
#include"menu_functions.h"

int main()
{
	int data_input_test=0;
		do{
	menu_main();
	scanf("%d", &menu_1);
	switch (menu_1)
	{
	case 1:
		add();
		break;
	case 2:
		if (photo != NULL){
		menu_picture_m();
		}
		else printf("Brak obrazu");
		break;
	case 3:
		filter_menu();
		break;
	case 4:
		noise_m();
		break;
	case 5:
		histogram_m();
		break;
	case 6:
		menu_geometry_m();
		break;
	case 7:
		save_m();
		break;
	case 8:
		end(photo);
		system("pause");
		return 0;
		break;
	}
	} while ((menu_1 = getchar()) != 9);
}

 