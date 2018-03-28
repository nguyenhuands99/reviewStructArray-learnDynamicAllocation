#pragma
#include "stdio.h"
#include "MonAn.h"
#define KHUYENMAI 0.9

struct MENU
{
	FOOD dish[4];
	int size;
	char id;
};

void taoMenu(FOOD *list[], MENU &table, int index[], int size_index);
void inMenu(MENU table);
int tongTien(MENU table);
void inTien(MENU table);
void inThongTin(FOOD *list[], MENU table, int index[], int size_index);