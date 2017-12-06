#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"structs.h"
#include"functions.h"

void add() {
	char adres[100];
	if (photo != NULL) {
		memmory.last_photo_number++;
		if (memmory.last_photo_number >= memmory.max_mem_size) {
			memmory.max_mem_size = (memmory.last_photo_number) * 2;
			photo = (Picture**)realloc(photo, (memmory.max_mem_size * sizeof(Picture*)));
		}
		

	}
	else  {
		memmory.max_mem_size = 1;
		memmory.last_photo_number = 0;
		photo = (Picture**)malloc(memmory.max_mem_size * sizeof(Picture*));
	}
	printf("Podaj adres\n");
	scanf("%99s", adres);

	photo[memmory.last_photo_number] = load(adres,&data_input_test);
	if (data_input_test == 0) {
		printf("s");
		memmory.last_photo_number--;
	}

}
//rwml
void end() {
	int i;
	int j;
	if (photo == NULL) {
		return;
	}

	for (i = 0; i <= memmory.last_photo_number; i++) {
		photo[i] = clear(photo[i]);
	}
	for (i = 0; i <= memmory.last_photo_number; i++) {
		free(photo[i]);
	}
	free(photo);
}
//rwml
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
//rwml
void histogram_chart(Picture *pgm) {
	int **tab;
	FILE *Wsk_do_pliku;
	int i,j;
	int n;
	int k;

	tab = (int**)calloc(2, sizeof(int*));
	for (i = 0; i <2; i++) {
		tab[i] = (int*)calloc(pgm->skala, sizeof(int));
	}

	for (k = 0; k < pgm->skala; k++) {

		for (i = 0; i < pgm->y; i++) {
			for (j = 0; j < pgm->x; j++) {
				if (k == pgm->pixel[i][j]) tab[1][k]++;


			}
		}
		tab[0][k] = k + 1;

	}

	
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
		fprintf(Wsk_do_pliku, "[ %d, %d],\n", tab[0][i], tab[1][i]);   //przekazanie danych na wykres
	}

	//

	fprintf(Wsk_do_pliku, "]);\n");

	fprintf(Wsk_do_pliku, "var options = {\n");
	fprintf(Wsk_do_pliku, "title: 'Histogram'\n");
	fprintf(Wsk_do_pliku, "};\n");
	fprintf(Wsk_do_pliku, "var chart = new google.visualization.ColumnChart(document.getElementById('chart_div'));\n");
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
	for (i = 0; i<2; i++) {
		free(tab[i]);
	}
	free(tab);
}
//rwml
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
//rwml
void swap(int*x, int*y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

}
//rwml
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
//rwml
Picture *scale(Picture *pgm_in, int scal) {
	int i, j;
	int **temp;
	int x, y;
	y = pgm_in->y / scal - 1;
	x = pgm_in->x / scal - 1;
	temp = (int**)calloc(y, sizeof(int*));
	for (i = 0; i < y; i++) {
		temp[i] = (int*)calloc(x, sizeof(int));;
	}


	int k = 0;
	int m = 0;
	for (i = 0; i<y; i++) {
		k = k + scal;
		for (j = 0; j<x; j++) {
			temp[i][j] = pgm_in->pixel[k][m];
			m = m + scal;
		}
		m = 0;
	}

	for (i = 0; i<pgm_in->y; i++) {
		free(pgm_in->pixel[i]);
	}
	free(pgm_in->pixel);
	pgm_in->pixel = (int**)malloc(y * sizeof(int*));
	for (i = 0; i < y; i++) {
		pgm_in->pixel[i] = (int*)malloc(x * sizeof(int));
	}
	pgm_in->x = x;
	pgm_in->y = y;


	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			pgm_in->pixel[i][j] = temp[i][j];
		}
	}
	for (i = 0; i<y; i++) {
		free(temp[i]);
	}
	free(temp);
	return pgm_in;
}
//rwml
Picture *negativ(Picture *pgm_in) {
	int i, j;

	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			pgm_in->pixel[i][j] = pgm_in->skala - pgm_in->pixel[i][j];
		}
	}
	return pgm_in;

}
//rwml
Picture *test() {
	int i, j;

	Picture *pgm_out;
	pgm_out = (Picture*)malloc(sizeof(Picture));

	pgm_out->skala = 100;
	pgm_out->x = 100;
	pgm_out->y = 100;
	pgm_out->pixel = (int**)calloc(pgm_out->y, sizeof(int*));
	for (i = 0; i < pgm_out->y; i++) {
		pgm_out->pixel[i] = (int*)calloc(pgm_out->x, sizeof(int));;
	}

	for (i = 0; i<pgm_out->y; i++) {
		for (j = 0; j<pgm_out->x; j++) {
			pgm_out->pixel[i][j] = i + j;
		}
	}
	return pgm_out;

}
//rwml
Picture *brightness(Picture *pgm_in, int bright_value) {
	int i, j;

	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			pgm_in->pixel[i][j] = pgm_in->pixel[i][j] + bright_value;
			if (pgm_in->pixel[i][j] > pgm_in->skala) pgm_in->pixel[i][j] = pgm_in->skala;
			if (pgm_in->pixel[i][j] < 0) pgm_in->pixel[i][j] = 0;
		}
	}
	return pgm_in;

}
//rwml
Picture *miror_y(Picture *pgm_in) {
	int i, j;
	int **temp;
	temp = (int**)calloc(pgm_in->y, sizeof(int*));
	for (i = 0; i < pgm_in->y; i++) {
		temp[i] = (int*)calloc(pgm_in->x, sizeof(int));;
	}

	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			temp[i][j] = pgm_in->pixel[i][pgm_in->x - 1 - j];
		}
	}
	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			pgm_in->pixel[i][j] = temp[i][j];
		}
	}
	for (i = 0; i < pgm_in->y; i++) {
		free(temp[i]);
	}
	free(temp);
	return pgm_in;

}
//rwml
Picture *miror_x(Picture *pgm_in) {
	int i, j;

	int **temp;
	temp = (int**)calloc(pgm_in->y, sizeof(int*));
	for (i = 0; i < pgm_in->y; i++) {

		temp[i] = (int*)calloc(pgm_in->x, sizeof(int));;
	}
	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			temp[i][j] = pgm_in->pixel[pgm_in->y - 1 - i][j];
		}
	}
	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			pgm_in->pixel[i][j] = temp[i][j];
		}
	}
	for (i = 0; i < pgm_in->y; i++) {
		free(temp[i]);
	}
	free(temp);
	return pgm_in;

}
//rwml
Picture *rotate(Picture *pgm_in) {
	int i, j;

	int **temp;
	int x, y;
	x = pgm_in->y;
	y = pgm_in->x;

	temp = (int**)calloc(y, sizeof(int*));
	for (i = 0; i < y; i++) {
		temp[i] = (int*)calloc(x, sizeof(int));;
	}


	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			temp[j][i] = pgm_in->pixel[i][j];
		}
	}
	for (i = 0; i<pgm_in->y; i++) {
		free(pgm_in->pixel[i]);
	}
	free(pgm_in->pixel);
	pgm_in->pixel = (int**)malloc(y * sizeof(int*));
	for (i = 0; i < y; i++) {
		pgm_in->pixel[i] = (int*)malloc(x * sizeof(int));
	}
	pgm_in->x = x;
	pgm_in->y = y;


	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			pgm_in->pixel[i][j] = temp[i][j];
		}
	}
	for (i = 0; i<y; i++) {
		free(temp[i]);
	}
	free(temp);
	return pgm_in;
}
//rwml
Picture *rotate_180(Picture *pgm_in) {
	int i, j;
	int **temp;
	int x, y;
	y = pgm_in->y;
	x = pgm_in->x;
	temp = (int**)calloc(y, sizeof(int*));
	for (i = 0; i < y; i++) {
		temp[i] = (int*)calloc(x, sizeof(int));;
	}
	int m = pgm_in->y - 1;
	int n = pgm_in->x - 1;
	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			temp[i][j] = pgm_in->pixel[m - i][n - j];
		}
	}
	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			pgm_in->pixel[i][j] = temp[i][j];
		}
	}
	for (i = 0; i<y; i++) {
		free(temp[i]);
	}
	free(temp);
	return pgm_in;
}
//rwml
Picture *thresholding(Picture *pgm_in, int thresholding_value)
{
	int i, j;
	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			if (pgm_in->pixel[i][j] > thresholding_value) {
				pgm_in->pixel[i][j] = 1;
			}
			else {
				pgm_in->pixel[i][j] = 0;
			}
		}
	}
	pgm_in->skala = 1;
	return pgm_in;
}
//rwml
Picture *paper_salt_noise(Picture *pgm_in, int noise_chance) {
	srand(time(NULL));
	int i, j, noise_number;
	noise_number = pgm_in->x*pgm_in->y*noise_chance / 100;
	for (i = 0; i < noise_number; i++) {
		if (rand() % 2 == 0)
			pgm_in->pixel[rand() % pgm_in->y][rand() % pgm_in->x] = 0;
		else
		{
			pgm_in->pixel[rand() % pgm_in->y][rand() % pgm_in->x] = pgm_in->skala;
		}
	}
	return pgm_in;
}
//rwml
Picture *filter(Picture *pgm_in, Filters *matrix_filter) {
	int i, j, k, l,m=0,n=0, a, average;
	int **temp;
	int x, y;
	y = pgm_in->y;
	x = pgm_in->x;
	temp = (int**)calloc(y, sizeof(int*));
	for (i = 0; i < y; i++) {
		temp[i] = (int*)calloc(x, sizeof(int));;
	}

	a = (matrix_filter->size - 1) / 2;


	for (i = a; i<pgm_in->y - a; i++) {
		for (j = a; j<pgm_in->x - a; j++) {
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
			temp[i][j] = average / matrix_filter->average;
		}
	}
	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j<pgm_in->x; j++) {
			pgm_in->pixel[i][j] = temp[i][j];
		}
	}
	for (i = 0; i<y; i++) {
		free(temp[i]);
	}
	free(temp);
	return pgm_in;
}
//rwml
Picture *load(char *nazwa, int *data_test) {

	int i, j;
	Picture *pgm_out;
	char bufor[100];
	FILE *file;
	
	file = fopen(nazwa, "r");

	if (file == NULL) {								// zbedne
		perror("Nie udalo sie otworzyc pliku ");
		system("pause");
		*data_test = 0;
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
	*data_test = 1;
	return pgm_out;
}
//rwml
Picture *contrast(Picture *pgm_in, float con_value) {
	int i, j, k;
	int *temp;
	temp = (int*)calloc(pgm_in->skala + 1, sizeof(int));

	for (i = 1; i <= pgm_in->skala; i++) {
		temp[i] = con_value*(i - pgm_in->skala / 2) + pgm_in->skala / 2;
		if (temp[i] < 0)temp[i] = 0;
		if (temp[i] > pgm_in->skala)temp[i] = pgm_in->skala;
	}

	for (i = 0; i<pgm_in->y; i++) {
		for (j = 0; j < pgm_in->x; j++) {
			for (k = 1; k <= pgm_in->skala; k++) {
				if (pgm_in->pixel[i][j] == k)
					pgm_in->pixel[i][j] = temp[k];
			}
		}
	}
	free(temp);
	return pgm_in;
}
//rwml
Picture *zoom(Picture *pgm_in) {

	int i, j;

	int **temp;

	int x, y;

	y = pgm_in->y * 2;

	x = pgm_in->x * 2;

	temp = (int**)malloc(y * sizeof(int*));

	for (i = 0; i < y; i++) {

		temp[i] = (int*)malloc(x * sizeof(int));;

	}

	int a = 0, b = 0;

	for (i = 0; i < y; i++) {

		for (j = 0; j < x; j++) {

			if ((i % 2 == 0) && (j % 2 == 0)) {

				temp[i][j] = pgm_in->pixel[a][b];

				b++;

			}

			if ((i % 2 == 0) && (j % 2 != 0)) 	temp[i][j] = -1;

			if ((i % 2 != 0) && (j % 2 == 0)) 	temp[i][j] = -2;

			if ((i % 2 != 0) && (j % 2 != 0)) 	temp[i][j] = -3;

		}



		if (i % 2 == 0)		a++;

		b = 0;

	}
	for (i = 1; i <y - 1; i++) {

		for (j = 1; j < x - 1; j++) {

			if (temp[i][j] == -3) {

				temp[i][j] = median(temp[i - 1][j - 1], temp[i - 1][j + 1], temp[i + 1][j - 1], temp[i + 1][j + 1]);

			}

		}

	}

	for (i = 1; i <y - 1; i++) {

		for (j = 1; j <x - 1; j++) {

			if (temp[i][j] == -2) {

				a = 0.5*(temp[i - 1][j]);

				b = 0.5*(temp[i + 1][j]);

				temp[i][j] = median(a, temp[i][j - 1], b, temp[i][j + 1]);

			}

		}

	}

	for (i = 1; i <y - 1; i++) {

		for (j = 1; j <x - 1; j++) {

			if (temp[i][j] == -1) {

				temp[i][j] = median(temp[i - 1][j], 0.5*temp[i][j + 1], temp[i + 1][j], 0.5*temp[i][j + 1]);

			}

		}

	}

	for (i = 0; i<pgm_in->y; i++) {

		free(pgm_in->pixel[i]);

	}

	free(pgm_in->pixel);

	pgm_in->pixel = (int**)malloc(y * sizeof(int*));

	for (i = 0; i < y; i++) {

		pgm_in->pixel[i] = (int*)malloc(x * sizeof(int));

	}

	pgm_in->x = x;

	pgm_in->y = y;





	for (i = 0; i<pgm_in->y; i++) {

		for (j = 0; j<pgm_in->x; j++) {

			pgm_in->pixel[i][j] = temp[i][j];

		}

	}

	for (i = 0; i<y; i++) {

		free(temp[i]);

	}

	free(temp);

	return pgm_in;

}
//rwml
Picture *clear(Picture *pgm_in) {
	int i, j;

	for (i = 0; i<pgm_in->y; i++) {
		free(pgm_in->pixel[i]);
	}
	free(pgm_in->pixel);
	return pgm_in;
}
//rwml


