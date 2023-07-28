/* program to implement quick sort*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int count;


void swap(int  *a,int *  b)
{
  int temp=*a;
  *a=*b;
  *b=temp;

}


 int partition(int * arr,int beg,int end)
 {
    int pivot =arr[beg];
    int i=beg,j=end+1;
   
    do{
   
       do{
          count++;
          i++;
          }while(arr[i]<pivot);
     
        do{
          count++;
          j--;
          }while(arr[j]>pivot);
          swap(&arr[i],&arr[j]);

     }while(i<j);
     
      swap(&arr[i],&arr[j]);
      swap(&arr[beg],&arr[j]);

      return j;
 }
 
  void quicksort(int *arr,int beg,int end)
{
   if(beg<end)
   {
     int split=partition(arr,beg,end);
     quicksort(arr,beg,split-1);
     quicksort(arr,split+1,end);
  }


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

      quicksort(arr,0,n-1);

      printf("THE ELEMENTS OF THE ARRAY AFTER SORTING\n"); 
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
       printf("\n");
       printf("\n");
}


