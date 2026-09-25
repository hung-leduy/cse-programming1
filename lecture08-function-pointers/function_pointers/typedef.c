#include <stdio.h>
#include <stdlib.h>

// typedef <type> <new name>;
struct fraction {
    int numerator;
    int denominator;
};
typedef struct fraction Fraction;

struct treenode {
    int data;
    struct treenode *left, *right;
};
typedef struct treenode *Tree; // Tree is a pointer to struct treenode

typedef int (*fp)(int, int); // fp is the function pointer type int (*)(int, int)

int add(int a, int b) { return a + b; }

int apply(fp f, int a, int b) { return f(a, b); }

int main() {
    Fraction f = {22, 7}; // no need to write "struct fraction"
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
