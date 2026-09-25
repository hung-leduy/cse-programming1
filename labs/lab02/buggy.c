// Lab 2 - Debugging exercise
// This program compiles but produces WRONG results. There are 4 bugs.
// Use gdb or VS Code (breakpoints, step, watch) to find them; do NOT add printf.
//
// Record the bugs you find:
//   Bug 1: line ..., symptom ..., fix ...
//   Bug 2:
//   Bug 3:
//   Bug 4:
#include <stdio.h>

#define N 5

int sum_array(int a[], int n) {
    int sum = 0;
    for (int i = 1; i < n; i++)
        sum += a[i];
    return sum;
}

double average(int a[], int n) {
    return sum_array(a, n) / n;
}

int max_array(int a[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void reverse_string(char s[], int len) {
    for (int i = 0; i < len; i++) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

int main() {
    int data[N] = {10, 20, 30, 40, 51};
    int temps[N] = {-5, -3, -8, -1, -9}; // winter temperatures

    printf("sum = %d\n", sum_array(data, N));
    printf("average = %.2f\n", average(data, N));
    printf("max = %d\n", max_array(data, N));
    printf("max temp = %d\n", max_array(temps, N));

    char word[] = "hello";
    reverse_string(word, 5);
    printf("reversed: %s\n", word);

    return 0;
}
