#include <stdio.h>
#include <stdlib.h>

// Cấp phát mảng n chiều bằng đệ quy, trả về (void *)
// shape: kích thước từng chiều, n_dims: số chiều
void *alloc_nd(int *shape, int n_dims) {
    if (n_dims == 1)
        return calloc(shape[0], sizeof(int)); // chiều cuối: mảng int
    void **a = malloc(shape[0] * sizeof(void *));
    for (int i = 0; i < shape[0]; i++)
        a[i] = alloc_nd(shape + 1, n_dims - 1); // cấp phát các chiều còn lại
    return a;
}

void free_nd(void *a, int *shape, int n_dims) {
    if (n_dims > 1) {
        void **p = a;
        for (int i = 0; i < shape[0]; i++)
            free_nd(p[i], shape + 1, n_dims - 1);
    }
    free(a);
}

int main() {
    int shape[] = {2, 3, 4};
    int ***a = alloc_nd(shape, 3); // ép (void *) thành int *** cho mảng 3 chiều

    int value = 0;
    for (int i = 0; i < shape[0]; i++)
        for (int j = 0; j < shape[1]; j++)
            for (int k = 0; k < shape[2]; k++)
                a[i][j][k] = value++;

    printf("a[1][2][3] = %d\n", a[1][2][3]); // 23
    free_nd(a, shape, 3);
    return 0;
}
