#pragma

#include "stdio.h"
#include "conio.h"
#include "MangTamGiac.h"

void main()
{
	TAMGIAC a[MAX_TRIANGLE];
	int n;

	nhapMangTamGiac(a, n);
	xuatMangTamGiac(a, n);

	TAMGIAC max = laChuViLonNhat(a, n);
	printf("\nTam giac co chu vi lon nhat la: ");
	xuatTamGiac(max);

	printf("\nTong dien tich cac tam giac la: %.4lf", tongDienTichTamGiac(a, n));
	printf("\nSo tam giac lon hon dien tich trung binh la: %d", demTgiacLonhonDtichTbinh(a, n));

	sapGiamTheoChuVi(a, n);
	xuatMangTamGiac(a, n);
	_getch();
}