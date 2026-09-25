#include <stdio.h>
#include <stdlib.h>

// Cấp phát mảng 2 chiều rows x cols bằng con trỏ int **
int **alloc_2d(int rows, int cols) {
    int **a = malloc(rows * sizeof(int *)); // mảng các con trỏ hàng
    for (int i = 0; i < rows; i++)
        a[i] = malloc(cols * sizeof(int));  // mỗi hàng là một mảng int
    return a;
}

// Giải phóng: từng hàng trước, mảng con trỏ sau
void free_2d(int **a, int rows) {
    for (int i = 0; i < rows; i++)
        free(a[i]);
    free(a);
}

int main() {
    int rows = 3, cols = 4;
    int **a = alloc_2d(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = i * cols + j; // truy cập như mảng 2 chiều thường

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    free_2d(a, rows);
    return 0;
}
