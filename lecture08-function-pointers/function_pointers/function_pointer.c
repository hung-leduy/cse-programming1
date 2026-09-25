#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int sum(int a, int b) { return a + b; }

int main() {
    int (*func)(int, int); // con trỏ tới hàm nhận (int, int) và trả về int

    func = max; // tên hàm chính là địa chỉ của hàm
    printf("max(3, 7) = %d\n", func(3, 7));
    func = min;
    printf("min(3, 7) = %d\n", func(3, 7));
    func = &sum; // viết &sum cũng được
    printf("sum(3, 7) = %d\n", (*func)(3, 7));

    // Mảng các con trỏ hàm
    int (*ops[])(int, int) = {max, min, sum};
    const char *names[] = {"max", "min", "sum"};
    for (int i = 0; i < 3; i++)
        printf("%s(10, 4) = %d\n", names[i], ops[i](10, 4));
    return 0;
}
