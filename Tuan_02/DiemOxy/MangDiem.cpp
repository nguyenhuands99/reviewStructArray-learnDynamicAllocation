#pragma

#include "MangDiem.h"

void nhapMangDiem(DIEM a[], int &n)
{
	do
	{
		printf("\nNhap so luong phan tu: ");
		scanf_s("%d", &n);
		if (n < 1)
		{
			printf("\nNhap sai. Nhap lai");
		}
		else
		{
			break;
		}
	} while (n<1 || n>MAX);
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap a[%d]", i);
		nhapDiem(a[i]);
	}
}

void xuatMangDiem(DIEM a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		xuatDiem(a[i]);
	}
}

void hoanViDiem(DIEM &a, DIEM &b)
{
	DIEM temp;
	temp.iX = a.iX;
	temp.iY = a.iY;
	a.iX = b.iX;
	a.iY = b.iY;
	b.iX = temp.iX;
	b.iY = temp.iY;
}


DIEM timXaNhat(DIEM a[], int n, DIEM x)
{
	DIEM kq = a[0];
	double kc = tinhKhoangCach(a[0], x);

	for (int i = 1; i < n; i++)
	{
		double kc2 = tinhKhoangCach(a[i], x);
		if (kc2>kc)
		{
			kq = a[i];
			kc = kc2;
		}
	}
	return kq;
}

void lietKeToaDoDuong(DIEM a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].iX>0 && a[i].iY > 0)
		{
			xuatDiem(a[i]);
		}
	}
}

void sapXepTangKhoangCach(DIEM a[], int n)
{
	DIEM o;
	o.iX = 0;
	o.iY = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tinhKhoangCach(a[i], o)>tinhKhoangCach(a[j], o))
			{
				hoanViDiem(a[i], a[j]);
			}
		}
	}
}