#pragma
#include "stdio.h"
#include "PhanAn.h"

void taoMenu(FOOD *list[], MENU &table, int index[], int size_index)
{
	table.size = size_index; // phần ăn này sẽ có bao nhiêu món

	for (int i = 0; i < table.size; i++)
	{
		table.dish[i].foodname = list[index[i]]->foodname;
		table.dish[i].price = list[index[i]]->price;
	}

}
void inMenu(MENU table)
{
	for (int i = 0; i < table.size; i++)
	{
		printf("\n%s: %d JPY",table.dish[i].foodname,table.dish[i].price);
	}
}
int tongTien(MENU table)
{
	int s = 0;
	for (int i = 0; i < table.size; i++)
	{
		s += table.dish[i].price;
	}	
	return s;
}
void inTien(MENU table)
{
	printf("\nTong gia tri mon: %d JPY", tongTien(table));
	printf("\nGia tri phan an: %d JPY", (int)(tongTien(table)*KHUYENMAI));
	
}
void inThongTin(FOOD *list[], MENU table, int index[], int size_index)
{
	printf("\n\n********* PHAN AN %c *********", table.id + ('A' - '1'));
	taoMenu(list, table, index,size_index);
	inMenu(table);
	printf("\n-----------------------------");
	inTien(table);
}

