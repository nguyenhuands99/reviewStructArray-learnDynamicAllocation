#pragma
#include "MyArray1D.h"
#include "stdio.h"
#include "malloc.h"
#define KHUYENMAI 0.9 //Khuyến mãi 10% 

struct FOOD
{
	char *foodname; //tên của món ăn
	int price; //giá tiền của món ăn
};
//Kiểu FOOD: món ăn

struct MENU
{
	FOOD *dish; //các món ăn trong phần ăn
	int size; //số các món ăn trong phần ăn 
	char id; //Mã của phần ăn
};
//Kiểu MENU: phần ăn

MENU *MenuListInit();
//Hàm cấp phát khởi động bộ nhớ cho kiểu MENU

void MenuListFree(MENU *MenuList);
//Hàm giải phóng bộ nhớ kiểu MENU

MENU *MenuListPush(MENU *MenuList, int n, FOOD F[]);
//Hàm đưa dữ liệu một Phần ăn vào Danh sách các Phần ăn

void MenuListInfo(MENU *MenuList);
//Hàm in ra thông tin của các Phần ăn trong Danh sách

int IdListCheck(MENU *MenuList, char idList);//
											 //Hàm kiểm tra Mã idList có trùng với mã Phần ăn nào trong Danh sách Phần ăn hay không?
											 //Nếu có trả về vị trí của Phần ăn đó trong danh sách

int BillSum(MENU *MenuList, int x);
//Hàm tính tổng các Món ăn trong Phần ăn thứ x

void BillInfo(MENU *MenuList, int x);
//Hàm xuất Tên Món ăn và Giá Món ăn trong Phần ăn thứ x