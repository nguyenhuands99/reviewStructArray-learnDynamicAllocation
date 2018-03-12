#pragma

#include "stdio.h"
#include "conio.h"
#include "MangDiem.h"

void main()
{
	DIEM a, b;
	printf("\nNhap A: ");
	nhapDiem(a);
	printf("\nNhap B: ");
	nhapDiem(b);
	printf("\nA: ");
	xuatDiem(a);
	printf("\nB: ");
	xuatDiem(b);
	printf("\nKhoang cach AB = %.4lf", tinhKhoangCach(a, b));

	DIEM arr[MAX];
	int n;
	nhapMangDiem(arr, n);
	xuatMangDiem(arr, n);

	DIEM x;
	x.iX = 0;
	x.iY = 0;
	printf("\nDiem xa A(0,0) nhat");
	xuatDiem(timXaNhat(arr, n, x));

	printf("\nLiet ke toa do duong");
	lietKeToaDoDuong(arr, n);

	printf("\nTang dan khoang cach");
	sapXepTangKhoangCach(arr, n);
	xuatMangDiem(arr, n);

	_getch();
}
