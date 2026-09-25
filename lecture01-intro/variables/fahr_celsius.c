#include <stdio.h>

// In bảng chuyển đổi nhiệt độ Fahrenheit -> Celsius (K&R, mục 1.2)
int main() {
    int fahr, celsius; // khai báo biến

    fahr = 0;
    while (fahr <= 300) {
        celsius = 5 * (fahr - 32) / 9; // phép chia số nguyên
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + 20;
    }
    return 0;
}
