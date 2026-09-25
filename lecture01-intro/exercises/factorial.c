#include <stdio.h>

// f(n) = n * (n-1) * ... * 2 * 1, dùng đệ quy
long factorial_recursive(int n) {
    if (n <= 1)
        return 1;
    return n * factorial_recursive(n - 1);
}

// Dùng vòng lặp for
long factorial_loop(int n) {
    long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    for (int n = 0; n <= 10; n++)
        printf("%2d! = %ld (loop: %ld)\n", n, factorial_recursive(n), factorial_loop(n));
    return 0;
}
