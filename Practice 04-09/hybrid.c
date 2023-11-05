#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        if (high - low + 1 <= 30) {
            bubbleSort(arr + low, high - low + 1);
        } else {
            int pivot = arr[low];
            int left = low + 1;
            int right = high;

            while (left <= right) {
                while (left <= high && arr[left] < pivot) {
                    left++;
                }

                while (right >= low && arr[right] > pivot) {
                    right--;
                }

                if (left <= right) {
                    int temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;
                    left++;
                    right--;
                }
            }

            int temp = arr[low];
            arr[low] = arr[right];
            arr[right] = temp;

            quickSort(arr, low, right - 1);
            quickSort(arr, right + 1, high);
        }
    }
}

int main() {
    int arr[2000];
    for (int i = 0; i < 2000; i++) {
        arr[i] = rand() % 10000;
    }

    printf("Original Array:\n");
    for (int i = 0; i < 2000; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, 1999);

    printf("Sorted Array:\n");
    for (int i = 0; i < 2000; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
