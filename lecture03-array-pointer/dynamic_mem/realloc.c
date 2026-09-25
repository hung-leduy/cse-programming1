#include <stdio.h>
#include <stdlib.h>

// Mảng động tự tăng kích thước khi đầy
int main() {
    int capacity = 2, size = 0;
    int *arr = malloc(capacity * sizeof(int));

    for (int i = 1; i <= 10; i++) {
        if (size == capacity) {
            capacity *= 2;
            int *tmp = realloc(arr, capacity * sizeof(int));
            if (tmp == NULL) { // realloc lỗi: arr cũ vẫn còn, phải free
                free(arr);
                return 1;
            }
            arr = tmp;
            printf("realloc -> capacity = %d\n", capacity);
        }
        arr[size++] = i * i;
    }

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
