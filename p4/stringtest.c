//Program to perform analysis of brute force string matching
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count = 0;

int stringmatching(char *text, char *pattern, int n, int m) {
    count = 0;
    for(int i=0; i<=n-m; i++)
     {
        int j=0;
        while(j<m)
         {
            count++;
            if(pattern[j] != text[i+j]) 
                break;
            j++;
        }
        if(j==m) {
            printf("THE PATTERN FOUND \n");

            return count;
        }
    }
    printf("THE PATTERN not found \n");
    return count;
}

void main()
{
  
    int m,n;
    char text[100],pattern[100];
    printf("ENTER THE PATTERN LENGTH\n");
    scanf("%d",&m);
    printf("ENTER THE TEXT LENGTH\n");
    scanf("%d",&n);
    printf("ENTER THE TEXT\n");
    scanf("%s",text);
    printf("ENTER THE PATTERN\n");
    scanf("%s",pattern);
    
            stringmatching(text, pattern, n,m); 

}


