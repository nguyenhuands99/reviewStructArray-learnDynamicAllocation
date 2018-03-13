#pragma

#include "Diem.h"
#include "math.h"

void nhapDiem(DIEM &a)
{
	printf("\n\tNhap x: ");
	scanf_s("%f", &a.iX);
	printf("\n\tNhap y: ");
	scanf_s("%f", &a.iY);
}

void xuatDiem(DIEM a)
{
	printf("\t(%.2f, %.2f)", a.iX, a.iY);
}

double tinhKhoangCach(DIEM a, DIEM b)
{
	double kc = sqrt(pow(float(b.iX - a.iX), 2) + pow(float(b.iY - a.iY), 2));
	return kc;
}