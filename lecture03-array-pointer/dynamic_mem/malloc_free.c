#include <stdio.h>
#include <stdlib.h>

int main() {
    // Cấp phát một biến
    int *p = malloc(sizeof(int));
    *p = 42;
    printf("*p = %d\n", *p);
    free(p);

    // Cấp phát mảng int[100]
    int *p_scores = malloc(100 * sizeof(int));
    if (p_scores == NULL) { // luôn kiểm tra kết quả malloc
        printf("Không đủ bộ nhớ\n");
        return 1;
    }
    p_scores[0] = 13;  // chỉ số giống như mảng thường
    p_scores[99] = 42;
    printf("%d %d\n", p_scores[0], p_scores[99]);
    free(p_scores);    // giải phóng -> tránh rò rỉ bộ nhớ (memory leak)
    p_scores = NULL;   // tránh con trỏ treo (dangling pointer)
    return 0;
}
