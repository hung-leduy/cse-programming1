#include <stdio.h>

int main() {
    char variable = 'a';
    int value = variable; // 97: tự động chuyển theo bảng mã ASCII
    printf("'%c' = %d\n", variable, value);

    // In một phần bảng ASCII
    for (char c = 'A'; c <= 'Z'; c++)
        printf("%c=%d ", c, c);
    printf("\n");

    // Chuyển chữ thường -> chữ hoa bằng phép toán số học
    char lower = 'g';
    char upper = lower - 'a' + 'A';
    printf("%c -> %c\n", lower, upper);
    return 0;
}
