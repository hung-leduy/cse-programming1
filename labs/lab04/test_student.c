// Lab 4 - Tests for the student module (no need to modify)
//   make test       run the tests
//   make debug      run the tests with DEBUG_PRINT enabled
//   make valgrind   check for memory leaks
#include <stdlib.h>
#include <string.h>
#include "student.h"

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

static int at_least_2(const Student *s) { return s->gpa >= 2.0f; }

int main() {
    printf("4.1 make_student\n");
    Student an = make_student(1003, "Nguyen Van An", 3.45f);
    CHECK(an.id == 1003 && strcmp(an.name, "Nguyen Van An") == 0 && an.gpa == 3.45f);
    Student longname = make_student(1, "Very long name very long name very long name very long name", 2.0f);
    CHECK(strlen(longname.name) == MAX_NAME - 1);

    printf("4.2 linked list\n");
    Node *list = NULL;
    CHECK(list_length(list) == 0);
    list = list_push_back(list, an);
    list = list_push_back(list, make_student(1001, "Tran Thi Binh", 3.80f));
    list = list_push_front(list, make_student(1005, "Le Van Cuong", 2.10f));
    list = list_push_back(list, make_student(1002, "Pham Thi Dung", 3.60f));
    list = list_push_back(list, make_student(1004, "Hoang Van Em", 1.90f));
    CHECK(list_length(list) == 5);
    CHECK(list != NULL && list->data.id == 1005);
    CHECK(list != NULL && list->next != NULL && list->next->data.id == 1003);

    Student *found = list_find(list, 1002);
    CHECK(found != NULL && strcmp(found->name, "Pham Thi Dung") == 0);
    CHECK(list_find(list, 9999) == NULL);
    if (found != NULL)
        found->gpa = 3.65f; // modify directly in the list
    CHECK(list_find(list, 1002) != NULL && list_find(list, 1002)->gpa == 3.65f);

    list = list_remove(list, 1005); // remove the head node
    list = list_remove(list, 1002); // remove a middle node
    list = list_remove(list, 1004); // remove the tail node
    list = list_remove(list, 9999); // not present
    CHECK(list_length(list) == 2);
    CHECK(list != NULL && list->data.id == 1003);
    CHECK(list_find(list, 1002) == NULL);

    list = list_push_back(list, make_student(1006, "Vo Thi Giang", 3.90f));
    list = list_push_back(list, make_student(1007, "Dang Van Hai", 2.50f));
    printf("\nCurrent list:\n");
    list_print(list);
    printf("\n");

    printf("4.3 function pointers\n");
    Student arr[10];
    int n = list_to_array(list, arr, 10);
    CHECK(n == 4);
    CHECK(list_to_array(list, arr, 2) == 2);
    n = list_to_array(list, arr, 10);

    sort_students(arr, n, compare_by_id);
    CHECK(n == 4 && arr[0].id == 1001 && arr[3].id == 1007);
    sort_students(arr, n, compare_by_name);
    CHECK(n == 4 && strcmp(arr[0].name, "Dang Van Hai") == 0 && strcmp(arr[3].name, "Vo Thi Giang") == 0);
    sort_students(arr, n, compare_by_gpa_desc);
    CHECK(n == 4 && arr[0].id == 1006 && arr[1].id == 1001 && arr[2].id == 1003 && arr[3].id == 1007);

    CHECK(count_if(list, is_excellent) == 2);
    CHECK(count_if(list, at_least_2) == 4);

    list_free(list);

    printf("\nResult: %d/%d PASS\n", passed, total);
    return passed == total ? 0 : 1;
}
