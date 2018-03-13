#pragma

#include "stdio.h"
#include "conio.h"
#include "MangDuongTron.h"

void main()
{
	DUONGTRON a[MAX_CIRCLE];
	int n;

	nhapMangDuongTron(a, n);
	xuatMangDuongTron(a, n);

	DUONGTRON max = laChuViLonNhat(a, n);
	printf("\nDuong tron co chu vi lon nhat la: ");
	xuatDuongTron(max);

	printf("\nTong dien tich cac duong tron la: %.4lf", tongDienTichDuongTron(a, n));
	printf("\nSo duong tron lon hon dien tich trung binh la: %d", demDtronLonhonDtichTbinh(a, n));

	sapGiamTheoChuVi(a, n);
	xuatMangDuongTron(a, n);
	_getch();
}
