#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"structs.h"
#include"filters_functions.h"
#include"filters_data.h"
#include"menu_functions.h"
#include"filters_functions.c"
#include"menu_functions.c"

void add() {
	char adres[100];
	if (photo != NULL) {

		if (memmory.last_photo_number >= memmory.max_mem_size) {
			memmory.max_mem_size = (memmory.last_photo_number) * 2;
			photo = (Picture**)realloc(photo, (memmory.max_mem_size * sizeof(Picture)));
		}
		memmory.last_photo_number++;

	}
	if (photo == NULL) {
		memmory.max_mem_size = 1;
		memmory.last_photo_number = 0;
		photo = (Picture**)calloc(memmory.max_mem_size, sizeof(Picture));
	}
	printf("Podaj adres\n");
	//scanf("%99s", adres);
	photo[memmory.last_photo_number] = load("002.pgm");
	photo[memmory.last_photo_number] = LUT(photo[memmory.last_photo_number]);
	photo[memmory.last_photo_number] = histogram(photo[memmory.last_photo_number]);

}
//ready
void end() {
	int i;
	int j;
	if (photo == NULL) {
		return;
	}

	for (i = 0; i <= memmory.last_photo_number; i++) {
		photo[i] = clear(photo[i]);
	}
	for (i = 0; i < memmory.max_mem_size; i++) {
		free(photo[i]);
	}
	free(photo);
}
//ready
void save(Picture *pgm_save) {
	int i, j;
	FILE *file;
	char adres[100];
	printf("Podaj adres\n");
	scanf("%99s", adres);
	file = fopen(adres, "w");
	fprintf(file, "%s\n", "P2");
	fprintf(file, "%s\n", "# komentarz");
	fprintf(file, "%d %d\n", pgm_save->x, pgm_save->y);
	fprintf(file, "%d\n", pgm_save->skala);
	for (j = 0; j<pgm_save->y; j++) {
		for (i = 0; i<pgm_save->x; i++) {
			fprintf(file, "%d ", pgm_save->pixel[j][i]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
}
//ready
void histogram_chart(Picture *pgm) {

	FILE *Wsk_do_pliku;
	int i;
	int n;
	n = pgm->skala;
	Wsk_do_pliku = fopen("out.html", "w");

	fprintf(Wsk_do_pliku, "<html>\n");
	fprintf(Wsk_do_pliku, "<head>\n");
	fprintf(Wsk_do_pliku, "<script type=\"text/javascript\" src=\"https://www.google.com/jsapi\"></script>\n");
	fprintf(Wsk_do_pliku, "<script type=\"text/javascript\">\n");
	fprintf(Wsk_do_pliku, "google.load(\"visualization\", \"1\", {packages:[\"corechart\"]});\n");
	//fprintf(Wsk_do_pliku, "google.load(\"current\", \"1\", {packages:[\"bar\"]});\n");
	fprintf(Wsk_do_pliku, "google.setOnLoadCallback(drawChart);\n");
	fprintf(Wsk_do_pliku, "function drawChart() {\n");
	fprintf(Wsk_do_pliku, "var data = google.visualization.arrayToDataTable([\n");
	fprintf(Wsk_do_pliku, "['s', 'sygnal'],\n");
	//
	for (i = 0; i < n; i++) {
		fprintf(Wsk_do_pliku, "[ %d, %d],\n", pgm->histogram[0][i], pgm->histogram[1][i]);   //przekazanie danych na wykres
	}

	//

	fprintf(Wsk_do_pliku, "]);\n");

	fprintf(Wsk_do_pliku, "var options = {\n");
	fprintf(Wsk_do_pliku, "title: 'Histogram'\n");
	fprintf(Wsk_do_pliku, "};\n");
	fprintf(Wsk_do_pliku, "var chart = new google.visualization.LineChart(document.getElementById('chart_div'));\n");
	fprintf(Wsk_do_pliku, "chart.draw(data, {\n");
	fprintf(Wsk_do_pliku, "colors: ['red']\n");
	fprintf(Wsk_do_pliku, "}\n");
	fprintf(Wsk_do_pliku, ");\n");
	fprintf(Wsk_do_pliku, "}\n");
	fprintf(Wsk_do_pliku, "</script>\n");
	fprintf(Wsk_do_pliku, "</head>\n");
	fprintf(Wsk_do_pliku, "<body>\n");
	fprintf(Wsk_do_pliku, "<div id=\"chart_div\" style=\"width: 900px; height: 500px;\"></div>\n");
	fprintf(Wsk_do_pliku, "adres pliku");
	fprintf(Wsk_do_pliku, "</body>\n");
	fprintf(Wsk_do_pliku, "</html>\n");

	fclose(Wsk_do_pliku);
}
//ready
int median(int a, int b, int c, int d){

	int i;
	int *temp;
	temp = (int*)malloc(sizeof(int) * 4);
	temp[0] = a;
	temp[1] = b;
	temp[2] = c;
	temp[3] = d;
	increas_sort(temp);
	i = (temp[2] + temp[1]) / 2;
	free(temp);
	return i;
}
//ready
void swap(int*x, int*y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

}
//ready
void increas_sort(int *tab)
{
	int i, n, j, temp;
	n = 5;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (tab[j + 1] > tab[j])
			{
				swap(&tab[j + 1], &tab[j]);

			}
		}
	}
}
//ready

Filters *low_pass_filter() {
	Filters *filter;
	filter = (Filters*)malloc(sizeof(Filters));
	low_pass_filter_menu();
	int menu_1, menu_2 = 0;
		system("cls");
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
//ready
Picture *scale(Picture *pgm_in, int scal) {
	int i, j;
	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;

	pgm_out->x = pgm_in->x / scal - scal;
	pgm_out->y = pgm_in->y / scal - scal;
	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}
	int k = 0;
	int m = 0;
	for (i = 0; i<pgm_out->y; i++) {
		k = k + scal;
		for (j = 0; j<pgm_out->x; j++) {
			pgm_out->pixel[i][j] = pgm_in->pixel[k][m];
			m = m + scal;
		}
		m = 0;
	}
	return pgm_out;
}
//ready
Picture *negativ(Picture *pgm_in) {
	int i, j;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}

	for (i = 0; i<pgm_out->y; i++) {
		for (j = 0; j<pgm_out->x; j++) {
			pgm_out->pixel[i][j] = pgm_in->skala - pgm_in->pixel[i][j];
		}
	}
	return pgm_out;

}
//ready
Picture *brightness(Picture *pgm_in, int bright_value) {
	int i, j;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}
	for (i = 0; i<pgm_out->y; i++) {
		for (j = 0; j<pgm_out->x; j++) {
			pgm_out->pixel[i][j] = pgm_in->pixel[i][j] + bright_value;
			if (pgm_out->pixel[i][j] > pgm_out->skala) pgm_out->pixel[i][j] = pgm_out->skala;
		}
	}
	return pgm_out;

}
//ready
Picture *miror_y(Picture *pgm_in) {
	int i, j;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}

	for (i = 0; i<pgm_out->y; i++) {
		for (j = 0; j<pgm_out->x; j++) {
			pgm_out->pixel[i][j] = pgm_in->pixel[i][pgm_out->x - 1 - j];
		}
	}
	return pgm_out;

}
//ready
Picture *miror_x(Picture *pgm_in) {
	int i, j;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}

	for (i = 0; i<pgm_out->y; i++) {
		for (j = 0; j<pgm_out->x; j++) {
			pgm_out->pixel[i][j] = pgm_in->pixel[pgm_out->y - 1 - i][j];
		}
	}
	return pgm_out;

}
//ready
Picture *rotate(Picture *pgm_in) {
	int i, j;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->y;
	pgm_out->y = pgm_in->x;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}


	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			pgm_out->pixel[j][i] = pgm_in->pixel[i][j];
		}
	}

	return pgm_out;
}
//ready
Picture *rotate_180(Picture *pgm_in) {
	int i, j;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}
	int m = pgm_in->y-1;
	int n = pgm_in->x-1;

	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			pgm_out->pixel[i][j] = pgm_in->pixel[m-i][n-j];
		}
	}

	return pgm_out;
}
//ready
Picture *histogram(Picture *pgm_in) {
	int i, j, k;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}

	pgm_out->pixel = pgm_in->pixel;

	pgm_out->histogram = (int**)calloc(2, sizeof(int*));
	for (i = 0; i <2; i++) {
		pgm_out->histogram[i] = (int*)calloc(pgm_out->skala, sizeof(int));
	}

	for (k = 0; k < pgm_out->skala; k++) {

		for (i = 0; i < pgm_out->y; i++) {
			for (j = 0; j < pgm_out->x; j++) {
				if (k == pgm_out->pixel[i][j]) pgm_out->histogram[1][k]++;


			}
		}
		pgm_out->histogram[0][k] = k + 1;

	}
	/*
	for (j = 0; j <pgm_out->skala; j++) {
	printf("%d:%d\n", pgm_out->histogram[0][j], pgm_out->histogram[1][j]);


	}*/
	return pgm_out;
}
//ready
Picture *thresholding(Picture *pgm_in, int thresholding_value)
{
	int i, j;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}

	for (i = 0; i<pgm_out->y; i++) {
		for (j = 0; j<pgm_out->x; j++) {
			if (pgm_in->pixel[i][j] > thresholding_value) {
				pgm_out->pixel[i][j] = 1;
			}
			if (pgm_in->pixel[i][j] <= thresholding_value) {
				pgm_out->pixel[i][j] = 0;
			}
		}
	}
	pgm_out->skala = 1;
	return pgm_out;
}
//ready
Picture *paper_salt_noise(Picture *pgm_in, int noise_chance) {

	srand(time(NULL));
	int i, j, noise_number;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}

	noise_number = pgm_out->x*pgm_out->y*noise_chance / 100;

	for (i = 0; i<pgm_out->y; i++) {
		for (j = 0; j<pgm_out->x; j++) {
			pgm_out->pixel[i][j] = pgm_in->pixel[i][j];
		}
	}

	for (i = 0; i < noise_number; i++) {
		if (rand() % 2 == 0)
			pgm_out->pixel[rand() % pgm_out->y][rand() % pgm_out->x] = 0;
		else
		{
			pgm_out->pixel[rand() % pgm_out->y][rand() % pgm_out->x] = pgm_out->skala;
		}

	}

	return pgm_out;



}
//ready
Picture *filter(Picture *pgm_in, Filters *matrix_filter) {
	int i, j, k, l,m=0,n=0, a, average;
	Picture *pgm_out;

	
	pgm_out = (Picture*)malloc(sizeof(Picture));




	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}
	a = (matrix_filter->size - 1) / 2;
	pgm_out->pixel = pgm_in->pixel;



	for (i = a; i<pgm_out->y - a; i++) {
		for (j = a; j<pgm_out->x - a; j++) {
			average = 0;
			m = 0;
			for (k = -a; k <= a; k++) {
				n = 0;
				for (l = -a; l <= a; l++) {
					average = (pgm_in->pixel[i + k][j + l] ) * (matrix_filter->type[m][n]) + average;
					n++;
				}
				m++;
			}
			pgm_out->pixel[i][j] = average / matrix_filter->average;
		}
	}

	return pgm_out;
}
//ready
Picture *load(char *nazwa) {

	int i, j;
	Picture *pgm_out;
	char bufor[100];
	FILE *file;
	
	file = fopen(nazwa, "r");

	if (file == NULL) {								// zbedne
		perror("Nie udalo sie otworzyc pliku ");
		system("pause");
		return ;
	}
	
	fgets(bufor, 100, file); //pominiecie "P2"
	fgets(bufor, 100, file); //pominiecie "P2"
	pgm_out = (Picture*)malloc(sizeof(Picture));

	fscanf(file, "%d%d%d", &pgm_out->x, &pgm_out->y, &pgm_out->skala);
	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));


	for (i = 0; i<pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}
	for (i = 0; i<pgm_out->y; i++) {
		for (j = 0; j<pgm_out->x; j++) {
			fscanf(file, "%d", &pgm_out->pixel[i][j]);
		}
	}
	fclose(file); 
	puts("Pomyslnie otwarto plik");
	system("pause");
	return pgm_out;
}
//ready
Picture *contrast(Picture *pgm_in, float con_value) {
	int i, j, k;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->LUT = (int*)calloc(pgm_out->skala+1, sizeof(int));
	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}

	for (i = 1; i <= pgm_out->skala; i++) {
		pgm_out->LUT[i] = con_value*(i - pgm_out->skala / 2) +  pgm_out->skala / 2;
		if (pgm_out->LUT[i] < 0)pgm_out->LUT[i] = 0;
		if (pgm_out->LUT[i] > pgm_out->skala)pgm_out->LUT[i] = pgm_out->skala;
	}

	for (i = 0; i<pgm_out->y; i++) {
		for (j = 0; j < pgm_out->x; j++) {
			for (k = 1; k <= pgm_out->skala; k++){
				if (pgm_in->pixel[i][j] == k)
					pgm_out->pixel[i][j] = pgm_out->LUT[k];
			}
		}
	}
	return pgm_out; 
}
//ready
Picture *zoom(Picture *pgm_in) {
	int i, j;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x * 2;
	pgm_out->y = pgm_in->y * 2;

	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}
	int a = 0, b = 0;
	for (i = 0; i < pgm_out->y; i++) {
		for (j = 0; j < pgm_out->x; j++) {
			if ((i % 2 == 0) && (j % 2 == 0)) {
				pgm_out->pixel[i][j] = pgm_in->pixel[a][b];
				b++;
			}
			if ((i % 2 == 0) && (j % 2 != 0)) pgm_out->pixel[i][j] = -1;
			if ((i % 2 != 0) && (j % 2 == 0)) pgm_out->pixel[i][j] = -2;
			if ((i % 2 != 0) && (j % 2 != 0)) pgm_out->pixel[i][j] = -3;
		}
		
		if (i % 2 == 0)		a++;
		b = 0;
	}
	
	
	for (i = 1; i < pgm_out->y - 1; i++) {
		for (j = 1; j <pgm_out->x - 1; j++) {
			if (pgm_out->pixel[i][j] == -3) {
				pgm_out->pixel[i][j] = median(pgm_out->pixel[i - 1][j - 1], pgm_out->pixel[i - 1][j + 1], pgm_out->pixel[i + 1][j - 1], pgm_out->pixel[i + 1][j + 1]);
			}
		}
	}
	for (i = 1; i < pgm_out->y - 1; i++) {
		for (j = 1; j <pgm_out->x - 1; j++) {
			if (pgm_out->pixel[i][j] == -2) {
				a = 0.5*(pgm_out->pixel[i - 1][j]);
				b = 0.5*(pgm_out->pixel[i + 1][j]);
				pgm_out->pixel[i][j] = median(a, pgm_out->pixel[i][j - 1], b, pgm_out->pixel[i][j + 1]);
			}
		}
	}
	for (i = 1; i < pgm_out->y - 1; i++) {
		for (j = 1; j <pgm_out->x - 1; j++) {
			if (pgm_out->pixel[i][j] == -1) {
				pgm_out->pixel[i][j] = median(pgm_out->pixel[i - 1][j], 0.5*pgm_out->pixel[i][j + 1], pgm_out->pixel[i + 1][j], 0.5*pgm_out->pixel[i][j + 1]);
			}
		}
	}

}
//ready
Picture *clear(Picture *pgm_in) {
	int i, j;
	for (i = 0; i<pgm_in->y; i++) {
		free(pgm_in->pixel[i]);
	}
	free(pgm_in->pixel);
	for (i = 0; i<2; i++) {
		free(pgm_in->histogram[i]);
	}
	free(pgm_in->LUT);
	free(pgm_in->histogram);
	return pgm_in;
}
//ready
Picture *LUT(Picture *pgm_in) {
	Picture *pgm_out;
	int i;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = pgm_in->skala;
	pgm_out->x = pgm_in->x;
	pgm_out->y = pgm_in->y;

	pgm_out->LUT = (int*)calloc(pgm_out->skala + 1, sizeof(int));
	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}

	for (i = 1; i <= pgm_out->skala; i++) {
		pgm_out->LUT[i] = i;
	}
	return pgm_out;
}
//ready
