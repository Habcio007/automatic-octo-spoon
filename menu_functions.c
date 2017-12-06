#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"functions.h"
#include"structs.h"
#include"filters_functions.h"
#include"menu_functions.h"

void save_m() {
	save(photo[memmory.last_photo_number]);
	system("out.pgm");
}
void low_pass_filter_menu()
{
	printf("Menu:\n");
	printf("\t-Filtry:\n");
	printf("\tWybierz rodzaj filtra z listy:\n");
	printf("\t\t1-filtr usredniajacy\n");
	printf("\t\t2-filtr kwadratowy\n");
	printf("\t\t3-filtr kolowy\n");
	printf("\t\t4-Rodzina filtrow LP\n");
	printf("\t\t5-filtr piramidalny \n");
	printf("\t\t6-filtr stozkowy\n");
	printf("\t\t7-Rodzina filtrow Gaussa\n");
	printf("\t\t8-Rodzina filtrow gornoprzepustowych\n");
	printf("\t\t9-Powrot do menu glownego\n");

}
void low_pass_filter_menu_lp()
{
	printf("Menu:\n");
	printf("\t-Filtry:\n");
	printf("\t\tFiltry LP:\n");
	printf("\t\tWybierz rodzaj filtra z listy:\n");
	printf("\t\t\t1-filtr LP1\n");
	printf("\t\t\t2-filtr LP2\n");
	printf("\t\t\t3-filtr LP3\n");
	printf("\t\t\t4-Powrot do wyboru filtrow\n");
}
void low_pass_filter_menu_gauss() {
	printf("Menu:\n");
	printf("\t-Filtry dolnoprzepustowe :\n");
	printf("\t\t Filtry Gaussa:\n");
	printf("\t\tWybierz rodzaj filtra z listy:\n");
	printf("\t\t\t1-filtr Gaussa 1\n");
	printf("\t\t\t2-filtr Gaussa 2\n");
	printf("\t\t\t3-filtr Gaussa 3\n");
	printf("\t\t\t4-filtr Gaussa 4\n");
	printf("\t\t\t5-filtr Gaussa 5\n");
	printf("\t\t\t6-Powrot do wyboru filtrow\n");
}
void high_pass_filter_menu() {
	printf("Menu:\n");
	printf("\t-Filtry gornoprzepustowe:\n");
	printf("\t\tWybierz rodzaj filtra z listy:\n");
	printf("\t\t\t1-usun srednia\n");
	printf("\t\t\t2-HP1\n");
	printf("\t\t\t3-HP2\n");
	printf("\t\t\t4-HP3\n");
	printf("\t\t\t5-Powrot do wyboru filtrow\n");
}
void menu_main() {
	system("cls");
	printf("1-Dodaj obraz\n");
	printf("2-Operacje na obrazie\n");
	printf("3-Filtry\n");
	printf("4-Szum\n");
	printf("5-Histogram\n");
	printf("6-Operacje geometryczne\n");
	printf("7-Zapis\n");
	printf("8-Zakonc program\n");
}
void menu_picture() {
	system("cls");
	printf("Menu:\n");
	printf("\t-Operacje na obrazie\n");
	printf("\t\t1-Zmiana jasnosci\n");
	printf("\t\t2-Kontrast\n");
	printf("\t\t3-Progowanie\n");
	printf("\t\t4-Negatyw\n");
	printf("\t\t5-Powrot do menu glownego\n");
}
void menu_picture_m() {
	//menu_main();
	int menu_1;
	int ths_value;
	int bright_value;
	float cont_value;
	menu_picture();

	scanf("%d", &menu_1);
	
	switch(menu_1)
	{
	case 1:
		printf("Podaj wartosc zmiany jasnosci");
		scanf("%d", &bright_value);
		photo[memmory.last_photo_number] = brightness(photo[memmory.last_photo_number], bright_value);
		break;
	case 2:
		printf("Podaj wartosc zmiany kontrastu: \n");
		do{
			scanf("%f", &cont_value);
			if ( cont_value < 0) {
			printf("Zmiana kontrastu nie moze byc mnniejsze od 0, wprowadz jeszcze raz: ");
			}
		} while ((cont_value = getchar()) < 0);
		photo[memmory.last_photo_number] = contrast(photo[memmory.last_photo_number], cont_value);
		break;
	case 3:
		printf("Podaj prog progowania");
		do {
			scanf("%d", &ths_value);
			if (ths_value < 0){
			printf("Wartosc progowania nie moze byc mniejsza od 0, wprowadz jeszcze raz: ");
			}
		} while ((ths_value = getchar()) < 0);
		photo[memmory.last_photo_number] = thresholding(photo[memmory.last_photo_number], ths_value);
		break;
	case 4:
		photo[memmory.last_photo_number] = negativ(photo[memmory.last_photo_number]);
		break;
	default:
		break;
	}




}
void menu_geometry() {
	system("cls");
	printf("Menu:\n");
	printf("\t-Operacje na geometryczne\n");
	printf("\t\t1-Odbicie wzgledem OX\n");
	printf("\t\t2-Odbicie wzgledem OY\n");
	printf("\t\t3-Obrot o 90 stopni\n");
	printf("\t\t4-Obrot o 180 stopni\n");
	printf("\t\t5-Obrot o 270 stopni\n");
	printf("\t\t6-Pomniejszenie obrazu\n");
	printf("\t\t7-Powiekszenie obrazu\n");
	printf("\t\t8-Powrot do menu glownego\n");
}
void histogram_m(){
		histogram_chart(photo[memmory.last_photo_number]);
		//system("out.html");
}
void filter_menu_m() {
	int menu_1;
	int ths_value;
	int bright_value;
	float cont_value;
	Filters *filter_matrix;
	low_pass_filter_menu();
	scanf("%d", &menu_1);

	switch (menu_1)
	{
	case 1:
		filter_matrix=averagre_filter();
		photo[memmory.last_photo_number] = filter(photo[memmory.last_photo_number], filter_matrix);
		filter_matrix = clean_f(filter_matrix);
		free(filter_matrix);
		break;
	case 2:
		filter_matrix = squere_filter();
		photo[memmory.last_photo_number] = filter(photo[memmory.last_photo_number], filter_matrix);
		filter_matrix = clean_f(filter_matrix);
		free(filter_matrix);
		break;
	case 3:
		filter_matrix = circle_filter();
		photo[memmory.last_photo_number] = filter(photo[memmory.last_photo_number], filter_matrix);
		filter_matrix = clean_f(filter_matrix);
		free(filter_matrix);
		break;
	case 4:
		filter_matrix = low_pass_filter_lp();
		photo[memmory.last_photo_number] = filter(photo[memmory.last_photo_number], filter_matrix);
		filter_matrix = clean_f(filter_matrix);
		free(filter_matrix);
		break;
	case 5:
		filter_matrix = piramidal_filter();
		photo[memmory.last_photo_number] = filter(photo[memmory.last_photo_number], filter_matrix);
		filter_matrix = clean_f(filter_matrix);
		free(filter_matrix);
		break;
	case 6:
		filter_matrix = conus_filter();
		photo[memmory.last_photo_number] = filter(photo[memmory.last_photo_number], filter_matrix);
		filter_matrix = clean_f(filter_matrix);
		free(filter_matrix);
		break;
	case 7:
		filter_matrix = low_pass_filter_gauss();
		photo[memmory.last_photo_number] = filter(photo[memmory.last_photo_number], filter_matrix);
		filter_matrix = clean_f(filter_matrix);
		free(filter_matrix);
		break;
	case 8:
		filter_matrix = high_pass_filter_menu_m();
		photo[memmory.last_photo_number] = filter(photo[memmory.last_photo_number], filter_matrix);
		filter_matrix = clean_f(filter_matrix);
		free(filter_matrix);
		break;
	case 9:
		break;
	default:
		break;
	}
}
void menu_geometry_m() {
	int menu_1;
	int scal_value;
	menu_geometry();

	scanf("%d", &menu_1);

	switch (menu_1)
	{
	case 1:
		photo[memmory.last_photo_number] = miror_x(photo[memmory.last_photo_number]);
		break;
	case 2:
		photo[memmory.last_photo_number] = miror_y(photo[memmory.last_photo_number]); 
		break;
	case 3:
		photo[memmory.last_photo_number] = rotate(photo[memmory.last_photo_number]);
		break;
	case 4:
		photo[memmory.last_photo_number] = rotate_180(photo[memmory.last_photo_number]);
		break;
	case 5:
		photo[memmory.last_photo_number] = rotate(photo[memmory.last_photo_number]);
		photo[memmory.last_photo_number] = rotate_180(photo[memmory.last_photo_number]);
		break;
	case 6:
		printf("Podaj wielokrotnosc zmniejszenia");
		scanf("%d", &scal_value);
		photo[memmory.last_photo_number] = scale(photo[memmory.last_photo_number], scal_value);
		break;
	case 7:
		photo[memmory.last_photo_number] = zoom(photo[memmory.last_photo_number]);
		break;
	default:
		break;
	}
}
void noise_m()
{
	int noise_chance;
	printf("Podaj procent zapelnienia szumem [0;100]");
	do {
		scanf("%d", &noise_chance);
		if ((noise_chance < 0) || (noise_chance > 4)) {
			printf("Zla wartosc, wprowadz jeszcze raz: ");
		}
	} while ((noise_chance < 0) || (noise_chance > 4));

	photo[memmory.last_photo_number]=paper_salt_noise(photo[memmory.last_photo_number], noise_chance);

}

Filters *low_pass_filter_lp() {
	Filters *filter;
	int menu_2;
	 filter = (Filters*)malloc(sizeof(Filters));
	//system("cls");
	low_pass_filter_menu_lp();
	scanf("%d", &menu_2);
	switch (menu_2)
	{
	case 1:
		filter = lp1_filter();
		return filter;
		break;
	case 2:
		filter = lp2_filter();
		return filter;
		break;
	case 3:
		filter = lp3_filter();
		return filter;
		break;
	case 4:
		break;
	default:
		break;
	}
}
Filters *low_pass_filter_gauss() {
	Filters *filter;
	int menu_2;
	 filter = (Filters*)malloc(sizeof(Filters));
//	system("cls");
	low_pass_filter_menu_gauss();
	scanf("%d", &menu_2);
	switch (menu_2)
	{
	case 1:
		filter = gauss1_filter();
		return filter;
		break;
	case 2:
		filter = gauss2_filter();
		return filter;
		break;
	case 3:
		filter = gauss3_filter();
		return filter;
		break;
	case 4:
		filter = gauss4_filter();
		return filter;
		break;
	case 5:
		filter = gauss5_filter();
		return filter;
		break;
	default:
		break;
	}
}
Filters *low_pass_filter() {
	Filters *filter;
	filter = (Filters*)malloc(sizeof(Filters));
	low_pass_filter_menu();
	int menu_1, menu_2 = 0;
	//system("cls");
	low_pass_filter_menu();
	scanf("%d", &menu_1);
	switch (menu_1) {
	case 1:
		filter = averagre_filter();
		break;
	case 2:
		filter = squere_filter();
		break;
	case 3:
		filter = circle_filter();
		break;
	case 4:
		filter = low_pass_filter_lp();
		break;
	case 5:
		filter = piramidal_filter();
		break;
	case 6:
		filter = conus_filter();
		break;
	case 7:
		filter = low_pass_filter_gauss();
		break;
	case 8:
		break;
	default:
		break;
	}
	return filter;
}
Filters *high_pass_filter_menu_m() {
	Filters *filter;
	filter = (Filters*)malloc(sizeof(Filters));
	int menu_1, menu_2 = 0;
	//system("cls");
	high_pass_filter_menu();
	scanf("%d", &menu_1);
	switch (menu_1) {
	case 1:
		filter = us_filter();
		break;
	case 2:
		filter = hp1_filter();
		break;
	case 3:
		filter = hp2_filter();
		break;
	case 4:
		filter = hp3_filter();
		break;
	case 5:
		break;
	default:
		break;
	}
	return filter;
}
//ready
						


