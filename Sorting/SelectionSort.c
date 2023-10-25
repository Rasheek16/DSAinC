#include <stdio.h>

void selection_sort(int arr[], int numOfElements) {
    for (int i = 0; i < numOfElements - 1; i++) {
        int min_index = i;
        for (int j=i+1; j<numOfElements; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    printf("Sorted array: ");
    for (int i = 0; i < numOfElements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numOfElements;
    printf("Enter no of elements in array: ");
    scanf("%d", &numOfElements);
    
    int array[numOfElements];
    for (int i = 0; i < numOfElements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    selection_sort(array, numOfElements);

    return 0;
}