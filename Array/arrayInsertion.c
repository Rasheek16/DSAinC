#include <stdio.h>

void insertion(int A[], int elementCount, int InsertionElement) {
    int location;
    printf("Enter location to insert element: ");
    scanf("%d", &location);
    int B[elementCount + 1];
    for (int i = 0; i < location - 1; i++) {
        B[i] = A[i];
        }
    B[location - 1] = InsertionElement;
    for (int i = location - 1; i < elementCount; i++) {
        B[i + 1] = A[i];
        }
    for (int i = 0; i < elementCount + 1; i++) {
        printf("%d ", B[i]);
    }
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

    int InsertionElement;
    printf("Enter element to insert: ");
    scanf("%d", &InsertionElement);

    insertion(A, elementCount, InsertionElement);

    return 0;
}


