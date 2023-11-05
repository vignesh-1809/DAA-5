#include <stdio.h>
int binarySearch(int arr[], int low, int high, int key, int *comparisons) {
    int mid;
    while (low <= high) {
        (*comparisons)++;
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
void binaryInsertionSort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        int pos = binarySearch(arr, 0, j, key, &comparisons);

        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }

        arr[j + 1] = key;
    }

    printf("Comparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    


    binaryInsertionSort(arr, n);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
