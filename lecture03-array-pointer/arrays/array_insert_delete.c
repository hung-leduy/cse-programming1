#include <stdio.h>

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

// Insert value at position pos: shift later elements right -> O(n)
// capacity is the maximum number of elements the array can hold
int insert_at(int a[], int n, int capacity, int pos, int value) {
    if (n >= capacity || pos < 0 || pos > n)
        return n;
    for (int i = n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = value;
    return n + 1;
}

// Delete the element at position pos: shift later elements left -> O(n)
int delete_at(int a[], int n, int pos) {
    if (pos < 0 || pos >= n)
        return n;
    for (int i = pos; i < n - 1; i++)
        a[i] = a[i + 1];
    return n - 1;
}

int main() {
    int a[10] = {1, 2, 3, 4, 5};
    int n = 5;
    n = insert_at(a, n, 10, 2, 99);
    print_array(a, n); // 1 2 99 3 4 5
    n = delete_at(a, n, 0);
    print_array(a, n); // 2 99 3 4 5
    return 0;
}
