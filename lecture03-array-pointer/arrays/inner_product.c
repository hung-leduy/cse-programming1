#include <stdio.h>

// Tích vô hướng của hai vector: sum(a[i] * b[i])
double inner_product(double a[], double b[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    return sum;
}

int main() {
    double a[] = {1, 2, 3};
    double b[] = {4, 5, 6};
    printf("a . b = %.1f\n", inner_product(a, b, 3)); // 32
    return 0;
}
