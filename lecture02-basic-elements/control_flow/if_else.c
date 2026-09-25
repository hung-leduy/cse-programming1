#include <stdio.h>

void classify(int score) {
    if (score >= 90) {
        printf("%d: A\n", score);
    } else if (score >= 70) {
        printf("%d: B\n", score);
    } else if (score >= 50) {
        printf("%d: C\n", score);
    } else {
        printf("%d: F\n", score);
    }
}

int main() {
    int x = 7;
    if (x % 2 == 0) printf("%d là số chẵn\n", x); // dạng đơn giản không có {}
    if (x % 2 != 0) printf("%d là số lẻ\n", x);

    classify(95);
    classify(75);
    classify(55);
    classify(10);
    return 0;
}
