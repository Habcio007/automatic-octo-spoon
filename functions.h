#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"structs.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void add();
void end();
void save(Picture *pgm_save);
void histogram_chart(Picture *pgm);
int median(int, int, int, int);
void swap(int*, int*);
void increas_sort(int *);


Filters *low_pass_filter();
Picture *scale(Picture *pgm_in, int scal);
Picture *negativ(Picture *pgm_in);
Picture *brightness(Picture *pgm_in, int bright_value);
Picture *miror_y(Picture *pgm_in);
Picture *miror_x(Picture *pgm_in);
Picture *rotate(Picture *pgm_in);
Picture *rotate_180(Picture *pgm_in);
Picture *histogram(Picture *pgm_in);
Picture *thresholding(Picture *pgm_in, int thresholding_value);
Picture *paper_salt_noise(Picture *pgm_in, int noise_chance);
Picture *filter(Picture *pgm_in, Filters *matrix_filter);
Picture *load(char *nazwa);
Picture *contrast(Picture *pgm_in, float con_value);
Picture *zoom(Picture *pgm_in);
Picture *clear(Picture *pgm_in);
Picture *LUT(Picture *pgm_in);

#endif // !FUNCTIONS_H
