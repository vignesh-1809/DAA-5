#include <stdio.h>

int searchInMatrix(int matrix[100][100], int n, int x) {
    int row = 0;
    int col = n - 1;

    while (row < n && col >= 0) {
        if (matrix[row][col] == x) {
            // Element found
            printf("Element %d found at position (%d, %d)\n", x, row, col);
            return 1; 
        } else if (matrix[row][col] > x) {
            
            col--;
        } else {
            row++;
        }
    }

    printf("Element %d not found in the matrix.\n", x);
    return 0;
}

int main() {
    int n, x;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int matrix[100][100];
    printf("Enter the elements of the %d x %d matrix (in increasing order):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the element to search for: ");
    scanf("%d", &x);

    searchInMatrix(matrix, n, x);

    return 0;
}
