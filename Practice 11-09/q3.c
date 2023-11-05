#include <stdio.h>

void sortTernaryArray(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
                break;

            case 1:
                mid++;
                break;

            case 2:
                temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
                break;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the ternary array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the ternary array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sortTernaryArray(arr, n);

    printf("Sorted ternary array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
