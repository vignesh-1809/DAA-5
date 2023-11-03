#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct HashMapNode {
    int key;
    int value;
};

struct HashMapNode* createHashMapNode(int key, int value) {
    struct HashMapNode* newNode = (struct HashMapNode*)malloc(sizeof(struct HashMapNode));
    newNode->key = key;
    newNode->value = value;
    return newNode;
}
void findDuplicatesAndPrintMultiplicity(int A[], int n) {

    struct HashMapNode** hashMap = (struct HashMapNode**)malloc(n * sizeof(struct HashMapNode*));

    for (int i = 0; i < n; i++) {
        hashMap[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int key = A[i];

        int pos = abs(key) % n;
        while (hashMap[pos] != NULL && hashMap[pos]->key != key) {
            pos = (pos + 1) % n;
        }

        if (hashMap[pos] == NULL) {

            hashMap[pos] = createHashMapNode(key, 1);
        } else {

            hashMap[pos]->value++;
        }
    }


    for (int i = 0; i < n; i++) {
        if (hashMap[i] != NULL && hashMap[i]->value > 1) {
            printf("Duplicate: %d, Multiplicity: %d\n", hashMap[i]->key, hashMap[i]->value);
        }
    }


    for (int i = 0; i < n; i++) {
        free(hashMap[i]);
    }
    free(hashMap);
}

int main() {
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    findDuplicatesAndPrintMultiplicity(A, n);

    return 0;
}
