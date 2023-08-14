#include <stdio.h>

void reverseArray(int A[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", A[i]);
    }
}

int main() {
    int noOfElements;
    printf("Enter number of elements in the Array: ");
    scanf("%d", &noOfElements);
    int A[noOfElements]; 

    for (int i = 0; i < noOfElements; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    reverseArray(A, noOfElements);  

    return 0;
}
