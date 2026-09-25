#include <stdio.h>

// Truyền tham trị: hàm nhận BẢN SAO, không đổi được biến gốc
void swap_by_value(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Truyền tham chiếu (qua con trỏ): thay đổi được biến gốc
void swap_by_reference(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int x = 1, y = 2;
    swap_by_value(x, y);
    printf("by value:     x = %d, y = %d\n", x, y); // 1, 2
    swap_by_reference(&x, &y);
    printf("by reference: x = %d, y = %d\n", x, y); // 2, 1
    return 0;
}
