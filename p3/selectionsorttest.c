#include<stdio.h>
#include<stdlib.h>

void  selectionsort(int *a,int n)
{
     int i,j,min,t,f,count=0;
   for(i=0;i<n-1;i++)
   {
       min=i;
    for(j=i+1;j<n;j++)    
     {
  
         if(*(a+j)<*(a+min))
          min=j;
     }
    
      if(min!=i)
      {
         t=*(a+min);
         *(a+min)=*(a+i);
         *(a+i)=t;

      }

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

      selectionsort(arr,0,n-1);

      printf("THE ELEMENTS OF THE ARRAY BEFORE SORTING\n"); 
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
       printf("\n");
       printf("\n");
}

