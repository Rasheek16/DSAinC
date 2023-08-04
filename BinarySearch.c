#include<stdio.h>

int binarySearch(int A[], int elementCount, int searchElement) {
    int s = 0;
    int e = elementCount - 1;
    int x = -1; 
    while (s <= e) {
        int mid = (s + e) / 2;
        if(searchElement == A[mid]){
            x = mid;
            break;
        }else if(searchElement > A[mid]) {
        s = mid + 1;
        }else{
        e = mid - 1;
        }
    }
    return x;
}

int main() {
    int elementCount;
    printf("Enter number of elements to be inserted in the array: ");
    scanf("%d", &elementCount);

    int A[elementCount];
    for (int i = 0; i < elementCount; i++) {
        printf("Enter element: ");
        scanf("%d", &A[i]);
    }

    int searchElement;
    printf("Enter element to find: ");
    scanf("%d", &searchElement);

    int result = binarySearch(A, elementCount, searchElement);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
