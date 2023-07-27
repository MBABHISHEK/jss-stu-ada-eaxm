/*program to implement the dfs algorithm and to check connectivity and acyclicity with adjacency matrix */

#include<stdio.h>
#include<stdlib.h>

int graph[100][100], visited[100], isCyclic = 0;
int dfsCount = 0, count = 0;
int dcount=0;
int path[100];
int d;

void dfs1(int n, int start, int parent) {
    visited[start] = 1;
    count++;
    for(int i=0; i<n; i++) {
        if(i!=parent && graph[start][i] && visited[i])
            isCyclic = 1;
        
            dcount++;
        if(graph[start][i] && visited[i]==0)
            dfs1(n, i, start);
    }
}
        
void ploter(int k)
{

    FILE *f1= fopen("DFSBEST.txt", "a");
    FILE *f2=fopen("DFWOSR.txt", "a");
    int v;
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
    isCyclic=0;
     dfsCount = 0;
     count = 0;
     dcount=0;
    dfs1(v, 0, -1);
    dfsCount++;
    int start;
        start = 1;
        while(count != v) {
            if(visited[start] != 1) {
                dfs1(v, start, -1);
                dfsCount++;
            }
            start++;
        }

           if(k==0)
         fprintf(f2,"%d\t%d\n",v,count);
         else
          fprintf(f2,"%d\t%d\n",v,count);
     free(arr);

  }

  fclose(f1);
  fclose(f2);

}


void main()
{
        for(int i=0;i<2;i++)
                   ploter(i);
             printf("DATA ENTERED IN TO THE FILE\n");     
      

    
}
