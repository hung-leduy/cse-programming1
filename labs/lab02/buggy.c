// Lab 2 — Bài tập debug
// Chương trình này biên dịch được nhưng cho kết quả SAI. Có 4 lỗi.
// Dùng gdb hoặc VS Code (breakpoint, step, watch) để tìm, KHÔNG thêm printf.
//
// Ghi lại các lỗi đã tìm được:
//   Lỗi 1: dòng ..., triệu chứng ..., cách sửa ...
//   Lỗi 2:
//   Lỗi 3:
//   Lỗi 4:
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
    int temps[N] = {-5, -3, -8, -1, -9}; // nhiệt độ mùa đông

    printf("sum = %d\n", sum_array(data, N));
    printf("average = %.2f\n", average(data, N));
    printf("max = %d\n", max_array(data, N));
    printf("max temp = %d\n", max_array(temps, N));

    char word[] = "hello";
    reverse_string(word, 5);
    printf("reversed: %s\n", word);

    return 0;
}
