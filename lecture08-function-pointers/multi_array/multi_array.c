#include <stdio.h>
#include <stdlib.h>

// Biểu diễn mảng nhiều chiều bằng:
//  - mảng 1 chiều cho dữ liệu đã "làm phẳng" (flattened)
//  - mảng 1 chiều cho hình dạng (shape)
// Giống numpy: np.arange(12).reshape(3, 2, 2)
struct MultiArray {
    int *data;  // mảng 1 chiều chứa dữ liệu
    int *shape; // kích thước từng chiều
    int n_dims; // số chiều
};

// Chuyển chỉ số nhiều chiều thành chỉ số của mảng phẳng
// Ví dụ shape = [3, 4]: array[i][j] -> data[i * 4 + j]
int get_flat_index(struct MultiArray *array, int *indexes) {
    int flat_index = 0;
    int cumul_shape = 1;
    for (int i = array->n_dims - 1; i >= 0; i--) {
        flat_index += indexes[i] * cumul_shape;
        cumul_shape *= array->shape[i];
    }
    return flat_index;
}

int get_data(struct MultiArray *array, int *indexes) {
    return array->data[get_flat_index(array, indexes)];
}

// Duyệt mọi phần tử theo kiểu "đếm" (như đồng hồ đo km):
// tăng chỉ số cuối, khi tràn thì đặt lại 0 và nhớ sang chiều trước
int next_index(int *indexes, int *shape, int n_dims) {
    for (int i = n_dims - 1; i >= 0; i--) {
        if (++indexes[i] < shape[i])
            return 1;
        indexes[i] = 0;
    }
    return 0; // đã duyệt hết
}

int main() {
    int shape[] = {3, 2, 2};
    struct MultiArray arr = {malloc(12 * sizeof(int)), shape, 3};
    for (int i = 0; i < 12; i++)
        arr.data[i] = i; // np.arange(12)

    int idx[] = {1, 0, 1};
    printf("array[1][0][1] -> data[%d] = %d\n", get_flat_index(&arr, idx), get_data(&arr, idx));

    int it[] = {0, 0, 0};
    do {
        printf("array[%d][%d][%d] = %d\n", it[0], it[1], it[2], get_data(&arr, it));
    } while (next_index(it, shape, 3));

    free(arr.data);
    return 0;
}
