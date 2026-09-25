#include <stdio.h>

int convert(char var) {
    return var - '0';
}

// Bài tập 2: atoi (ASCII to integer)
// Đặt tên my_atoi để tránh trùng với hàm atoi của <stdlib.h>
int my_atoi(char s[], int size) {
    int num = 0;
    for (int i = 0; i < size; i++) {
        num = 10 * num + convert(s[i]);
    }
    return num;
}

int main() {
    char s[] = {'1', '2', '3', '4'};
    int converted_value = my_atoi(s, 4); // 1234
    printf("%d\n", converted_value);
    return 0;
}
