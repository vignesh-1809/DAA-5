#include <stdio.h>
void sort(int arr[], int low, int high) {
    if (low < high) {
        int p1, p2;
        partition(arr, low, high, &p1, &p2);
        sort(arr, low, p1 - 1);
        sort(arr, p1 + 1, p2 - 1);
        sort(arr, p2 + 1, high);
    }
}
void partition(int arr[], int low, int high, int *p1, int *p2) {
    if (arr[low] > arr[high]) {
        swap(&arr[low], &arr[high]);
    }
    int pivot1 = arr[low];
    int pivot2 = arr[high];
    int i = low + 1;
    int j = high - 1;
    int k = low + 1;

    while (k <= j) {
        if (arr[k] < pivot1) {
            swap(&arr[k], &arr[i]);
            i++;
        } else if (arr[k] >= pivot2) {
            while (arr[j] > pivot2 && k < j) {
                j--;
            }
            swap(&arr[k], &arr[j]);
            j--;
            if (arr[k] < pivot1) {
                swap(&arr[k], &arr[i]);
                i++;
            }
        }
        k++;
    }

    i--;
    j++;

    swap(&arr[low], &arr[i]);
    swap(&arr[high], &arr[j]);

    *p1 = i;
    *p2 = j;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int n,arr[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    sort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
