#include <stdio.h>

int main() {
    int a = 17, b = 5;
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b); // chia nguyên: 3
    printf("a %% b = %d\n", a % b); // chia lấy dư: 2

    double x = 17.0, y = 5.0;
    printf("x / y = %f\n", x / y); // chia số thực: 3.4
    // x % y -> lỗi biên dịch: toán tử % không dùng cho float/double
    return 0;
}
