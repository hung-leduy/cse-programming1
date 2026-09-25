// Lab 2 — Mảng và chuỗi
// Biên dịch và chạy:  gcc -Wall -Wextra -g lab02.c -o lab02 && ./lab02
// Nhiệm vụ: cài đặt các hàm có đánh dấu TODO cho đến khi tất cả đều PASS.
#include <stdio.h>
#include <string.h> // chỉ dùng trong main để kiểm tra

// ---------------------------------------------------------------------------
// Khung kiểm tra đơn giản (không cần sửa)
static int passed = 0, total = 0;
#define CHECK(expr)                                 \
    do {                                            \
        total++;                                    \
        if (expr) {                                 \
            passed++;                               \
            printf("  PASS  %s\n", #expr);          \
        } else {                                    \
            printf("  FAIL  %s\n", #expr);          \
        }                                           \
    } while (0)

static int same_array(const int a[], const int b[], int n) {
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
// ---------------------------------------------------------------------------

#define ROWS 3
#define COLS 4

// 2.1 Giá trị lớn nhất của mảng (n >= 1)
int array_max(int a[], int n) {
    // TODO: lưu ý mảng có thể toàn số âm
    (void)a; (void)n;
    return -1;
}

// 2.2 Trung bình cộng (n >= 1)
double array_mean(int a[], int n) {
    // TODO: cẩn thận phép chia nguyên
    (void)a; (void)n;
    return -1;
}

// 2.3 Đảo ngược mảng tại chỗ: {1, 2, 3} -> {3, 2, 1}
void reverse_array(int a[], int n) {
    // TODO: hoán đổi a[i] và a[n - 1 - i]; chỉ cần đi đến giữa mảng
    (void)a; (void)n;
}

// 2.4 Số lần xuất hiện của value trong mảng
int count_value(int a[], int n, int value) {
    // TODO
    (void)a; (void)n; (void)value;
    return -1;
}

// 2.5 Max theo trục (Lecture 3):
//   axis = 0: max của từng CỘT -> out có COLS phần tử
//   axis = 1: max của từng HÀNG -> out có rows phần tử
void max_2d(int a[][COLS], int rows, int axis, int out[]) {
    // TODO
    (void)a; (void)rows; (void)axis; (void)out;
}

// 2.6 Nhân ma trận: C = A x B, với A là 2x3, B là 3x2, C là 2x2
void matmul(int A[2][3], int B[3][2], int C[2][2]) {
    // TODO: C[i][j] = tổng theo k của A[i][k] * B[k][j]
    (void)A; (void)B; (void)C;
}

// 2.7 Tự cài đặt strlen (KHÔNG dùng <string.h>)
int my_strlen(const char s[]) {
    // TODO: đếm tới khi gặp '\0'
    (void)s;
    return -1;
}

// 2.8 Đổi chữ thường thành chữ hoa tại chỗ, giữ nguyên các ký tự khác
void to_upper(char s[]) {
    // TODO: 'a' - 'A' == 32 (bảng ASCII)
    (void)s;
}

// 2.9 Trả về 1 nếu s là chuỗi đối xứng ("racecar", "abba", ""), ngược lại 0
int is_palindrome(const char s[]) {
    // TODO
    (void)s;
    return -1;
}

// 2.10 Đếm số từ; các từ cách nhau bởi một hoặc nhiều dấu cách ' '
//      "  hello   world " -> 2
int count_words(const char s[]) {
    // TODO: đếm số lần "bắt đầu một từ": ký tự khác ' ' mà đứng trước là ' ' (hoặc đầu chuỗi)
    (void)s;
    return -1;
}

int main() {
    printf("2.1 array_max\n");
    int a1[] = {3, 9, -2, 7};
    int neg[] = {-5, -3, -8};
    CHECK(array_max(a1, 4) == 9);
    CHECK(array_max(neg, 3) == -3);

    printf("2.2 array_mean\n");
    int a2[] = {1, 2, 3, 4};
    CHECK(array_mean(a2, 4) == 2.5);
    CHECK(array_mean(neg, 3) > -5.34 && array_mean(neg, 3) < -5.33);

    printf("2.3 reverse_array\n");
    int r1[] = {1, 2, 3, 4, 5}, e1[] = {5, 4, 3, 2, 1};
    int r2[] = {1, 2, 3, 4}, e2[] = {4, 3, 2, 1};
    reverse_array(r1, 5);
    reverse_array(r2, 4);
    CHECK(same_array(r1, e1, 5));
    CHECK(same_array(r2, e2, 4));

    printf("2.4 count_value\n");
    int a4[] = {1, 2, 1, 3, 1};
    CHECK(count_value(a4, 5, 1) == 3);
    CHECK(count_value(a4, 5, 9) == 0);

    printf("2.5 max_2d\n");
    int m[ROWS][COLS] = {{1, 8, 3, 4}, {5, 2, 7, 0}, {9, 6, 1, 2}};
    int cols[COLS] = {0}, rows[ROWS] = {0};
    int ecols[] = {9, 8, 7, 4}, erows[] = {8, 7, 9};
    max_2d(m, ROWS, 0, cols);
    max_2d(m, ROWS, 1, rows);
    CHECK(same_array(cols, ecols, COLS));
    CHECK(same_array(rows, erows, ROWS));

    printf("2.6 matmul\n");
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2] = {{0}};
    matmul(A, B, C);
    CHECK(C[0][0] == 58 && C[0][1] == 64);
    CHECK(C[1][0] == 139 && C[1][1] == 154);

    printf("2.7 my_strlen\n");
    CHECK(my_strlen("") == 0);
    CHECK(my_strlen("hello") == 5);

    printf("2.8 to_upper\n");
    char s8[] = "Hello, World 2024!";
    to_upper(s8);
    CHECK(strcmp(s8, "HELLO, WORLD 2024!") == 0);

    printf("2.9 is_palindrome\n");
    CHECK(is_palindrome("racecar") == 1);
    CHECK(is_palindrome("abba") == 1);
    CHECK(is_palindrome("") == 1);
    CHECK(is_palindrome("abca") == 0);

    printf("2.10 count_words\n");
    CHECK(count_words("hello world") == 2);
    CHECK(count_words("  hello   world ") == 2);
    CHECK(count_words("") == 0);
    CHECK(count_words("   ") == 0);
    CHECK(count_words("C") == 1);

    printf("\nKết quả: %d/%d PASS\n", passed, total);
    return passed == total ? 0 : 1;
}
