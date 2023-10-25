#include <stdio.h>


void bubble_sort(int arr[], int numOfElements) {
    int i, j;
    int temp;
    for (i = 0; i < numOfElements ;i++) {
        for (j = 0; j<numOfElements ;j++) {
            if (arr[j]>arr[j+1]) {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted Array is :");
    for (i = 0; i < numOfElements; i++) {
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
    };
    bubble_sort(array,numOfElements);
    
    return 0;
}





