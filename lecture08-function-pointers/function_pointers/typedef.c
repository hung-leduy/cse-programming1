#include <stdio.h>
#include <stdlib.h>

// typedef <kiểu> <tên mới>;
struct fraction {
    int numerator;
    int denominator;
};
typedef struct fraction Fraction;

struct treenode {
    int data;
    struct treenode *left, *right;
};
typedef struct treenode *Tree; // Tree là con trỏ tới struct treenode

typedef int (*fp)(int, int); // fp là kiểu con trỏ hàm int (*)(int, int)

int add(int a, int b) { return a + b; }

int apply(fp f, int a, int b) { return f(a, b); }

int main() {
    Fraction f = {22, 7}; // không cần viết "struct fraction"
    printf("%d/%d\n", f.numerator, f.denominator);

    Tree t = malloc(sizeof(struct treenode));
    t->data = 1;
    t->left = t->right = NULL;
    printf("root = %d\n", t->data);
    free(t);

    fp op = add;
    printf("apply(add, 2, 3) = %d\n", apply(op, 2, 3));
    return 0;
}
