#include <stdio.h>

// Tích chập 1 chiều (chế độ "valid"): out có n - k + 1 phần tử
void convolve_1d(int in[], int n, int kernel[], int k, int out[]) {
    for (int i = 0; i <= n - k; i++) {
        out[i] = 0;
        for (int j = 0; j < k; j++)
            out[i] += in[i + j] * kernel[j];
    }
}

// Tích chập 2 chiều (chế độ "valid") trên ảnh H x W với kernel 3 x 3
#define H 5
#define W 5
#define KS 3
void convolve_2d(int img[H][W], int ker[KS][KS], int out[H - KS + 1][W - KS + 1]) {
    for (int i = 0; i <= H - KS; i++)
        for (int j = 0; j <= W - KS; j++) {
            out[i][j] = 0;
            for (int u = 0; u < KS; u++)
                for (int v = 0; v < KS; v++)
                    out[i][j] += img[i + u][j + v] * ker[u][v];
        }
}

int main() {
    int in[] = {1, 2, 3, 4, 5, 6};
    int kernel[] = {1, 0, -1};
    int out[4];
    convolve_1d(in, 6, kernel, 3, out);
    printf("1D:");
    for (int i = 0; i < 4; i++) printf(" %d", out[i]);
    printf("\n");

    // Ảnh 5 x 5 có một vùng sáng (giá trị 9) ở góc dưới phải
    int img[H][W] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 9, 9, 9},
        {0, 0, 9, 9, 9},
        {0, 0, 9, 9, 9},
    };
    int ker[KS][KS] = {{0, 1, 0}, {1, -4, 1}, {0, 1, 0}}; // Laplacian: phát hiện biên
    int out2[H - KS + 1][W - KS + 1];
    convolve_2d(img, ker, out2);
    printf("2D:\n");
    for (int i = 0; i <= H - KS; i++) {
        for (int j = 0; j <= W - KS; j++)
            printf("%4d", out2[i][j]);
        printf("\n");
    }
    return 0;
}
