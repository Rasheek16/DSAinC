#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int A[], int elementCount, int searchElement) {
    int s=0;
    int e=elementCount-1;
    int x=-1;
    while (s<=e) {
        int mid=(s+e)/2;
        if(searchElement==A[mid]) {
            x=mid;
            break;
        } else if(searchElement>A[mid]) {
            s=mid+1;
        } else {
            e=mid-1;
        }
    }

    if (x!=-1){
        printf("Search Element found at position %d\n",x+1);
    }else{
        int location;
        printf("Search Element Not found\n Enter location to insert element: ");
        scanf("%d",&location);

        int B[elementCount +1];

        for(int i=0; i<location;i++) {
            B[i] = A[i];
        }
        B[location] = searchElement;
        for(int i=location;i<elementCount;i++) {
            B[i + 1] = A[i];
        }
        for(int i=0;i<elementCount+1;i++) {
            printf("%d ", B[i]);
        }
    }

    return 0;
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

    bubbleSort(A, elementCount);

    printf("\nSorted array: ");
    for (int i = 0; i < elementCount; i++) {
        printf("%d ", A[i]);
    }

    int searchElement;
    printf("\nEnter element to find: ");
    scanf("%d", &searchElement);

    binarySearch(A, elementCount, searchElement);

    return 0;
}
