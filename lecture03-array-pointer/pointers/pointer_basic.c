#include <stdio.h>

int main() {
    // Khai báo con trỏ
    int *int_pointer;
    float *float_pointer;
    char *char_pointer;
    void *pointer;      // con trỏ tổng quát
    int_pointer = NULL; // con trỏ rỗng
    float_pointer = NULL;
    char_pointer = NULL;
    pointer = NULL;
    printf("%p %p %p %p\n", (void *)int_pointer, (void *)float_pointer, (void *)char_pointer, pointer);

    int x = 10;
    int_pointer = &x; // tham chiếu (referencing): lấy địa chỉ của x
    printf("địa chỉ của x = %p\n", (void *)int_pointer);
    printf("*int_pointer  = %d\n", *int_pointer); // giải tham chiếu (dereferencing)

    *int_pointer = 20; // thay đổi x thông qua con trỏ
    printf("x = %d\n", x);
    return 0;
}
