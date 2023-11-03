#include <stdio.h>

int find(int arr[], int size) {
    if (size < 3) {
        return -1;
    }

    int min_val = arr[0];
    int max_val = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] != min_val && arr[i] != max_val) {
            return arr[i];
        }
    }

    return -1;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = find(arr, n);
    if (result != -1) {
        printf("The number found is: %d\n", result);
    } else {
        printf("No number found\n");
    }

    return 0;
}
