#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSortAscending(int arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]); }
}
void selectionSortDescending(int arr[], int n) {
    int i, j, maxIndex;
    for (i = 0; i < n - 1; i++) {
        maxIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(&arr[i], &arr[maxIndex]);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);}
    printf("\n");
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int selectionSortedAscending[n];
    for (int i = 0; i < n; i++) {
        selectionSortedAscending[i] = arr[i];}
    selectionSortAscending(selectionSortedAscending, n);
    printf("Selection Sort - Ascending: ");
    printArray(selectionSortedAscending, n);
    int selectionSortedDescending[n];
    for (int i = 0; i < n; i++) {
        selectionSortedDescending[i] = arr[i];}
    selectionSortDescending(selectionSortedDescending, n);
    printf("Selection Sort - Descending: ");
    printArray(selectionSortedDescending, n);
    return 0;
}
