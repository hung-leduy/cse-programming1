#include <stdio.h>

// Mảng làm tham số: cần truyền kèm kích thước N
int get_max_1d_array(int a[], int N) {
    int max = a[0];
    for (int i = 1; i < N; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main() {
    int scores[100]; // chỉ số từ 0 đến 99
    for (int i = 0; i < 100; i++)
        scores[i] = (i * 37) % 101;
    scores[0] = 13;  // phần tử đầu tiên
    scores[99] = 42; // phần tử cuối cùng

    printf("max = %d\n", get_max_1d_array(scores, 100));
    return 0;
}
