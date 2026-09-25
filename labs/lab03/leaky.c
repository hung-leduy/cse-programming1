// Lab 3 — Bài tập valgrind
// Chương trình in ra kết quả "có vẻ đúng" nhưng có 4 lỗi bộ nhớ.
//   gcc -Wall -g leaky.c -o leaky
//   valgrind --leak-check=full --track-origins=yes ./leaky
// Sửa tất cả lỗi cho tới khi valgrind báo: 0 errors, không rò rỉ.
//
// Ghi lại các lỗi đã tìm được:
//   Lỗi 1: dòng ..., valgrind báo ..., cách sửa ...
//   Lỗi 2:
//   Lỗi 3:
//   Lỗi 4:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tạo bản sao của chuỗi trên heap
char *copy_string(const char *s) {
    char *copy = malloc(strlen(s));
    strcpy(copy, s);
    return copy;
}

// Tạo mảng n phần tử: phần tử thứ i bằng i * i
int *make_squares(int n) {
    int *a = malloc(n * sizeof(int));
    for (int i = 1; i < n; i++)
        a[i] = i * i;
    return a;
}

int main() {
    char *name = copy_string("Programming 1");
    printf("name = %s\n", name);

    int *squares = make_squares(5);
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += squares[i];
    if (sum > 0)
        printf("sum of squares = %d\n", sum);

    free(squares);
    printf("first square = %d\n", squares[1]);

    return 0;
}
