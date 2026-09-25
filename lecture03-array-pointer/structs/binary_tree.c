#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree
struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
};

struct treenode *insert(struct treenode *root, int data) {
    if (root == NULL) {
        struct treenode *n = malloc(sizeof(struct treenode));
        n->data = data;
        n->left = n->right = NULL;
        return n;
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int contains(struct treenode *root, int data) {
    while (root != NULL) {
        if (data == root->data)
            return 1;
        root = data < root->data ? root->left : root->right;
    }
    return 0;
}

// In-order traversal: prints the values in sorted order
void print_inorder(struct treenode *root) {
    if (root == NULL)
        return;
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

int height(struct treenode *root) {
    if (root == NULL)
        return 0;
    int l = height(root->left), r = height(root->right);
    return 1 + (l > r ? l : r);
}

// Free in post-order: children first, then the parent
void free_tree(struct treenode *root) {
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    struct treenode *root = NULL;
    for (int i = 0; i < 7; i++)
        root = insert(root, values[i]);

    print_inorder(root);
    printf("\nheight = %d\n", height(root));
    printf("contains 60? %d, contains 65? %d\n", contains(root, 60), contains(root, 65));

    free_tree(root);
    return 0;
}
