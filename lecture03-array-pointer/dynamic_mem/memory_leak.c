#include <stdio.h>
#include <stdlib.h>

// Ví dụ rò rỉ bộ nhớ: kiểm tra với valgrind
//   gcc -g memory_leak.c -o memory_leak && valgrind --leak-check=full ./memory_leak
void leak(void) {
    int *p = malloc(10 * sizeof(int));
    p[0] = 1;
    // quên free(p): khi hàm kết thúc, không còn cách nào giải phóng vùng nhớ này
}

void no_leak(void) {
    int *p = malloc(10 * sizeof(int));
    p[0] = 1;
    free(p);
}

int main() {
    leak();
    no_leak();
    printf("done\n");
    return 0;
}
