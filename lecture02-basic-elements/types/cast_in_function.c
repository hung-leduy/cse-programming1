#include <stdio.h>

double half(double x) {
    return x / 2;
}

int take_int(int x) {
    return x;
}

int main() {
    // Arguments are converted automatically, just like in assignment
    printf("half(5) = %f\n", half(5));          // int -> double: 2.5
    printf("take_int(3.9) = %d\n", take_int(3.9)); // double -> int: 3
    return 0;
}
