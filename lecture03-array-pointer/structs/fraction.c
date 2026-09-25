#include <stdio.h>

struct fraction {
    int numerator;
    int denominator;
}; // Don't forget the semicolon!

void print_fraction(struct fraction f) {
    printf("%d/%d\n", f.numerator, f.denominator);
}

struct fraction multiply(struct fraction a, struct fraction b) {
    struct fraction r = {a.numerator * b.numerator, a.denominator * b.denominator};
    return r;
}

int main() {
    struct fraction f1, f2; // declare two fractions
    f1.numerator = 22;      // access members with '.'
    f1.denominator = 7;
    f2 = f1; // copies the whole struct

    print_fraction(f2);
    print_fraction(multiply(f1, f2));
    return 0;
}
