#include <stdio.h>

int main() {
    // for
    for (int i = 0; i < 5; i++)
        printf("for: %d\n", i);

    // while: kiểm tra điều kiện trước
    int j = 0;
    while (j < 3) {
        printf("while: %d\n", j);
        j++;
    }

    // do-while: thân vòng lặp chạy ít nhất một lần
    int k = 10;
    do {
        printf("do-while: %d\n", k);
        k++;
    } while (k < 3);
    return 0;
}
