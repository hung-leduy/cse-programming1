#include <stdio.h>
#include "math_utils.h"

int main() {
    printf("gcd(12, 18) = %d\n", gcd(12, 18));
    printf("lcm(4, 6)   = %d\n", lcm(4, 6));
    printf("primes < 30:");
    for (int i = 0; i < 30; i++)
        if (is_prime(i))
            printf(" %d", i);
    printf("\n");
    return 0;
}
