/*program to implement the topological sorting with dfs on adjacency matrix*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int count=0;
int graph[MAX][MAX], visited[MAX],path[MAX], count=0;
int stack[MAX], top=-1;
int c=0;

void dfs(int n, int start) {
    visited[start] = 1;
    path[start] =1;
    for(int i=0; i<n; i++)
      {
          count++;
          if(graph[start][i] && visited[i]==1&& path[i]==1)
              c=1 ;
        if(graph[start][i] && visited[i]==0)
            dfs(n, i);
       }
       path[start]=0;
    stack[++top] = start;
}

void ploter(int k)
{

    FILE *f1= fopen("BFSBEST.txt", "a");
    FILE *f2=fopen("BFSWOSR.txt", "a");
    int v,start;
    for(int i=1;i<=10;i++)
  {
    v=i;
  int *arr[v];
  for(int i=0;i<v;i++)
  arr[i]=(int *)malloc(sizeof(int)*v); 


 if(k==0)
 {
  for(int i=0;i<v;i++)
{

   for(int j=0;j<v;j++)
  {
       
       if(i!=j)
       {
        arr[i][j] =1;
       }
       else
       arr[i][j] =0;
  }
}
 }

if(k==1)
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
         arr[i][j] =0;
    }
    for(int i=0;i<v-1;i++)
    {
            arr[i][i+1]=1;
    }

}
count=0;
     for(int i=0; i<v; i++) {
        if(visited[i] == 0)
            dfs(n, i);
           if(k==0)
         fprintf(f2,"%d\t%d\n",v,count);
         else
          fprintf(f1,"%d\t%d\n",v,count);
         // printf("%d\t%d\n",v,orderCount);


  }

  fclose(f1);
  fclose(f2);

}

void main()
{

    for(int i=0; i<2;i++)
    ploter(i);
}
