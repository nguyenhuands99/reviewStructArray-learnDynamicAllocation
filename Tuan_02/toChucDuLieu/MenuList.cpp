#pragma
#include "stdio.h"
#include "malloc.h"
#include "MyArray1D.h"
#include "MenuList.h"

MENU *MenuListInit()
{
	void *p;
	p = arrInit(0, sizeof(MENU));
	return (MENU *)p;
}

void MenuListFree(MENU *MenuList)
{
	if (MenuList == NULL)
		return;
	int nMenu = arrSize(MenuList);
	for (int i = 0; i < nMenu; i++)
	{
		if (MenuList[i].dish != NULL)
			free(MenuList[i].dish);
	}
	arrFree(MenuList);
}


MENU *MenuListPush(MENU *MenuList, int n, FOOD F[])
{
	if (n <= 0)
	{
		return MenuList;
	}
	MENU menu;
	menu.size = n;//kích cỡ mảng F vào size của Menu
	static char ch = '1';//khởi tạo biến static để lưu mã ASCII sau mỗi lần thực hiện hàm
	menu.id = ch++; //Sau mỗi lần tăng Mã của Phần Ăn 1 đơn vị (mã ASCII). VD: '1' -> '2'
	menu.dish = (FOOD *)calloc(n, sizeof(FOOD));
	for (int i = 0; i < n; i++) //Thêm các Món ăn trong mảng F vào Phần ăn
	{
		menu.dish[i] = F[i];
	}
	void *p = arrPushBack(MenuList, &menu);
	return (MENU *)p;

}
void MenuListInfo(MENU *MenuList)
{
	printf("\nChon mot trong cac phan an sau:\n");
	int listSize = arrSize(MenuList); //Số lượng các phần ăn trong MenuList
	for (int i = 0; i < listSize; i++)
	{
		printf("%d: Phan an %c (", i + 1, MenuList[i].id + ('A' - '1'));//Chuyển mã Phần ăn. vd: từ '1' -> 'A'
		for (int j = 0; j < MenuList[i].size; j++) //In ra tên các Món ăn trong mỗi Phần ăn
		{
			printf("%s", MenuList[i].dish[j].foodname);
			if (j != MenuList[i].size - 1) //Thêm dấu phẩy sau mỗi món
				printf(", ");
		}
		printf(")\n");
	}
}

int IdListCheck(MENU *MenuList, char idList)
{
	int listSize = arrSize(MenuList);//Số lượng các phần ăn trong MenuList
	for (int i = 0; i < listSize; i++) //Kiểm tra mã Phần ăn nào trùng với mã idList người dùng nhập
	{
		if (MenuList[i].id == idList)
		{
			return i; //trả về vị trí phần ăn trong Danh sách
		}
	}
	return -1; //Không có
}
int BillSum(MENU *MenuList, int x)
{
	int sum = 0;
	for (int i = 0; i < MenuList[x].size; i++)
	{
		sum += MenuList[x].dish[i].price;
	}
	return sum;
}

void BillInfo(MENU *MenuList, int x)
{
	printf("\n\n********* PHAN AN %c *********", MenuList[x].id + ('A' - '1'));
	for (int i = 0; i < MenuList[x].size; i++)//In thông tin các món trong Phần ăn thứ x
	{
		printf("\n%s: %d JPY", MenuList[x].dish[i].foodname, MenuList[x].dish[i].price);
	}
	printf("\n-----------------------------");
	printf("\nTong gia tri mon: %d JPY", BillSum(MenuList, x)); //Giá trị thật của các món
	printf("\nGia tri phan an: %d JPY", (int)(BillSum(MenuList, x)*KHUYENMAI)); //Tiền phải trả

}