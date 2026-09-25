#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// qsort của thư viện chuẩn nhận một con trỏ hàm để so sánh hai phần tử
int ascending(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int descending(const void *a, const void *b) {
    return *(const int *)b - *(const int *)a;
}

int by_string(const void *a, const void *b) {
    return strcmp(*(const char *const *)a, *(const char *const *)b);
}

void print(int *a, int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {5, 2, 9, 1, 7};
    qsort(a, 5, sizeof(int), ascending);
    print(a, 5);
    qsort(a, 5, sizeof(int), descending);
    print(a, 5);

    const char *names[] = {"lan", "an", "minh", "binh"};
    qsort(names, 4, sizeof(char *), by_string);
    for (int i = 0; i < 4; i++) printf("%s ", names[i]);
    printf("\n");
    return 0;
}
