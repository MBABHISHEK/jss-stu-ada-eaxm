/*heap sort with recursion */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count,count2=0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void heapify(int *heap, int n, int root) {
    int largest = root;
    int left = 2*root+1;
    int right = 2*root+2;
    if(left < n )
    {
          count++;
    if(heap[left] > heap[largest]) {
        largest = left;
    }
    }
    if(right < n )
    {
          count++;
    if(heap[right] > heap[largest]) {
        largest = right;
    }
    }
    if(largest != root) {
        swap(&heap[root], &heap[largest]);
        heapify(heap, n, largest);
    }
}


void heapSort(int *heap, int n) {
    for(int i = (n/2)-1; i>=0; i--) {
        heapify(heap, n, i);
    }
     count2=count;
     count=0;
    for(int i = n-1; i>=0; i--) {
        swap(&heap[0], &heap[i]);
        heapify(heap, i, 0);
    }

}

int max(int a, int b) {

    int temp =a>b ? a:b;
    return temp;
}
void main()
{
  int *arr, n;
   printf("ENTER THE NUMBER OF ELEMENTS\n");
   scanf("%d",&n);

   arr=(int *)malloc(sizeof(int)*n);
   printf("ENTER THE ELEMENTS OF THE ARRAY\n");
      for(int i=0;i<n;i++)
       scanf("%d",&arr[i]);

  printf("THE ELEMENTS OF THE ARRAY BEFORE SORTING\n"); 
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
    printf("\n");

      heapSort(arr,n);

      printf("THE ELEMENTS OF THE ARRAY BEFORE SORTING\n"); 
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
       printf("\n");
       printf("\n");
}


