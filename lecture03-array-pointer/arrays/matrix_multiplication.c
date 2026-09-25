#include <stdio.h>

#define M 2
#define K 3
#define N 2

// C[M][N] = A[M][K] x B[K][N]
void matmul(int A[M][K], int B[K][N], int C[M][N]) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < K; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int A[M][K] = {{1, 2, 3}, {4, 5, 6}};
    int B[K][N] = {{7, 8}, {9, 10}, {11, 12}};
    int C[M][N];
    matmul(A, B, C);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            printf("%5d", C[i][j]);
        printf("\n");
    }
    return 0;
}
