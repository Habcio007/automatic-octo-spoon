#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"structs.h"
#include"filters_data.h"
#include"filters_functions.h"
#include"filters_functions.c"


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

Filters *clean_f(Filters *filter) {
	int i;
	for (i = 0; i < filter->size; i++) {
		free(filter->type[i]);
	}
		free(filter->type);
		return filter;
}






