#pragma

#include "TamGiac.h"

void nhapTamGiac(TAMGIAC &t)
{
	printf("\n\tNhap dinh A: ");
	nhapDiem(t.A);
	printf("\n\tNhap dinh B: ");
	nhapDiem(t.B);
	printf("\n\tNhap dinh C: ");
	nhapDiem(t.C);
}

void xuatTamGiac(TAMGIAC t)
{
	printf("\n\tDinh A: ");
	xuatDiem(t.A);
	printf("\n\tDinh B: ");
	xuatDiem(t.B);
	printf("\n\tDinh C: ");
	xuatDiem(t.C);
}