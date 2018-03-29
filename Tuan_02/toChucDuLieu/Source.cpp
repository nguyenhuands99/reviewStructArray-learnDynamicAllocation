#include <stdio.h>
#include <conio.h>
#include "MenuList.h"

//Thông tin các phần ăn trong kho dữ liệu. Dễ dàng chỉnh sửa thay đổi giá trị món, tên món, số lượng món trong mỗi phần
FOOD phanA[] = { { "Burger" ,130 },{ "Drink" ,130 },{ "Potato" ,120 } };
FOOD phanB[] = { { "Cheese burger" ,150 },{ "Drink" ,130 },{ "Potato" ,120 } };
FOOD phanC[] = { { "Chicken burger",200 },{ "Drink" ,130 },{ "Potato" ,120 } };
FOOD phanD[] = { { "Chicken burger",200 },{ "Drink" ,130 },{ "Potato" ,120 } ,{ "Ice cream" ,130 } };
int n1 = (sizeof(phanA) / sizeof(phanA[0])), n2 = (sizeof(phanB) / sizeof(phanB[0])), n3 = (sizeof(phanC) / sizeof(phanC[0])), n4 = (sizeof(phanD) / sizeof(phanD[0]));

void main()
{
	MENU *mList = MenuListInit();//Cấp phát khởi động bộ nhớ 
	char idList;

	//Thêm các phần ăn từ kho dữ liệu vào bộ nhớ
	if (mList != NULL)
	{
		mList = MenuListPush(mList, n1, phanA);
		mList = MenuListPush(mList, n2, phanB);
		mList = MenuListPush(mList, n3, phanC);
		mList = MenuListPush(mList, n4, phanD);
	}
	//In thông tin của các phần ăn
	MenuListInfo(mList);
	//Khách hàng chọn mã phần ăn 
	scanf_s("%c", &idList);
	idList = getchar();

	int MenuNo = IdListCheck(mList, idList); //trả về vị trí Phần ăn trong danh sách
	if (MenuNo == -1) //Khi mã khách chọn không có trong Danh sách
	{
		printf("\nDa xay ra loi khi chon phan an");
	}
	else
	{
		BillInfo(mList, MenuNo);
	}

	MenuListFree(mList);
	_getch();
}