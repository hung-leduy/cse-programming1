#include <stdio.h>

int main() {
    // Mảng ký tự: chứa tối đa 49 ký tự + ký tự kết thúc '\0'
    char str[50] = "Hello, World!";
    str[0] = 'h'; // được phép sửa

    // Con trỏ tới chuỗi hằng (string literal): KHÔNG được sửa
    const char *literal = "Hello, World!";
    // literal[0] = 'h'; // lỗi / hành vi không xác định

    printf("%s\n%s\n", str, literal);

    // Chuỗi luôn kết thúc bằng '\0'
    char s[] = "abc"; // tương đương {'a', 'b', 'c', '\0'}
    printf("sizeof(s) = %zu\n", sizeof(s)); // 4
    for (int i = 0; s[i] != '\0'; i++)
        printf("s[%d] = '%c' (%d)\n", i, s[i], s[i]);
    return 0;
}
