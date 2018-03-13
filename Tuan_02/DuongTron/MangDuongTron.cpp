#pragma

#include "math.h"
#include "MangDuongTron.h"

void nhapMangDuongTron(DUONGTRON a[], int &n)
{
	do
	{
		printf("\nNhap so luong duong tron: ");
		scanf_s("%d", &n);
	} while (n<1 || n>MAX_CIRCLE);
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap duong tron a[%d]: ", i);
		nhapDuongTron(a[i]);
		printf("\n");
	}
}

void xuatMangDuongTron(DUONGTRON a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nDuong tron a[%d]: ", i);
		xuatDuongTron(a[i]);
		printf("\n");
	}
}

double chuViDuongTron(DUONGTRON c)
{
	return 2 * PI*c.r;
}

DUONGTRON laChuViLonNhat(DUONGTRON a[], int n)
{
	DUONGTRON max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (chuViDuongTron(a[i]) > chuViDuongTron(max))
		{
			max = a[i];
		}
	}
	return max;
}

double dienTichDuongTron(DUONGTRON c)
{
	return PI*c.r*c.r;
}

double tongDienTichDuongTron(DUONGTRON a[], int n)
{
	double tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += dienTichDuongTron(a[i]);
	}
	return tong;
}

int demDtronLonhonDtichTbinh(DUONGTRON a[], int n)
{
	int dem = 0;
	double tbinh = tongDienTichDuongTron(a, n) / n;

	for (int i = 0; i < n; i++)
	{
		if (dienTichDuongTron(a[i]) > tbinh)
		{
			dem++;
		}
	}
	return dem;
}

void sapGiamTheoChuVi(DUONGTRON a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (chuViDuongTron(a[i]) < chuViDuongTron(a[j]))
			{
				DUONGTRON temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
