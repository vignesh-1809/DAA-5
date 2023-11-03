#include <stdio.h>

void find_min_and_second_min(int arr[], int size, int *min, int *second_min) {
    if (size < 2) {
        // The array must have at least two elements.
        return;
    }

    // Initialize min and second_min with the first two elements of the array.
    if (arr[0] < arr[1]) {
        *min = arr[0];
        *second_min = arr[1];
    } else {
        *min = arr[1];
        *second_min = arr[0];
    }

    // Traverse the array, comparing elements in pairs to find the minimum and second minimum.
    for (int i = 2; i < size; i += 2) {
        if (arr[i] < arr[i + 1]) {
            if (arr[i] < *min) {
                *second_min = *min;
                *min = arr[i];
            } else if (arr[i] < *second_min) {
                *second_min = arr[i];
            }
        } else {
            if (arr[i + 1] < *min) {
                *second_min = *min;
                *min = arr[i + 1];
            } else if (arr[i + 1] < *second_min) {
                *second_min = arr[i + 1];
            }
        }
    }

    // If the array size is odd, compare the last element with the minimum and second minimum.
    if (size % 2 == 1) {
        if (arr[size - 1] < *min) {
            *second_min = *min;
            *min = arr[size - 1];
        } else if (arr[size - 1] < *second_min) {
            *second_min = arr[size - 1];
        }
    }
}

int main() {
    int size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int min, second_min;
    find_min_and_second_min(arr, size, &min, &second_min);

    printf("Minimum: %d\n", min);
    printf("Second Minimum: %d\n", second_min);

    return 0;
}
