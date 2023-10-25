#include<stdio.h>

int linearSearch(int A[], int elementCount, int searchElement){
    printf("Enter element to search: ");
    scanf("%d",&searchElement);
    for (int x=0; x < elementCount ; x++){
        if (A[x] == searchElement){
           return x;
        };

    }
};;
int main(){
    int elementCount;
    
    printf("Enter number of elements to be inserted in the array :");
    scanf("%d",&elementCount);
    int elements, searchElement, A[elementCount];
    for (int i = 0; i < elementCount; i++){
        printf("Enter element : ");
        scanf("%d" , &A[i]);
    }
    int result = linearSearch(A,elementCount,searchElement);
    if (result) {
        printf("Element found at index: %d\n", result+1);
    } else {
        printf("Element not found\n");
    }

    return 0;
}