#ifndef MENU_FUNCTIONS_H
#define MENU_FUNCTIONS_H

int menu_1;
void low_pass_filter_menu();
void low_pass_filter_menu_lp();
void low_pass_filter_menu_gauss();
void menu_main();
void menu_picture();
void menu_picture_m();
void menu_geometry();
void histogram_m();
void filter_menu();
void menu_geometry_m();
void noise_m();

Filters *low_pass_filter_lp();
Filters *low_pass_filter_gauss();
Filters *high_pass_filter_menu_m();

#endif // !MENU_FUNCTIONS_H



