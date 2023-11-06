#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int LISS(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int size_excl = LISS(root->left) + LISS(root->right);
    int size_incl = 1;
    if (root->left) {
        size_incl += LISS(root->left->left) + LISS(root->left->right);
    }
    if (root->right) {
        size_incl += LISS(root->right->left) + LISS(root->right->right);
    }
    return (size_incl > size_excl) ? size_incl : size_excl;
}

int main() {
    struct Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printf("Size of the Largest Independent Set is %d\n", LISS(root));

    return 0;
}
