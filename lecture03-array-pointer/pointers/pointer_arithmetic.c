#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int *base = calloc(5, sizeof(int)); // 5 số nguyên, khởi tạo bằng 0
    int *p_scores = base;

    // Di chuyển con trỏ: p + 1 tiến thêm sizeof(int) byte
    printf("p_scores     = %p\n", (void *)p_scores);
    printf("p_scores + 3 = %p\n", (void *)(p_scores + 3));

    *(p_scores) = 3;     // base[0] = 3
    *(++p_scores) = 1;   // tăng p trước rồi gán: base[1] = 1
    *(p_scores + 3) = 2; // base[1 + 3] = base[4] = 2
    print(base, 5);      // 3 1 0 0 2

    // Quiz: *(p_scores++) = 7 gán vào vị trí HIỆN TẠI rồi mới tăng p
    p_scores = base;
    *(p_scores++) = 7; // base[0] = 7, sau đó p trỏ tới base[1]
    print(base, 5);    // 7 1 0 0 2
    printf("*p_scores = %d\n", *p_scores); // 1

    free(base); // giải phóng bằng con trỏ gốc, không phải p_scores đã bị dịch
    return 0;
}
