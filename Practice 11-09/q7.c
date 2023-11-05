#include <stdio.h>

int findThirdMaximum(int arr[], int n, int *comparisons) {
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }

    return third;
}

int main() {
    int n, comparisons = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int thirdMaximum = findThirdMaximum(arr, n, &comparisons);
    printf("Third maximum element is: %d\n", thirdMaximum);
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
