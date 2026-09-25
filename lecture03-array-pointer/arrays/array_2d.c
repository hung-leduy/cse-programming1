#include <stdio.h>

#define M 3
#define N 4

// Tìm max theo trục (axis), giống numpy:
//  axis = 0: max theo cột -> kết quả có N phần tử
//  axis = 1: max theo hàng -> kết quả có M phần tử
// Lưu ý: với mảng 2 chiều, kích thước chiều thứ hai phải được chỉ rõ
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
    // board[0] có kiểu int[10]: mảng 2 chiều là mảng của các mảng
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
