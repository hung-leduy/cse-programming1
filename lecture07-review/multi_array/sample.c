#include <stdio.h>

// Chương trình nhỏ để thử debug với VS Code (đặt breakpoint trong vòng lặp)
int main() {
    int a[5] = {5, 3, 8, 1, 9};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += a[i]; // <-- đặt breakpoint ở đây, xem giá trị i, sum, a[i]
    }
    printf("sum = %d\n", sum);
    return 0;
}
