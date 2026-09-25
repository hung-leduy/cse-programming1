#include <stdio.h>

// Array as a parameter: the size N must be passed too
int get_max_1d_array(int a[], int N) {
    int max = a[0];
    for (int i = 1; i < N; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main() {
    int scores[100]; // indices 0 to 99
    for (int i = 0; i < 100; i++)
        scores[i] = (i * 37) % 101;
    scores[0] = 13;  // first element
    scores[99] = 42; // last element

    printf("max = %d\n", get_max_1d_array(scores, 100));
    return 0;
}
