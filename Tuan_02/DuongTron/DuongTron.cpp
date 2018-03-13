#pragma

#include "DuongTron.h"

void nhapDuongTron(DUONGTRON &c)
{
	printf("\n\tNhap toa do tam: ");
	nhapDiem(c.O);
	do
	{
		printf("\n\tNhap ban kinh R: ");
		scanf_s("%f", &c.r);
	} while (c.r <= 0);
}

void xuatDuongTron(DUONGTRON c)
{
	printf("\n\tDuong tron co tam: ");
	xuatDiem(c.O);
	printf("\n\tBan kinh: %.2f",c.r);
}