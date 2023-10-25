#include<stdio.h>
int main() {
  int arr1[] = {1, 3, 5, 7};
  int arr2[] = {2, 4, 6, 8};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int arr3[n1 + n2];

  merge(arr1, arr2, n1, n2, arr3);

  for (int i = 0; i < n1 + n2; i++) {
    printf("%d ", arr3[i]);
  }

  printf("\n");

  return 0;
}
fact(int x){
    int i;
    printf("Enter the number");
    scanf("%d",&x);
    int fact=1;
    for(i =1 ; i<=x ; i++){
        fact=fact*i;
    }
    printf("%d",fact);
}
fibonacciSeries(int x){
    printf("Enter value of x");
    scanf("%d",&x);
    int G;
    int l=0;
    int z=0; 
    int y=1;
    printf("%d",l);
    for(int i=1; i<x; i++){
        G=z+y;
        y=z;
        z=G;
        
    
    printf(",%d",G);
        
    }
}


void merge(int *arr1, int *arr2, int n1, int n2, int *arr3) {
  int i = 0, j = 0, k = 0;
  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j]) {
      arr3[k++] = arr1[i++];
    } else {
      arr3[k++] = arr2[j++];
    }
  }

  while (i < n1) {
    arr3[k++] = arr1[i++];
  }

  while (j < n2) {
    arr3[k++] = arr2[j++];
  }
}


