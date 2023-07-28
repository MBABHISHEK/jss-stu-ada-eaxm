#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int linearSearch(int *a, int k, int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        count++;
        if (*(a + i) == k)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int key, int *a, int high, int low)
{ 
    
    int mid;
    mid = (high + low) / 2;
    if (low > high)
        return -1;
    if (*(a + mid) == key)
        return mid;
    else if (*(a + mid) > key)
        return binarySearch(key,a,mid - 1,low);
    else
        return binarySearch(key, a, high, mid + 1);
}

void main()
{
    int arr[100];
    int n,key,r;

    for(;;)
    {
      printf("ENTER 1.TO LINEAR SEARCH\n2.TO BINARY SEARCH\n3.TO EXIT\n");
      int ch;
      scanf("%d",&ch);
      switch (ch)
      {
      case 1:
      printf("ENTER THE NUMBER OF ELEMENTS\n");
      scanf("%d",&n);
      printf("ENTER THE ELEMENTS OF THE ARRAY\n");
      for(int i=0;i<n;i++)
      {
      scanf("%d",&arr[i]);
      
      }
      printf("ENTER THE KEY ELEMENT\n");
      scanf("%d",&key);
      r=linearSearch(arr,key,n);
        if (r != -1)
        {
            printf("the element is present at the index \n",r);
        }
        else
            printf("Element not found");
        break;
       case 2:
      printf("ENTER THE NUMBER OF ELEMENTS\n");
      scanf("%d",&n);
      printf("ENTER THE ELEMENTS OF THE ARRAY\n");
      for(int i=0;i<n;i++)
      scanf("%d",arr[i]);
      printf("ENTER THE KEY ELEMENT\n");
      scanf("%d",key);
      r=binarySearch(key,arr,0,n-1);
        if (r != -1)
        {
            printf("the element is present at the index \n",r);
        }
        else
            printf("Element not found");
        break;
      default:exit(0);
      }
    }
}
