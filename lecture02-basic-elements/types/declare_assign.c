#include <stdio.h>

int main() {
    // Khai báo biến
    int integer_var;
    char char_var;
    float float_var;

    // Gán giá trị hằng
    integer_var = 42;      // số nguyên
    integer_var = 0x2A;    // số hệ 16 (hexadecimal) = 42
    char_var = 'A';        // hằng ký tự
    float_var = 3.14f;     // số thực

    printf("%d %c %f\n", integer_var, char_var, float_var);

    // Tên biến phân biệt hoa/thường, được dùng dấu _
    int count = 1, Count = 2, _count = 3;
    printf("%d %d %d\n", count, Count, _count);
    return 0;
}
