#pragma

void *arrInit(int nItem, int sizeItem);
//Khởi động mảng, qui định số phần tử, kích thước mỗi phần tử, trả về  con trỏ phần dữ liệu mảng đã được cấp phát
void *arrResize(void *a, int nItem);
//Thay đổi kích thước mảng, số phần tử mới là nItems, trả về mảng mới. Tham số vào là mảng a phải là con trỏ đã trả về trước bới hàm arrInit(). Mảng cũ tự động được giải phóng khi cần thiết.
int arrSize(void *a);
//Trả về kích thước mảng (số phần tử).
void arrFree(void *a);
//Giải phóng bộ nhớ đã cấp phát
void *arrPushBack(void *a, void *x);
//Thêm phần tử x vào mỗi cuối mảng, cần cấp phát nới rộng bộ nhớ để thêm vào
void *arrPopBack(void *a);
//Lấy phần tử cuối cùng ra khỏi mảng