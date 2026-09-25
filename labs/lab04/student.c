// Lab 4 — Student management module: IMPLEMENTATION
// Task: implement the functions marked TODO. Run "make test" to check.
#include <stdlib.h>
#include <string.h>
#include "student.h"

// ===================== 4.1 Struct =====================

// Create a Student. Names longer than MAX_NAME - 1 characters are truncated
// (hint: strncpy then set '\0' at the end yourself, or use snprintf).
Student make_student(int id, const char *name, float gpa) {
    Student s = {0};
    // TODO
    (void)id; (void)name; (void)gpa;
    return s;
}

// Print one line in the form:  "  1001  Nguyen Van An                  3.45"
void print_student(const Student *s) {
    printf("%6d  %-30s %.2f\n", s->id, s->name, s->gpa);
}

// ===================== 4.2 Linked list =====================

// Insert at the front of the list, return the new head
Node *list_push_front(Node *head, Student s) {
    // TODO: malloc a Node, set data and next, return the new node
    (void)s;
    return head;
}

// Insert at the end of the list, return head (changes if the list was empty)
Node *list_push_back(Node *head, Student s) {
    // TODO
    (void)s;
    DEBUG_PRINT("push_back id=%d", s.id);
    return head;
}

// Number of elements
int list_length(const Node *head) {
    // TODO
    (void)head;
    return -1;
}

// Find by id; return a pointer to the Student in the list (so it can be modified), or NULL
Student *list_find(Node *head, int id) {
    // TODO
    (void)head; (void)id;
    return NULL;
}

// Remove the first node with the matching id (remember to free it), return the new head.
// If the id is not found, leave the list unchanged.
Node *list_remove(Node *head, int id) {
    // TODO: handle removing the head node as a special case
    (void)id;
    return head;
}

// Print the whole list
void list_print(const Node *head) {
    for (const Node *p = head; p != NULL; p = p->next)
        print_student(&p->data);
}

// Free the whole list
void list_free(Node *head) {
    // TODO: save next BEFORE freeing the current node
    (void)head;
}

// ===================== 4.3 Function pointers =====================

// Comparison functions for qsort: a, b are pointers to Student.
// Return < 0 if a comes before b, 0 if equal, > 0 if a comes after b.

int compare_by_id(const void *a, const void *b) {
    const Student *x = a, *y = b;
    return x->id - y->id; // example
}

int compare_by_name(const void *a, const void *b) {
    // TODO: use strcmp
    (void)a; (void)b;
    return 0;
}

// GPA in descending order (higher GPA first). Careful: gpa is a float, do not return x->gpa - y->gpa!
int compare_by_gpa_desc(const void *a, const void *b) {
    // TODO
    (void)a; (void)b;
    return 0;
}

// Copy at most max elements of the list into the array out, return the number copied
int list_to_array(const Node *head, Student out[], int max) {
    // TODO
    (void)head; (void)out; (void)max;
    return 0;
}

// Sort the array using the comparison function cmp
void sort_students(Student arr[], int n, StudentCompare cmp) {
    // TODO: call qsort
    (void)arr; (void)n; (void)cmp;
}

// Excellent student: gpa >= 3.6
int is_excellent(const Student *s) {
    // TODO
    (void)s;
    return 0;
}

// Count the students that satisfy pred
int count_if(const Node *head, StudentPredicate pred) {
    // TODO: call pred(&p->data) for each node
    (void)head; (void)pred;
    return -1;
}
