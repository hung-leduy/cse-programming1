#include <stdio.h>
#include <stdlib.h>

// Represent a multi-dimensional array with:
//  - a 1D array for the flattened data
//  - a 1D array for the shape
// Like numpy: np.arange(12).reshape(3, 2, 2)
struct MultiArray {
    int *data;  // 1D array holding the data
    int *shape; // size of each dimension
    int n_dims; // number of dimensions
};

// Convert a multi-dimensional index into a flat-array index
// Example: shape = [3, 4]: array[i][j] -> data[i * 4 + j]
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

// Visit every element by "counting" (like an odometer):
// increment the last index; on overflow reset it to 0 and carry into the previous dimension
int next_index(int *indexes, int *shape, int n_dims) {
    for (int i = n_dims - 1; i >= 0; i--) {
        if (++indexes[i] < shape[i])
            return 1;
        indexes[i] = 0;
    }
    return 0; // all elements visited
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
