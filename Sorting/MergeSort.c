#include <stdio.h>


void merge(int a[], int left, int middle, int right){
    int n1 = middle-left+1;
    int n2 = right-middle;
    int leftArr[n1], rightArr[n2];
    for(int i=0;i<n1;i++){
        leftArr[i]=a[left+i];
    }
    for(int j=0;j<n2;j++){
        rightArr[j]=a[middle+1+j];
    }
    int i=0,j=0,k=left;
    while (i<n1 && j<n2){
        if (leftArr[i] <= rightArr[j]){
            a[k] = leftArr[i];
            i++;
        }else{
            a[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=leftArr[i];
        i++;
        k++;
    }
    while (j<n2) {
        a[k] = rightArr[j];
        j++;
        k++;
    }
}


void mergeSort(int a[], int left, int right) {
    if(left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(a, left, middle);
        mergeSort(a, middle + 1, right);
        merge(a, left, middle, right);
    }
}


int main(){
    int arr[2]={2, 1};
    int length=sizeof(arr)/sizeof(arr[0]);
    printf("Original Array: ");
    for (int i=0; i<length; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    mergeSort(arr,0,length-1);
    printf("Sorted Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
