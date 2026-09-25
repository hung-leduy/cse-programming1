#include <stdio.h>

// Định nghĩa hàm print_hello: đầu vào là chuỗi, đầu ra là int
int print_hello(const char *name) {
    printf("hello, %s\n", name);
    return 0;
}

// Hàm không có đầu vào và không trả về giá trị
void print_line(void) {
    printf("------------\n");
}

int main() {
    // Một hàm có thể được gọi nhiều lần -> tái sử dụng code
    print_hello("world");
    print_line();
    print_hello("student");
    print_hello("teacher");
    return 0;
}
