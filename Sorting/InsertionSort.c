#include <stdio.h>

void insertion_sort(int arr[], int numOfElements) {
    for (int i = 1; i < numOfElements; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
    printf("Sorted array: ");
    for (int i = 0; i < numOfElements; i++) {
        printf("%d ", arr[i]);
    }

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

    insertion_sort(array, numOfElements);
    return 0;
}
