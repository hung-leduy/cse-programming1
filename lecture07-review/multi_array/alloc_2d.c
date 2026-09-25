#include <stdio.h>
#include <stdlib.h>

// Allocate a rows x cols 2D array using an int ** pointer
int **alloc_2d(int rows, int cols) {
    int **a = malloc(rows * sizeof(int *)); // array of row pointers
    for (int i = 0; i < rows; i++)
        a[i] = malloc(cols * sizeof(int));  // each row is an int array
    return a;
}

// Free: each row first, then the array of pointers
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
            a[i][j] = i * cols + j; // accessed like a regular 2D array

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    free_2d(a, rows);
    return 0;
}
