// Lab 3 — Con trỏ và bộ nhớ động
// Biên dịch và chạy:  gcc -Wall -Wextra -g lab03.c -o lab03 && ./lab03
// Kiểm tra bộ nhớ:    valgrind --leak-check=full ./lab03
// Nhiệm vụ: cài đặt các hàm có đánh dấu TODO cho đến khi tất cả đều PASS
//           và valgrind báo 0 errors, không rò rỉ.
#include <stdio.h>
#include <stdlib.h>
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

static int same_array(const int *a, const int *b, int n) {
    if (a == NULL || b == NULL)
        return 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
// ---------------------------------------------------------------------------

// 3.1 Hoán đổi giá trị hai biến
void swap(int *a, int *b) {
    // TODO
    (void)a; (void)b;
}

// 3.2 Tìm min và max của mảng (n >= 1), trả về qua con trỏ
void min_max(const int *a, int n, int *min, int *max) {
    // TODO
    (void)a; (void)n; (void)min; (void)max;
}

// 3.3 Tổng mảng. KHÔNG dùng a[i]; chỉ dùng *p và p++ (hoặc *(a + i))
int sum_pointer(const int *a, int n) {
    // TODO
    (void)a; (void)n;
    return -1;
}

// 3.4 Trả về bản sao của mảng, cấp phát trên heap (người gọi sẽ free)
int *copy_array(const int *a, int n) {
    // TODO: malloc(n * sizeof(int)), kiểm tra NULL, chép từng phần tử
    (void)a; (void)n;
    return NULL;
}

// 3.5 Trả về mảng mới chỉ gồm các số chẵn của a (giữ nguyên thứ tự).
//     Số phần tử của mảng kết quả ghi vào *returnSize.
int *filter_even(const int *a, int n, int *returnSize) {
    // TODO
    (void)a; (void)n;
    *returnSize = 0;
    return NULL;
}

// 3.6 Tự cài đặt strdup: trả về bản sao của chuỗi s trên heap
char *my_strdup(const char *s) {
    // TODO: đếm độ dài, malloc(độ dài + 1) — vì sao +1?
    (void)s;
    return NULL;
}

// 3.7 Thêm value vào cuối mảng động arr.
//     *size: số phần tử hiện có; *capacity: số phần tử đã cấp phát.
//     Nếu đầy (*size == *capacity): nhân đôi capacity bằng realloc
//     (nếu *capacity == 0 thì cấp phát 1 phần tử).
//     Trả về con trỏ tới mảng (có thể đã thay đổi sau realloc).
int *push_back(int *arr, int *size, int *capacity, int value) {
    // TODO
    (void)size; (void)capacity; (void)value;
    return arr;
}

// 3.8 Cấp phát ma trận rows x cols bằng int ** (Lecture 7), khởi tạo toàn 0
int **alloc_matrix(int rows, int cols) {
    // TODO: 1 lần malloc cho mảng con trỏ hàng + rows lần calloc cho từng hàng
    (void)rows; (void)cols;
    return NULL;
}

// 3.8 Giải phóng ma trận: từng hàng trước, mảng con trỏ sau
void free_matrix(int **m, int rows) {
    // TODO
    (void)m; (void)rows;
}

// 3.9 Cấp phát một int trên heap, gán giá trị value, và "trả về" qua tham số p
//     (sửa lỗi của out-of-scope-allocation_1.c)
void allocate_int(int **p, int value) {
    // TODO
    (void)p; (void)value;
}

int main() {
    printf("3.1 swap\n");
    int x = 1, y = 2;
    swap(&x, &y);
    CHECK(x == 2 && y == 1);

    printf("3.2 min_max\n");
    int a2[] = {4, -7, 9, 0, 3};
    int mn = 0, mx = 0;
    min_max(a2, 5, &mn, &mx);
    CHECK(mn == -7 && mx == 9);

    printf("3.3 sum_pointer\n");
    CHECK(sum_pointer(a2, 5) == 9);
    CHECK(sum_pointer(a2, 0) == 0);

    printf("3.4 copy_array\n");
    int *c = copy_array(a2, 5);
    CHECK(c != NULL && c != a2 && same_array(c, a2, 5));
    free(c);

    printf("3.5 filter_even\n");
    int a5[] = {1, 2, 3, 4, 6, 7}, e5[] = {2, 4, 6};
    int n5 = -1;
    int *ev = filter_even(a5, 6, &n5);
    CHECK(n5 == 3 && same_array(ev, e5, 3));
    free(ev);

    printf("3.6 my_strdup\n");
    const char *orig = "Programming 1";
    char *dup = my_strdup(orig);
    CHECK(dup != NULL && dup != orig && strcmp(dup, orig) == 0);
    free(dup);

    printf("3.7 push_back\n");
    int *arr = NULL, size = 0, capacity = 0;
    for (int i = 1; i <= 10; i++)
        arr = push_back(arr, &size, &capacity, i * 10);
    int e7[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    CHECK(size == 10);
    CHECK(capacity == 16);
    CHECK(same_array(arr, e7, 10));
    free(arr);

    printf("3.8 alloc_matrix\n");
    int **m = alloc_matrix(3, 4);
    int ok = m != NULL;
    for (int i = 0; ok && i < 3; i++)
        for (int j = 0; j < 4; j++)
            ok = ok && m[i][j] == 0;
    CHECK(ok);
    if (m != NULL) {
        m[2][3] = 42;
        CHECK(m[2][3] == 42);
        free_matrix(m, 3);
    }

    printf("3.9 allocate_int\n");
    int *p = NULL;
    allocate_int(&p, 42);
    CHECK(p != NULL && *p == 42);
    free(p);

    printf("\nKết quả: %d/%d PASS\n", passed, total);
    return passed == total ? 0 : 1;
}
