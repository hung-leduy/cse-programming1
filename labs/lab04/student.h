// Lab 4 — Module quản lý sinh viên: phần KHAI BÁO (interface)
// File này đã hoàn chỉnh, KHÔNG cần sửa. Cài đặt nằm trong student.c.
#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

#define MAX_NAME 50

// Macro debug: chỉ in khi biên dịch với -DDEBUG (make debug)
#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...) \
    fprintf(stderr, "[DEBUG] %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...)
#endif

typedef struct Student {
    int id;
    char name[MAX_NAME];
    float gpa;
} Student;

// Một nút của danh sách liên kết đơn
typedef struct Node {
    Student data;
    struct Node *next;
} Node;

// Kiểu con trỏ hàm dùng để so sánh (cùng dạng với tham số của qsort)
typedef int (*StudentCompare)(const void *, const void *);

// Kiểu con trỏ hàm dùng để lọc: trả về 1 nếu sinh viên thoả điều kiện
typedef int (*StudentPredicate)(const Student *);

// ---- 4.1 Struct ----
Student make_student(int id, const char *name, float gpa);
void print_student(const Student *s);

// ---- 4.2 Danh sách liên kết ----
// Các hàm thay đổi danh sách trả về con trỏ head MỚI:  head = list_push_front(head, s);
Node *list_push_front(Node *head, Student s);
Node *list_push_back(Node *head, Student s);
int list_length(const Node *head);
Student *list_find(Node *head, int id);
Node *list_remove(Node *head, int id);
void list_print(const Node *head);
void list_free(Node *head);

// ---- 4.3 Con trỏ hàm ----
int compare_by_id(const void *a, const void *b);
int compare_by_name(const void *a, const void *b);
int compare_by_gpa_desc(const void *a, const void *b);
int list_to_array(const Node *head, Student out[], int max);
void sort_students(Student arr[], int n, StudentCompare cmp);
int is_excellent(const Student *s);
int count_if(const Node *head, StudentPredicate pred);

#endif
