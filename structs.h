#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdlib.h> 

typedef struct Picture {
	int x, y, skala;
	int **pixel;
} Picture;

typedef struct Filters {
	int **type;
	int size;
	int average;
} Filters;

typedef struct Memmory {
	int max_mem_size;
	int last_photo_number;
} Memmory;

Picture **photo;
Memmory memmory;
int data_input_test;
#endif // !1

