#include <stdio.h>

// Kích thước (byte) của các kiểu dữ liệu cơ bản: short <= int <= long
int main() {
    printf("char:   %zu byte\n", sizeof(char));
    printf("short:  %zu byte\n", sizeof(short));
    printf("int:    %zu byte\n", sizeof(int));
    printf("long:   %zu byte\n", sizeof(long));
    printf("float:  %zu byte\n", sizeof(float));
    printf("double: %zu byte\n", sizeof(double));
    return 0;
}
