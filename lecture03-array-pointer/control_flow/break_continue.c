#include <stdio.h>

int main() {
    // continue: bỏ qua phần còn lại, sang lượt lặp tiếp theo
    // break: thoát khỏi vòng lặp
    int i = 0;
    while (1) {
        i++;
        if (i > 10)
            break;
        if (i % 2 == 0)
            continue;
        printf("%d ", i); // chỉ in số lẻ từ 1 đến 9
    }
    printf("\n");
    return 0;
}
