// Lab 4 — Student management module: DECLARATIONS (interface)
// This file is complete; do NOT modify it. The implementation is in student.c.
#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

#define MAX_NAME 50

// Debug macro: prints only when compiled with -DDEBUG (make debug)
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

// A node of a singly linked list
typedef struct Node {
    Student data;
    struct Node *next;
} Node;

// Function pointer type for comparison (same signature as qsort's comparator)
typedef int (*StudentCompare)(const void *, const void *);

// Function pointer type for filtering: returns 1 if the student meets the condition
typedef int (*StudentPredicate)(const Student *);

// ---- 4.1 Struct ----
Student make_student(int id, const char *name, float gpa);
void print_student(const Student *s);

// ---- 4.2 Linked list ----
// Functions that modify the list return the NEW head pointer:  head = list_push_front(head, s);
Node *list_push_front(Node *head, Student s);
Node *list_push_back(Node *head, Student s);
int list_length(const Node *head);
Student *list_find(Node *head, int id);
Node *list_remove(Node *head, int id);
void list_print(const Node *head);
void list_free(Node *head);

// ---- 4.3 Function pointers ----
int compare_by_id(const void *a, const void *b);
int compare_by_name(const void *a, const void *b);
int compare_by_gpa_desc(const void *a, const void *b);
int list_to_array(const Node *head, Student out[], int max);
void sort_students(Student arr[], int n, StudentCompare cmp);
int is_excellent(const Student *s);
int count_if(const Node *head, StudentPredicate pred);

#endif
