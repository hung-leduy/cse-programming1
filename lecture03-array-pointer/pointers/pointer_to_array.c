#include <stdio.h>

int main() {
    int scores[5] = {10, 20, 30, 40, 50};
    int *p_scores = scores; // tên mảng chính là con trỏ tới phần tử đầu tiên

    printf("scores     = %p\n", (void *)scores);
    printf("&scores[0] = %p\n", (void *)&scores[0]);

    // Truy cập bằng chỉ số với con trỏ giống như với mảng
    printf("p_scores[2] = %d, *(p_scores + 2) = %d\n", p_scores[2], *(p_scores + 2));

    // Tên mảng là "hằng" con trỏ: không thể gán lại
    // scores = p_scores;  // lỗi biên dịch
    // scores++;           // lỗi biên dịch
    p_scores++; // nhưng biến con trỏ thì được
    printf("*p_scores = %d\n", *p_scores); // 20
    return 0;
}
