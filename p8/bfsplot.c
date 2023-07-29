/*program to implement BFS to check connectivity and acyclicity for the adjacency matrix*/

#include<stdio.h>
#include<stdlib.h>
int bfsCount = 0, cyclic=0;
int count = 0;//to count how many vertex visited 
int orderCount = 0;

int graph[100][100], visited[100];

void bfs(int n, int start){
    int queue[n], parent[n];
    int rear = -1, front = -1, i, parentNode;
    visited[start] = 1; count++;
    queue[++rear] = start;
    parent[rear] = -1;
    while(rear != front){
        start = queue[++front];
        parentNode = parent[front];
        for(i=0; i<n; i++){
            orderCount++;
            if (i != parentNode && graph[start][i] && visited[i])
                cyclic = 1;
            if((graph[start][i]) && (visited[i] == 0)){
                queue[++rear] = i;
                parent[rear] = start;
                visited[i] = 1;
               // count++;
            }
        }
    }
}


void ploter(int k)
{

    FILE *f1= fopen("BFSBEST.txt", "a");
    FILE *f2=fopen("BFSWOSR.txt", "a");
    int v,start;
    for(int i=1;i<=10;i++)
  {
    v=i;


 if(k==0)
 {
  for(int i=0;i<v;i++)
{

   for(int j=0;j<v;j++)
  {
       
       if(i!=j)
       {
        graph[i][j] =1;
       }
       else
       graph[i][j] =0;
  }
}
 }

if(k==1)
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        graph[i][j] =0;
    }
    for(int i=0;i<v-1;i++)
    {
            graph[i][i+1]=1;
    }

}

    bfsCount = 0, cyclic=0;
    count = 0;
    orderCount = 0;
    bfsCount++;
    bfs(v, 0);
    if(count != v){
        start = 1;
        while(count != v){
            if(visited[start] != 1) {
                bfsCount++;
                bfs(v, start);
            }
            start++;
        }
    }
           if(k==0)
         fprintf(f2,"%d\t%d\n",v,orderCount);
         else
          fprintf(f1,"%d\t%d\n",v,orderCount);
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
