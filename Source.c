#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"structs.h"
#include"functions.h"
#include"menu_functions.h"

int main()
{
	data_input_test = 0;
	photo = NULL;
		do{
	menu_main();
	scanf("%d", &menu_1);
	switch (menu_1)
	{
	case 1:
		add();
		break;
	case 2:
		if (data_input_test != 0) {
		menu_picture_m();
		}
		if (data_input_test == 0) {
			printf("Nie wgrales zdjecia\n");
			system("pause");
		}
		break;
	case 3:
		if (data_input_test != 0) {
			filter_menu_m();
		}
		if (data_input_test == 0) {
			printf("Nie wgrales zdjecia\n");
			system("pause");
		}
		break;
	case 4:
		if (data_input_test != 0) {
			noise_m();
		}
		if (data_input_test == 0) {
			printf("Nie wgrales zdjecia\n");
			system("pause");
		}
		break;
	case 5:
		if (data_input_test != 0) {
			histogram_m();
		}
		if (data_input_test == 0) {
			printf("Nie wgrales zdjecia\n");
			system("pause");
		}
		break;
	case 6:
		if (data_input_test != 0) {
			menu_geometry_m();
		}
		if (data_input_test == 0) {
			printf("Nie wgrales zdjecia\n");
			system("pause");
		}
		break;
	case 7:
		if (data_input_test != 0) {
			save_m();
		}
		if (data_input_test == 0) {
			printf("Nie wgrales zdjecia\n");
			system("pause");
		}
		break;
	case 8:
		end();
		return 0;
		break;
	}
	} while ((menu_1 = getchar()) != 8);
}

 