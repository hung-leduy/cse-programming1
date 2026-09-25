#include <stdio.h>

// Đệ quy: đơn giản nhưng rất chậm vì tính lặp lại nhiều lần (O(2^n))
long fib_recursive(int n) {
    if (n < 2)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Vòng lặp for: mỗi số chỉ tính một lần (O(n))
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

    // Thử n = 45 với fib_recursive sẽ thấy rất chậm, fib_loop thì tức thì
    printf("fib_loop(80) = %ld\n", fib_loop(80));
    return 0;
}
