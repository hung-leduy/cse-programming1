#include <stdio.h>

int main() {
    char variable = 'a'; // 97

    float value1 = variable / 5;          // 19.0: chia nguyên rồi mới chuyển sang float
    float value2 = (float)variable / 5;   // 19.4: ép kiểu trước khi chia
    printf("value1 = %f, value2 = %f\n", value1, value2);

    // Mất độ chính xác (truncation) khi gán số thực cho số nguyên
    double pi = 3.14159;
    int truncated = pi; // 3
    printf("truncated = %d\n", truncated);

    // Tràn (overflow) khi gán số lớn cho kiểu nhỏ
    int big = 300;
    char small = big; // chỉ giữ lại 8 bit thấp
    printf("small = %d\n", small);
    return 0;
}
