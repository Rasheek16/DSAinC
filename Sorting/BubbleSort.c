#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSortAscending(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void bubbleSortDescending(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
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
    int bubbleSortedAscending[n];
    for (int i = 0; i < n; i++) {
        bubbleSortedAscending[i] = arr[i];}
    bubbleSortAscending(bubbleSortedAscending, n);
    printf("Bubble Sort - Ascending: ");
    printArray(bubbleSortedAscending, n);
    int bubbleSortedDescending[n];
    for (int i = 0; i < n; i++) {
        bubbleSortedDescending[i] = arr[i];
    }
    bubbleSortDescending(bubbleSortedDescending, n);
    printf("Bubble Sort - Descending: ");
    printArray(bubbleSortedDescending, n);
    return 0;
}
