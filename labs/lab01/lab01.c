// Lab 1 — Nền tảng C
// Biên dịch và chạy:  gcc -Wall -Wextra lab01.c -o lab01 && ./lab01
// Nhiệm vụ: cài đặt các hàm có đánh dấu TODO cho đến khi tất cả đều PASS.
#include <stdio.h>

// ---------------------------------------------------------------------------
// Khung kiểm tra đơn giản (không cần sửa)
static int passed = 0, total = 0;
#define CHECK(expr)                                 \
    do {                                            \
        total++;                                    \
        if (expr) {                                 \
            passed++;                               \
            printf("  PASS  %s\n", #expr);          \
        } else {                                    \
            printf("  FAIL  %s\n", #expr);          \
        }                                           \
    } while (0)
// ---------------------------------------------------------------------------

// 1.1 Tổng hai số
int add(int a, int b) {
    // TODO
    (void)a; (void)b; // xoá dòng này khi cài đặt
    return -1; // TODO: sửa giá trị trả về
}

// 1.2 Tổng các chữ số của n (n có thể âm: sum_digits(-12) = 3)
int sum_digits(int n) {
    // TODO: dùng n % 10 để lấy chữ số cuối, n / 10 để bỏ chữ số cuối
    (void)n;
    return -1; // TODO: sửa giá trị trả về
}

// 1.3 n! bằng vòng lặp (0! = 1)
long factorial(int n) {
    // TODO
    (void)n;
    return -1; // TODO: sửa giá trị trả về
}

// 1.4a Fibonacci bằng đệ quy: fib(0) = 0, fib(1) = 1, fib(n) = fib(n-1) + fib(n-2)
long fib_recursive(int n) {
    // TODO
    (void)n;
    return -1; // TODO: sửa giá trị trả về
}

// 1.4b Fibonacci bằng vòng lặp
long fib_loop(int n) {
    // TODO
    (void)n;
    return -1; // TODO: sửa giá trị trả về
}

// 1.5 Trả về 1 nếu n là số nguyên tố, ngược lại 0 (số < 2 không phải số nguyên tố)
int is_prime(int n) {
    // TODO: chỉ cần thử các ước i với i * i <= n
    (void)n;
    return -1; // TODO: sửa giá trị trả về
}

// 1.6 Ước chung lớn nhất (thuật toán Euclid): gcd(a, b) = gcd(b, a % b), gcd(a, 0) = a
int gcd(int a, int b) {
    // TODO
    (void)a; (void)b;
    return -1; // TODO: sửa giá trị trả về
}

// 1.7 Năm nhuận
int is_leap_year(int y) {
    // TODO
    (void)y;
    return -1; // TODO: sửa giá trị trả về
}

// 1.8 Số ngày trong tháng. BẮT BUỘC dùng switch, gộp các case cùng kết quả.
// Trả về 0 nếu month không nằm trong 1..12
int days_in_month(int month, int year) {
    // TODO
    (void)month; (void)year;
    return -1; // TODO: sửa giá trị trả về
}

int main() {
    printf("1.1 add\n");
    CHECK(add(2, 3) == 5);
    CHECK(add(-4, 4) == 0);

    printf("1.2 sum_digits\n");
    CHECK(sum_digits(1234) == 10);
    CHECK(sum_digits(0) == 0);
    CHECK(sum_digits(-12) == 3);

    printf("1.3 factorial\n");
    CHECK(factorial(0) == 1);
    CHECK(factorial(5) == 120);
    CHECK(factorial(15) == 1307674368000L);

    printf("1.4 fibonacci\n");
    CHECK(fib_recursive(0) == 0);
    CHECK(fib_recursive(1) == 1);
    CHECK(fib_recursive(20) == 6765);
    CHECK(fib_loop(0) == 0);
    CHECK(fib_loop(20) == 6765);
    CHECK(fib_loop(80) == 23416728348467685L);

    printf("1.5 is_prime\n");
    CHECK(is_prime(2) == 1);
    CHECK(is_prime(97) == 1);
    CHECK(is_prime(1) == 0);
    CHECK(is_prime(91) == 0);
    CHECK(is_prime(-7) == 0);

    printf("1.6 gcd\n");
    CHECK(gcd(12, 18) == 6);
    CHECK(gcd(17, 5) == 1);
    CHECK(gcd(7, 0) == 7);

    printf("1.7 is_leap_year\n");
    CHECK(is_leap_year(2024) == 1);
    CHECK(is_leap_year(2023) == 0);
    CHECK(is_leap_year(1900) == 0);
    CHECK(is_leap_year(2000) == 1);

    printf("1.8 days_in_month\n");
    CHECK(days_in_month(1, 2023) == 31);
    CHECK(days_in_month(4, 2023) == 30);
    CHECK(days_in_month(2, 2023) == 28);
    CHECK(days_in_month(2, 2024) == 29);
    CHECK(days_in_month(13, 2024) == 0);

    printf("\nKết quả: %d/%d PASS\n", passed, total);
    return passed == total ? 0 : 1;
}
