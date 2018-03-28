#pragma

#include "MonAn.h"
#include "stdlib.h"

void taoMon(char *x, int y, FOOD *list[])
{
	static int count;

	//create array of struct
	list[count] = (struct FOOD*)malloc(sizeof(FOOD) * 6);

	list[count]->foodname = x;
	list[count]->price = y;
	count++;
}