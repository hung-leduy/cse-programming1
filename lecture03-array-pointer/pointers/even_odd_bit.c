#include <stdio.h>
#include <stdlib.h>

// Convert n to binary (least significant bit at index 0)
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

// LeetCode 2595: count the 1 bits at even and odd positions
int *evenOddBit(int n, int *returnSize) {
    int *out = malloc(2 * sizeof(int));
    *returnSize = 2;
    int binSize;
    int *bin = toBinary(n, &binSize); // pass the address so the function can write binSize
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
