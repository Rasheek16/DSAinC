#include <stdio.h>
void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max){
            max = arr[i];
        }
    }
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
        }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        }
    for (int i = 1; i <= max; i++){
        count[i] += count[i - 1];
        }
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    countingSort(arr, n);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}