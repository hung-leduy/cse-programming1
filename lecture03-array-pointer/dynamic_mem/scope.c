#include <stdio.h>
#include <stdlib.h>

int global_counter = 0; // biến toàn cục: dùng được ở mọi hàm

// SAI: trả về địa chỉ biến cục bộ (nằm trên stack), biến bị huỷ khi hàm kết thúc
// int *bad_array(void) {
//     int local[3] = {1, 2, 3};
//     return local;
// }

// ĐÚNG: mảng cấp phát trên heap tồn tại tới khi free
int *good_array(void) {
    int *heap = malloc(3 * sizeof(int));
    heap[0] = 1;
    heap[1] = 2;
    heap[2] = 3;
    return heap;
}

void increase(void) {
    int local = 0; // biến cục bộ: tạo mới mỗi lần gọi hàm
    local++;
    global_counter++;
    printf("local = %d, global_counter = %d\n", local, global_counter);
}

int main() {
    increase();
    increase();

    {
        int x = 5; // x chỉ tồn tại trong khối {} này
        printf("x = %d\n", x);
    }
    // printf("%d", x); // lỗi: x ngoài phạm vi

    int *a = good_array();
    printf("%d %d %d\n", a[0], a[1], a[2]);
    free(a);
    return 0;
}
