#pragma

#include "stdio.h"
#include "conio.h"
#include "PhanAn.h"

char *name[6] = { "Burger","Cheese burger","Chicken burger","Drink","Potato","Ice cream" }; //Tên các món
int price[] = { 130,150,200,130,120,160 };//Giá tiền các món theo đúng thứ tự
int index_phanA[] = { 0,3,4 }; //Chỉ số của món ăn có trong phần A
int index_phanB[] = { 1,3,4 };
int index_phanC[] = { 2,3,4 };
int index_phanD[] = { 2,3,4,5 };

void main()
{
	FOOD *list[sizeof(name) / sizeof(*name)]; //sizeof(name)/sizeof(*name): kích thước mảng chứa các món ăn
	MENU table;

	for (int i = 0; i < 6; i++)
	{
		taoMon(name[i], price[i], list);
	}

	printf("Nhap phan an: ");
	scanf_s("%c", &table.id);
	table.id = getchar();
	switch (table.id)
	{
	case '1': {
		inThongTin(list, table, index_phanA, sizeof(index_phanA) / sizeof(*index_phanA));
	}; break;
	case '2': {
		inThongTin(list, table, index_phanB, sizeof(index_phanB) / sizeof(*index_phanB));
	}; break;
	case '3': {
		inThongTin(list, table, index_phanC, sizeof(index_phanC) / sizeof(*index_phanC));
	}; break;
	case '4': {
		inThongTin(list, table, index_phanD, sizeof(index_phanD) / sizeof(*index_phanD));
	}; break;
	}
	_getch();
}