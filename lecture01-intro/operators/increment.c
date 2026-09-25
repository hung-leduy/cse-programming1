#include <stdio.h>

int main() {
    int i = 42;
    i++;
    printf("i = %d\n", i); // 43

    // i++ : lấy giá trị trước, sau đó mới tăng
    i = 42;
    int j = (i++ + 10);
    printf("j = %d, i = %d\n", j, i); // j = 52, i = 43

    // ++i : tăng trước, sau đó mới lấy giá trị
    i = 42;
    j = (++i + 10);
    printf("j = %d, i = %d\n", j, i); // j = 53, i = 43

    // Tương tự với i-- và --i
    i = 42;
    printf("i-- = %d, ", i--);
    printf("i = %d\n", i); // 41
    return 0;
}
