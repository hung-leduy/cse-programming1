// Lab 1 — C Fundamentals
// Compile and run:  gcc -Wall -Wextra lab01.c -o lab01 && ./lab01
// Task: implement the functions marked TODO until all tests PASS.
#include <stdio.h>

// ---------------------------------------------------------------------------
// Simple test harness (no need to modify)
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

// 1.1 Sum of two numbers
int add(int a, int b) {
    return a+b; // TODO: fix the return value
}

// 1.2 Sum of the digits of n (n may be negative: sum_digits(-12) = 3)
int sum_digits(int n) {
    // TODO: use n % 10 to get the last digit, n / 10 to drop the last digit
    if (n < 0) n *= -1;
    int res = 0;
    while(n/10 != 0){
        res += n%10;
        n /= 10;
    }
    return res+n;
}

// 1.3 n! using a loop (0! = 1)
long long factorial(int n) {
    if (n == 0) return 1;
    long long res = 1;
    for (int i = 1; i<=n; ++i){
        res*=i;
    }
    return res;
}

// 1.4a Recursive Fibonacci: fib(0) = 0, fib(1) = 1, fib(n) = fib(n-1) + fib(n-2)
long fib_recursive(int n) {
    if (n == 1 || n == 0){
        return (long) n;
    }
    return fib_recursive(n-1)+fib_recursive(n-2);
}

// 1.4b Iterative Fibonacci
long long fib_loop(int n) {
    if (n == 1 || n == 0){
        return n;
    }
    long long arr[n];
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < n ; ++i){
        arr[i] = arr[i-1]+arr[i-2];
    }

    return arr[n-1];
}

// 1.5 Return 1 if n is prime, otherwise 0 (numbers < 2 are not prime)
int is_prime(int n) {
    if (n < 2) return 0;

    for (int i = 2; i < n; ++i){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

// 1.6 Greatest common divisor (Euclid's algorithm): gcd(a, b) = gcd(b, a % b), gcd(a, 0) = a
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

// 1.7 Leap year
int is_leap_year(int y) {
    if (y % 400 == 0)
        return 1;
    
    if (y % 100 == 0)
        return 0;
    
    if (y % 4 == 0)
        return 1;
    
    return 0;
}

// 1.8 Number of days in a month. You MUST use switch, grouping cases with the same result.
// Return 0 if month is not in 1..12
int days_in_month(int month, int year) {
    if (month > 12 || month < 1) return 0;
    switch(month){
        case 1: case 3: case 5: case 7:case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (is_leap_year(year)){
                return 29;
            }else{
                return 28;
            }
    }
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

    printf("\nResult: %d/%d PASS\n", passed, total);
    return passed == total ? 0 : 1;
}
