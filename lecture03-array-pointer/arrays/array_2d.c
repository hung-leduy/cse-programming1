#include <stdio.h>

#define M 3
#define N 4

// Find the max along an axis, like numpy:
//  axis = 0: max of each column -> result has N elements
//  axis = 1: max of each row -> result has M elements
// Note: for a 2D array, the size of the second dimension must be specified
void get_max_2d_array(int a[][N], int rows, int axis, int out[]) {
    if (axis == 0) {
        for (int j = 0; j < N; j++) {
            out[j] = a[0][j];
            for (int i = 1; i < rows; i++)
                if (a[i][j] > out[j])
                    out[j] = a[i][j];
        }
    } else {
        for (int i = 0; i < rows; i++) {
            out[i] = a[i][0];
            for (int j = 1; j < N; j++)
                if (a[i][j] > out[i])
                    out[i] = a[i][j];
        }
    }
}

int main() {
    int board[10][10];
    board[0][0] = 13;
    board[9][9] = 13;
    // board[0] has type int[10]: a 2D array is an array of arrays
    printf("sizeof(board) = %zu, sizeof(board[0]) = %zu\n", sizeof(board), sizeof(board[0]));

    int a[M][N] = {
        {1, 8, 3, 4},
        {5, 2, 7, 0},
        {9, 6, 1, 2},
    };
    int max_cols[N], max_rows[M];
    get_max_2d_array(a, M, 0, max_cols);
    get_max_2d_array(a, M, 1, max_rows);

    printf("axis=0:");
    for (int j = 0; j < N; j++) printf(" %d", max_cols[j]);
    printf("\naxis=1:");
    for (int i = 0; i < M; i++) printf(" %d", max_rows[i]);
    printf("\n");
    return 0;
}
