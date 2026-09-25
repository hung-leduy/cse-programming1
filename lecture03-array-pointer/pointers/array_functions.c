#include <stdio.h>
#include <stdlib.h>

// Find the maximum, returned through a pointer parameter
void find_max(int *a, int n, int *max) {
    *max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > *max)
            *max = a[i];
}

// Reverse an array by swapping values
void reverse(int *a, int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}

// Return a pointer to a new array, with its size in *returnSize
// (LeetCode-style function)
int *even_numbers(int *a, int n, int *returnSize) {
    int *out = malloc(n * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            out[count++] = a[i];
    *returnSize = count;
    return out; // heap memory persists after the function returns
}

int main() {
    int a[] = {4, 7, 1, 8, 2, 9, 6};
    int n = sizeof(a) / sizeof(a[0]);

    int max;
    find_max(a, n, &max);
    printf("max = %d\n", max);

    reverse(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    int size;
    int *evens = even_numbers(a, n, &size);
    for (int i = 0; i < size; i++) printf("%d ", evens[i]);
    printf("(size = %d)\n", size);
    free(evens);
    return 0;
}
