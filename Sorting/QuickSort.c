#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (1) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quickSortFirst(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partitionFirst(arr, low, high);
        quickSortFirst(arr, low, pivotIndex - 1);
        quickSortFirst(arr, pivotIndex + 1, high);
    }
}
int partitionLast(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSortLast(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partitionLast(arr, low, high);
        quickSortLast(arr, low, pivotIndex - 1);
        quickSortLast(arr, pivotIndex + 1, high);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int quickSortedFirstAscending[n];
    for (int i = 0; i < n; i++) {
        quickSortedFirstAscending[i] = arr[i];
    }
    quickSortFirst(quickSortedFirstAscending, 0, n - 1);
    printf("Quick Sort (First pivot) - Ascending: ");
    printArray(quickSortedFirstAscending, n);
    int quickSortedFirstDescending[n];
    for (int i = 0; i < n; i++) {
        quickSortedFirstDescending[i] = arr[i];
    }
    quickSortFirst(quickSortedFirstDescending, 0, n - 1);
    for (int i = 0; i < n / 2; i++) {
        swap(&quickSortedFirstDescending[i], &quickSortedFirstDescending[n - i - 1]);
    }
    printf("Quick Sort (First pivot) - Descending: ");
    printArray(quickSortedFirstDescending, n);
    int quickSortedLastAscending[n];
    for (int i = 0; i < n; i++) {
        quickSortedLastAscending[i] = arr[i];
    }
    quickSortLast(quickSortedLastAscending, 0, n - 1);
    printf("Quick Sort (Last pivot) - Ascending: ");
    printArray(quickSortedLastAscending, n);
    int quickSortedLastDescending[n];
    for (int i = 0; i < n; i++) {
        quickSortedLastDescending[i] = arr[i];
    }
    quickSortLast(quickSortedLastDescending, 0, n - 1);
    for (int i = 0; i < n / 2; i++) {
        swap(&quickSortedLastDescending[i], &quickSortedLastDescending[n - i - 1]);
    }
    printf("Quick Sort (Last pivot) - Descending: ");
    printArray(quickSortedLastDescending, n);
    return 0;
}
