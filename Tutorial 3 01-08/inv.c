#include <stdio.h>
#include <stdlib.h>


long long int mergeAndCountInversions(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long int inversions = 0;

    i = left;
    j = mid;
    k = left;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i);
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

long long int mergeSortAndCountInversions(int arr[], int temp[], int left, int right) {
    long long int inversions = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        inversions += mergeSortAndCountInversions(arr, temp, left, mid);
        inversions += mergeSortAndCountInversions(arr, temp, mid + 1, right);

        inversions += mergeAndCountInversions(arr, temp, left, mid + 1, right);
    }

    return inversions;
}

void removeInversions(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));

    long long int inversions = mergeSortAndCountInversions(arr, temp, 0, n - 1);

    free(temp);

    printf("Number of inversions removed: %lld\n", inversions);
}

int main() {
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }


    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    removeInversions(A, n);

    printf("Array after removing inversions: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
