#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void insertionSortAscending(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void insertionSortDescending(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    int insertionSortedAscending[n];
    for (int i = 0; i < n; i++) {
        insertionSortedAscending[i] = arr[i];
    }
    insertionSortAscending(insertionSortedAscending, n);
    printf("Insertion Sort - Ascending: ");
    printArray(insertionSortedAscending, n);
    int insertionSortedDescending[n];
    for (int i = 0; i < n; i++) {
        insertionSortedDescending[i] = arr[i];
    }
    insertionSortDescending(insertionSortedDescending, n);
    printf("Insertion Sort - Descending: ");
    printArray(insertionSortedDescending, n);
    return 0;
}
