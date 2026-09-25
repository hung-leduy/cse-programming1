#include <stdio.h>

// Recursion: simple but very slow because values are recomputed many times (O(2^n))
long fib_recursive(int n) {
    if (n < 2)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// for loop: each number is computed only once (O(n))
long fib_loop(int n) {
    long prev = 0, curr = 1;
    if (n == 0)
        return 0;
    for (int i = 2; i <= n; i++) {
        long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    for (int n = 0; n <= 20; n++)
        printf("fib(%2d) = %5ld (loop: %5ld)\n", n, fib_recursive(n), fib_loop(n));

    // Try n = 45: fib_recursive is very slow, fib_loop is instant
    printf("fib_loop(80) = %ld\n", fib_loop(80));
    return 0;
}
