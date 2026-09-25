#include <stdio.h>

int main() {
    int a = 5, b = 10;

    // Toán tử quan hệ: kết quả là 1 (đúng) hoặc 0 (sai)
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a >  b: %d\n", a > b);
    printf("a <  b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);

    // Toán tử logic
    printf("!(a < b): %d\n", !(a < b));
    printf("a < b && b < 20: %d\n", a < b && b < 20);
    printf("a > b || b < 20: %d\n", a > b || b < 20);

    // Trong C, mọi giá trị khác 0 đều được xem là "đúng"
    if (42)
        printf("42 là đúng\n");
    return 0;
}
