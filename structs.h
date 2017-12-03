#ifndef STRUCTS_H
#define STRUCTS_H
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>  

typedef struct Picture {
	int x, y, skala;
	int **pixel;
	int **histogram;
	int *LUT;
}Picture;

typedef struct Filters {
	int **type;
	int size;
	int average;
}Filters;

typedef struct Memmory {
	int max_mem_size;
	int last_photo_number;
}Memmory;

#endif // !1

