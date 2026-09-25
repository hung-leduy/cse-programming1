#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *new_node(int data) {
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Chèn vào đầu danh sách: O(1)
void push_front(struct node **head, int data) {
    struct node *n = new_node(data);
    n->next = *head;
    *head = n;
}

// Chèn vào cuối danh sách: O(n)
void push_back(struct node **head, int data) {
    struct node *n = new_node(data);
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct node *cur = *head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = n;
}

// Chèn vào vị trí index (0 = đầu danh sách)
void insert_at(struct node **head, int index, int data) {
    if (index == 0) {
        push_front(head, data);
        return;
    }
    struct node *cur = *head;
    for (int i = 0; cur != NULL && i < index - 1; i++)
        cur = cur->next;
    if (cur == NULL)
        return; // index vượt quá độ dài
    struct node *n = new_node(data);
    n->next = cur->next;
    cur->next = n;
}

// Truy cập phần tử thứ index; trả về 1 nếu tìm thấy
int get(struct node *head, int index, int *value) {
    for (int i = 0; head != NULL; i++, head = head->next)
        if (i == index) {
            *value = head->data;
            return 1;
        }
    return 0;
}

// Xoá phần tử đầu tiên có giá trị bằng data
void delete_value(struct node **head, int data) {
    struct node **pp = head; // con trỏ tới "ô" đang trỏ tới node hiện tại
    while (*pp != NULL) {
        if ((*pp)->data == data) {
            struct node *victim = *pp;
            *pp = victim->next;
            free(victim);
            return;
        }
        pp = &(*pp)->next;
    }
}

void print_list(struct node *head) {
    for (; head != NULL; head = head->next)
        printf("%d -> ", head->data);
    printf("NULL\n");
}

// Giải phóng toàn bộ danh sách
void free_list(struct node *head) {
    while (head != NULL) {
        struct node *next = head->next; // lưu next TRƯỚC khi free
        free(head);
        head = next;
    }
}

int main() {
    struct node *head = NULL;
    push_back(&head, 2);
    push_back(&head, 3);
    push_front(&head, 1);
    insert_at(&head, 3, 4);
    print_list(head); // 1 -> 2 -> 3 -> 4 -> NULL

    int v;
    if (get(head, 2, &v))
        printf("list[2] = %d\n", v);

    delete_value(&head, 1);
    delete_value(&head, 3);
    print_list(head); // 2 -> 4 -> NULL

    free_list(head);
    return 0;
}
