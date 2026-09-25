#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int sum(int a, int b) { return a + b; }

// Con trỏ hàm làm tham số: "rút gọn" mảng 2 chiều N x M bằng hàm func
int reduce(int **arr, int N, int M, int (*func)(int, int)) {
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0)
                result = arr[i][j];
            else
                result = func(result, arr[i][j]);
        }
    }
    return result;
}

int main() {
    int N = 3, M = 4;
    int **arr = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        arr[i] = malloc(M * sizeof(int));
        for (int j = 0; j < M; j++)
            arr[i][j] = (i * 7 + j * 5) % 11;
    }

    printf("max = %d\n", reduce(arr, N, M, max));
    printf("min = %d\n", reduce(arr, N, M, min));
    printf("sum = %d\n", reduce(arr, N, M, sum));

    for (int i = 0; i < N; i++)
        free(arr[i]);
    free(arr);
    return 0;
}
