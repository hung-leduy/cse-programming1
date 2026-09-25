// Lab 4 — Module quản lý sinh viên: phần CÀI ĐẶT (implementation)
// Nhiệm vụ: cài đặt các hàm có đánh dấu TODO. Chạy "make test" để kiểm tra.
#include <stdlib.h>
#include <string.h>
#include "student.h"

// ===================== 4.1 Struct =====================

// Tạo một Student. Tên dài hơn MAX_NAME - 1 ký tự thì cắt bớt
// (gợi ý: strncpy rồi tự đặt '\0' ở cuối, hoặc snprintf).
Student make_student(int id, const char *name, float gpa) {
    Student s = {0};
    // TODO
    (void)id; (void)name; (void)gpa;
    return s;
}

// In một dòng dạng:  "  1001  Nguyen Van An                  3.45"
void print_student(const Student *s) {
    printf("%6d  %-30s %.2f\n", s->id, s->name, s->gpa);
}

// ===================== 4.2 Danh sách liên kết =====================

// Thêm vào đầu danh sách, trả về head mới
Node *list_push_front(Node *head, Student s) {
    // TODO: malloc một Node, gán data và next, trả về nút mới
    (void)s;
    return head;
}

// Thêm vào cuối danh sách, trả về head (thay đổi nếu danh sách đang rỗng)
Node *list_push_back(Node *head, Student s) {
    // TODO
    (void)s;
    DEBUG_PRINT("push_back id=%d", s.id);
    return head;
}

// Số phần tử
int list_length(const Node *head) {
    // TODO
    (void)head;
    return -1;
}

// Tìm theo id; trả về con trỏ tới Student trong danh sách (để sửa được), hoặc NULL
Student *list_find(Node *head, int id) {
    // TODO
    (void)head; (void)id;
    return NULL;
}

// Xoá nút đầu tiên có id tương ứng (nhớ free), trả về head mới.
// Không có id đó thì giữ nguyên danh sách.
Node *list_remove(Node *head, int id) {
    // TODO: xét riêng trường hợp xoá nút đầu
    (void)id;
    return head;
}

// In toàn bộ danh sách
void list_print(const Node *head) {
    for (const Node *p = head; p != NULL; p = p->next)
        print_student(&p->data);
}

// Giải phóng toàn bộ danh sách
void list_free(Node *head) {
    // TODO: lưu next TRƯỚC khi free nút hiện tại
    (void)head;
}

// ===================== 4.3 Con trỏ hàm =====================

// Các hàm so sánh cho qsort: a, b là con trỏ tới Student.
// Trả về < 0 nếu a đứng trước b, 0 nếu bằng nhau, > 0 nếu a đứng sau b.

int compare_by_id(const void *a, const void *b) {
    const Student *x = a, *y = b;
    return x->id - y->id; // ví dụ mẫu
}

int compare_by_name(const void *a, const void *b) {
    // TODO: dùng strcmp
    (void)a; (void)b;
    return 0;
}

// GPA giảm dần (GPA cao đứng trước). Cẩn thận: gpa là float, không trả về x->gpa - y->gpa!
int compare_by_gpa_desc(const void *a, const void *b) {
    // TODO
    (void)a; (void)b;
    return 0;
}

// Chép tối đa max phần tử của danh sách vào mảng out, trả về số phần tử đã chép
int list_to_array(const Node *head, Student out[], int max) {
    // TODO
    (void)head; (void)out; (void)max;
    return 0;
}

// Sắp xếp mảng theo hàm so sánh cmp
void sort_students(Student arr[], int n, StudentCompare cmp) {
    // TODO: gọi qsort
    (void)arr; (void)n; (void)cmp;
}

// Sinh viên xuất sắc: gpa >= 3.6
int is_excellent(const Student *s) {
    // TODO
    (void)s;
    return 0;
}

// Đếm số sinh viên thoả điều kiện pred
int count_if(const Node *head, StudentPredicate pred) {
    // TODO: gọi pred(&p->data) cho từng nút
    (void)head; (void)pred;
    return -1;
}
