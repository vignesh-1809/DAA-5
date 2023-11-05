#include <stdio.h>

void generateSubsets(int set[], int subset[], int n, int index) {
    if (index == n) {
        printf("{ ");
        for (int i = 0; i < n; i++) {
            if (subset[i] == 1) {
                printf("%d ", set[i]);
            }
        }
        printf("}\n");
        return;
    }

    subset[index] = 1;
    generateSubsets(set, subset, n, index + 1);

    subset[index] = 0;
    generateSubsets(set, subset, n, index + 1);
}

int main() {
    int n;
    printf("Enter the size of the set: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    int subset[n];
    generateSubsets(set, subset, n, 0);

    return 0;
}

