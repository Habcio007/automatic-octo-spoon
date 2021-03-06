#include<stdio.h>
#include<stdlib.h>
#include"structs.h"
#include"filters_functions.h"

Filters *matrix_filter;

int AVERAGE_SIZE = 3;
int AVERAGE[9] = { 1, 1, 1,
1, 1, 1,
1, 1, 1 };

int SQUARE_SIZE = 5;
int SQUARE[25] = { 1, 1, 1, 1, 1,
1, 1, 1, 1, 1,
1, 1, 1, 1, 1,
1, 1, 1, 1, 1,
1, 1, 1, 1, 1 };

int CIRCLE_SIZE = 5;
int CIRCLE[25] = { 0, 1, 1, 1, 0,
1, 1, 1, 1, 1,
1, 1, 1, 1, 1,
1, 1, 1, 1, 1,
0, 1, 1, 1, 0 };

int LP1_SIZE = 3;
int LP1[9] = { 1, 1, 1,
1, 2, 1,
1, 1, 1 };

int LP2_SIZE = 3;
int LP2[9] = { 1, 1, 1,
1, 4, 1,
1, 1, 1 };

int LP3_SIZE = 3;
int LP3[9] = { 1, 1, 1,
1, 12,1,
1, 1, 1 };

int PIRAMIDAL_SIZE = 5;
int PIRAMIDAL[25] = { 1, 2, 3, 2, 1,
2, 4, 6, 4, 2,
3, 6, 9, 6, 3,
2, 4, 6, 4, 2,
1, 2, 3, 2, 1 };

int CONUS_SIZE = 5;
int CONUS[25] = { 0, 0, 1, 0, 0,
0, 2, 2, 2, 0,
1, 2, 5, 2, 1,
0, 2, 2, 2, 0,
0, 0, 1, 0, 0 };

int GAUSS1_SIZE = 3;
int GAUSS1[9] = { 1, 2, 1,
2, 4, 2,
1, 2, 1 };

int GAUSS2_SIZE = 5;
int GAUSS2[25] = { 1, 1, 2, 1, 1,
1, 2, 4, 2, 1,
2, 4, 8, 4, 2,
1, 2, 4, 2, 1,
1, 1, 2, 1, 1 };

int GAUSS3_SIZE = 5;
int GAUSS3[25] = { 0, 1, 2, 1, 0,
1, 4, 8, 4, 1,
2, 8, 16,8, 2,
1, 4, 8, 4, 1,
0, 1, 2, 1, 0 };

int GAUSS4_SIZE = 5;
int GAUSS4[25] = { 1, 4, 7, 4, 1,
4,16,26,16, 4,
7,26,41,26, 7,
4,26,16,26, 4,
1, 4, 7, 4, 1 };

int GAUSS5_SIZE = 7;
int GAUSS5[49] = { 1, 1, 2, 2, 2, 1, 1,
1, 2, 2, 4, 2, 2, 1,
2, 2, 4, 8, 4, 2, 2,
2, 4, 8,16, 8, 4, 2,
2, 2, 4, 8, 4, 2, 2,
1, 2, 2, 4, 2, 2, 1,
1, 1, 2, 2, 2, 1, 1 };

int USUN_SREDNIA_SIZE = 3;
int USUN_SREDNIA[9] = { -1, -1, -1,
-1,  9, -1,
-1, -1, -1 };

int HP1_SIZE = 3;
int HP1[9] = { 0, -1,  0,
-1,  5, -1,
0, -1,  0 };

int HP2_SIZE = 3;
int HP2[9] = { 1, -2,  1,
-2,  5, -2,
1, -2,  1 };

int HP3_SIZE = 3;
int HP3[9] = { 0, -1,  0,
-1,  20, -1,
0, -1,  0 };

int HORIZONTAL_SIZE = 3;
int POZIOMY[9] = { 0,  0,  0,
-1,  1,  0,
0,  0,  0 };

int VERTICAL_SIZE = 3;
int PIONOWY[9] = { 0, -1,  0,
0,  1,  0,
0,  0,  0 };

int GRADIENT_E_SIZE = 3;
int GRADIENT_E[9] = { -1,  1,  1,
-1, -2,  1,
-1,  1,  1 };

int GRADIENT_SE_SIZE = 3;
int GRADIENT_SE[9] = { -1, -1,  1,
-1, -2,  1,
1,  1,  1 };

int GRADIENT_S_SIZE = 3;
int GRADIENT_S[9] = { -1, -1, -1,
1, -2,  1,
1,  1,  1 };

int GRADIENT_SW_SIZE = 3;
int GRADIENT_SW[9] = { 1, -1, -1,
1, -2, -1,
1,  1,  1 };

int GRADIENT_W_SIZE = 3;
int GRADIENT_W[9] = { 1,  1, -1,
1, -2, -1,
1,  1, -1 };

int GRADIENT_NW_SIZE = 3;
int GRADIENT_NW[9] = { 1,  1,  1,
1, -2, -1,
1, -1, -1 };

int GRADIENT_N_SIZE = 3;
int GRADIENT_N[9] = { 1,  1,  1,
1, -2,  1,
-1, -1, -1 };

int GRADIENT_NE_SIZE = 3;
int GRADIENT_NE[9] = { 1,  1,  1,
-1, -2,  1,
-1, -1,  1 };

int UWYPUKLAJACY_E_SIZE = 3;
int UWYPUKLAJACY_E[9] = { -1,  0,  1,
-1,  1,  1,
-1,  0,  1 };

int UWYPUKLAJACY_SE_SIZE = 3;
int UWYPUKLAJACY_SE[9] = { -1, -1,  0,
-1,  1,  1,
0,  1,  1 };

int UWYPUKLAJACY_S_SIZE = 3;
int UWYPUKLAJACY_S[9] = { -1, -1, -1,
0,  1,  0,
1,  1,  1 };

int UWYPUKLAJACY_SW_SIZE = 3;
int UWYPUKLAJACY_SW[9] = { 0, -1, -1,
1,  1, -1,
1,  1,  0 };

int UWYPUKLAJACY_W_SIZE = 3;
int UWYPUKLAJACY_W[9] = { 1,  0, -1,
1,  1, -1,
1,  0, -1 };

int UWYPUKLAJACY_NW_SIZE = 3;
int UWYPUKLAJACY_NW[9] = { 1,  1,  0,
1,  1, -1,
0, -1, -1 };

int UWYPUKLAJACY_N_SIZE = 3;
int UWYPUKLAJACY_N[9] = { 1,  1,  1,
0,  1,  0,
-1, -1, -1 };

int UWYPUKLAJACY_NE_SIZE = 3;
int UWYPUKLAJACY_NE[9] = { 0,  1,  1,
-1,  1,  1,
-1, -1,  0 };

int LAPL1_SIZE = 3;
int LAPL1[9] = { 0, -1,  0,
-1,  4, -1,
0, -1,  0 };

int LAPL2_SIZE = 3;
int LAPL2[9] = { -1, -1, -1,
-1,  8, -1,
-1, -1, -1 };

int LAPL3_SIZE = 3;
int LAPL3[9] = { 1, -2,  1,
-2,  4, -2,
1, -2,  1 };

int LAPL_SKOSNY_SIZE = 3;
int LAPL_SKOSNY[9] = { -1,  0, -1,
0,  4,  0,
-1,  0, -1 };

int LAPL_PIONOWY_SIZE = 3;
int LAPL_PIONOWY[9] = { 0, -1,  0,
0,  2,  0,
0, -1,  0 };

int LAPL_POZIOMY_SIZE = 3;
int LAPL_POZIOMY[9] = { 0,  0,  0,
-1,  2, -1,
0,  0,  0 };

int SOBEL_POZIOMY_SIZE = 3;
int SOBEL_POZIOMY[9] = { 1,  2,  1,
0,  0,  0,
-1, -2, -1 };

int SOBEL_PIONOWY_SIZE = 3;
int SOBEL_PIONOWY[9] = { 1,  0, -1,
2,  0, -2,
1,  0, -1 };

int PREWITT_POZIOMY_SIZE = 3;
int PREWITT_POZIOMY[9] = { -1, -1, -1,
0,  0,  0,
1,  1,  1 };

int PREWITT_PIONOWY_SIZE = 3;
int PREWITT_PIONOWY[9] = { 1,  0, -1,
1,  0, -1,
1,  0, -1 };




Filters *averagre_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = AVERAGE_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = AVERAGE[k];
			filter->average = AVERAGE[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *squere_filter(){
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = SQUARE_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = SQUARE[k];
			filter->average = SQUARE[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *circle_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = CIRCLE_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = CIRCLE[k];
			filter->average = CIRCLE[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *lp1_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = LP1_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = LP1[k];
			filter->average = LP1[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *lp2_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = LP2_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = LP2[k];
			filter->average = LP2[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *lp3_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = LP3_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = LP3[k];
			filter->average = LP3[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *piramidal_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = PIRAMIDAL_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = PIRAMIDAL[k];
			filter->average = PIRAMIDAL[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *conus_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = CONUS_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = CONUS[k];
			filter->average = CONUS[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *gauss1_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = GAUSS1_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = GAUSS1[k];
			filter->average = GAUSS1[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *gauss2_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = GAUSS2_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = GAUSS2[k];
			filter->average = GAUSS2[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *gauss3_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = GAUSS3_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = GAUSS3[k];
			filter->average = GAUSS3[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *gauss4_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = GAUSS4_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = GAUSS4[k];
			filter->average = GAUSS4[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *gauss5_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = GAUSS5_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = GAUSS5[k];
			filter->average = GAUSS5[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *hp1_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = HP1_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = HP1[k];
			filter->average = HP1[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *hp2_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = HP2_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = HP2[k];
			filter->average = HP2[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *hp3_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = HP3_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = HP3[k];
			filter->average = HP3[k] + filter->average;
			k++;
		}
	}
	return filter;
}

Filters *us_filter() {
	Filters *filter;
	int  i, j, k = 0;
	filter = (Filters*)malloc(sizeof(Filters));
	filter->average = 0;
	filter->size = USUN_SREDNIA_SIZE;
	filter->type = (int**)calloc(filter->size, sizeof(int*));
	for (i = 0; i < filter->size; i++) {
		filter->type[i] = (int*)calloc(filter->size, sizeof(int));
	}

	for (i = 0; i < filter->size; i++) {
		for (j = 0; j < filter->size; j++) {
			filter->type[i][j] = USUN_SREDNIA[k];
			filter->average = USUN_SREDNIA[k] + filter->average;
			k++;
		}
	}
	return filter;
}


Filters *clean_f(Filters *filter) {
	int i;
	for (i = 0; i < filter->size; i++) {
		free(filter->type[i]);
	}
		free(filter->type);
		return filter;
}







