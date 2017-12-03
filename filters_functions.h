#include"structs.h"
#ifndef FILTERS_FUNCTIONS_H
#define FILTERS_FUNCTIONS_H
Filters *averagre_filter();
Filters *squere_filter();
Filters *circle_filter();
Filters *lp1_filter();
Filters *lp2_filter();
Filters *lp3_filter();
Filters *piramidal_filter();
Filters *conus_filter();
Filters *gauss1_filter();
Filters *gauss2_filter();
Filters *gauss3_filter();
Filters *gauss4_filter();
Filters *gauss5_filter();
Filters *clean_f(Filters *filter);
#endif // !filters_functions.h
