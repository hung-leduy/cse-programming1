#include <stdio.h>
#include <string.h>

int main() {
    char a[50] = "Hello";
    char b[] = "World";

    printf("strlen(a) = %zu\n", strlen(a)); // độ dài, không tính '\0'

    printf("strcmp(a, b) = %d\n", strcmp(a, b) < 0 ? -1 : 1); // < 0: a đứng trước b
    printf("strncmp(\"Hello\", \"Help\", 3) = %d\n", strncmp("Hello", "Help", 3)); // 0

    strcat(a, ", ");          // nối chuỗi: a phải đủ chỗ!
    strncat(a, b, 3);         // nối tối đa 3 ký tự
    printf("a = %s\n", a);    // Hello, Wor

    char c[50];
    strcpy(c, b);             // sao chép chuỗi
    printf("c = %s\n", c);

    char d[4];
    strncpy(d, "abcdef", sizeof(d) - 1); // strncpy không tự thêm '\0' nếu cắt
    d[sizeof(d) - 1] = '\0';
    printf("d = %s\n", d);    // abc

    char *found = strstr(a, "llo"); // tìm chuỗi con
    if (found != NULL)
        printf("\"llo\" ở vị trí %ld\n", found - a);
    return 0;
}
