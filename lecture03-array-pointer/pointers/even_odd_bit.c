#include <stdio.h>
#include <stdlib.h>

// Chuyển n sang nhị phân (bit thấp nhất ở vị trí 0)
int *toBinary(int n, int *binSize) {
    int *bin = malloc(32 * sizeof(int));
    int size = 0;
    do {
        bin[size++] = n % 2;
        n /= 2;
    } while (n > 0);
    *binSize = size;
    return bin;
}

// LeetCode 2595: đếm số bit 1 ở vị trí chẵn và lẻ
int *evenOddBit(int n, int *returnSize) {
    int *out = malloc(2 * sizeof(int));
    *returnSize = 2;
    int binSize;
    int *bin = toBinary(n, &binSize); // truyền địa chỉ để hàm ghi vào binSize
    out[0] = out[1] = 0;
    for (int i = 0; i < binSize; i++)
        if (bin[i])
            out[i % 2]++;
    free(bin);
    return out;
}

int main() {
    int returnSize;
    int *res = evenOddBit(17, &returnSize); // 17 = 10001b
    printf("[%d, %d]\n", res[0], res[1]);   // [2, 0]
    free(res);
    return 0;
}
