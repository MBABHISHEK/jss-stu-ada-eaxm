/*TESTER IS USED TO CHECK THE CORRECTNESS OF THE ALGORITH*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void merge(int *arr,int beg,int mid,int end)
{
   int i,j,k;
   int n1=(mid-beg)+1;
   int n2=end-mid;
   int left[n1],right[n2];
   for(i=0;i<n1;i++)
   left[i]=arr[beg+i];
   for(j=0;j<n2;j++)
   right[j]=arr[mid+j+1];
    i=0;j=0;k=beg;
   while(i<n1&&j<n2)
   {
        count++;
       if(left[i]<=right[j])
        arr[k]=left[i++];
       else
        arr[k]=right[j++];
       k++;
   }

    while(i<n1)
    arr[k++]=left[i++];
     while(j<n2)
    arr[k++]=right[j++];

}



void mergesort(int *arr,int beg,int end)
{
    if(beg<end)
    {
     int mid=(beg+end)/2;
     mergesort(arr,beg,mid);
     mergesort(arr,mid+1,end);
     merge(arr,beg,mid,end);
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

      mergesort(arr,0,n-1);

      printf("THE ELEMENTS OF THE ARRAY BEFORE SORTING\n"); 
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
       printf("\n");
       printf("\n");
}


