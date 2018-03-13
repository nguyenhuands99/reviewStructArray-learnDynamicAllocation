#pragma

#include "math.h"
#include "MangTamGiac.h"

void nhapMangTamGiac(TAMGIAC a[], int &n)
{
	do
	{
		printf("\nNhap so luong tam giac: ");
		scanf_s("%d", &n);
	} while (n<1||n>MAX_TRIANGLE);
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap tam giac a[%d]: ", i);
		nhapTamGiac(a[i]);
		printf("\n");
	}
}

void xuatMangTamGiac(TAMGIAC a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nTam giac a[%d]: ", i);
		xuatTamGiac(a[i]);
		printf("\n");
	}
}

//Hàm tính chu vi tam giác:
//	Nếu không phải tam giác (thẳng hàng, trùng nhau): trả về 0
//	Trả về chu vi nếu thỏa điều kiện tam giác
double chuViTamGiac(TAMGIAC t)
{
	/*Xét điều kiện không tạo thành tam giác (3 điểm thẳng hàng):
	Ba điểm thẳng hàng khi và chỉ khi hệ số góc của đường thằng ab = hệ số góc của ac
	với:
	hệ số góc của ab k1 = (yB-yA)/(xB-xA)
	hệ số góc của ac k2 = (yC-yA)/(xC-xA)
	k1=k2 <=> (yB-yA)*(xC-xA) = (yC-yA)*(xB-xA) */
	if ((t.B.iY - t.A.iY)*(t.C.iX - t.A.iX) == (t.C.iY - t.A.iY)*(t.B.iX - t.A.iX))
	{
		return 0;
	}

	double AB = tinhKhoangCach(t.A, t.B), AC = tinhKhoangCach(t.A, t.C), BC = tinhKhoangCach(t.B, t.C);

	return AB + AC + BC;
}

TAMGIAC laChuViLonNhat(TAMGIAC a[], int n)
{
	TAMGIAC max=a[0];
	for (int i = 1; i < n; i++)
	{
		if (chuViTamGiac(a[i]) > chuViTamGiac(max))
			max = a[i];
	}
	return max;
}

//Hàm tính diện tích tam giác:
//	Nếu không phải tam giác (thẳng hàng, trùng nhau): trả về 0
//	Trả về diện tích nếu thỏa điều kiện tam giác
double dienTichTamGiac(TAMGIAC t)
{
	//Xet dieu kien tam giac
	if ((t.B.iY - t.A.iY)*(t.C.iX - t.A.iX) == (t.C.iY - t.A.iY)*(t.B.iX - t.A.iX))
	{
		return 0;
	}

	double p = chuViTamGiac(t) / 2;
	double AB = tinhKhoangCach(t.A, t.B), AC = tinhKhoangCach(t.A, t.C), BC = tinhKhoangCach(t.B, t.C);
	return sqrt(p*(p - AB)*(p - BC)*(p - AC));
}

double tongDienTichTamGiac(TAMGIAC a[], int n)
{
	double tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += dienTichTamGiac(a[i]);
	}
	return tong;
}

int demTgiacLonhonDtichTbinh(TAMGIAC a[], int n)
{
	int dem = 0;
	double tbinh = tongDienTichTamGiac(a, n) / n;

	for (int i = 0; i < n; i++)
	{
		if (dienTichTamGiac(a[i]) > tbinh)
		{
			dem++;
		}
	}

	return dem;
}

void sapGiamTheoChuVi(TAMGIAC a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (chuViTamGiac(a[i]) < chuViTamGiac(a[j]))
			{
				//Hoan vi 2 tam giac
				TAMGIAC temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

