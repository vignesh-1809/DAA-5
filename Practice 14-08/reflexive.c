#include <stdio.h>

void generateReflexiveRelations(int relation[], int n, int index) {
    if (index == n) {
        printf("{ ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j && relation[i * n + j] == 1) {
                    printf("(%d,%d) ", i + 1, j + 1);
                }
            }
        }
        printf("}\n");
        return;
    }


    relation[index * n + index] = 1;
    generateReflexiveRelations(relation, n, index + 1);


    relation[index * n + index] = 0;
    generateReflexiveRelations(relation, n, index + 1);
}

int main() {
    int n;
    printf("Enter the size of the set: ");
    scanf("%d", &n);

    int relation[n * n];
    for (int i = 0; i < n * n; i++) {
        relation[i] = 0;
    }

    generateReflexiveRelations(relation, n, 0);

    return 0;
}
