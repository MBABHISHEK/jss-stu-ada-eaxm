/* program to implement the Warshall's Algorithm*/

#include<stdio.h>
#include<stdlib.h>

int graph[100][100];
int counter=0;
void warshall (int n)
{
    for(int k=1; k<=n; k++) 
    {
        for(int i=1; i<=n; i++) 
        {

            if(graph[i][k]!=0)
            {
                 for(int j=1; j<=n; j++)
                {// graph[i][j] = (graph[i][k] && graph[k][j]));
                  graph[i][j] = (graph[i][j] || (graph[i][k] && graph[k][j]));
                   counter++;
                }
            }
        }
    }
}


void ploter(int c)
{

  FILE *f1=fopen("warshalbest.txt","a");
  FILE *f2=fopen("warshallworst.txt","a");
   
    for(int i=1;i<=10;i++)
  {
    int n=i; 
 if(c==1)
{
    for(int i=1;i<=n;i++)
  {
     for(int j=1;j<=n;j++)
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

if(c==0)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
         graph[i][j] =0;
    }
    for(int i=1;i<n;i++)
    {
            graph[i][i+1]=1;
    }
     graph[n][1]=1;
}
    counter=0;
    warshall(n);    
    if(c==0)
    fprintf(f1,"%d\t%d\n",n,counter);
    else
    fprintf(f2,"%d\t%d\n",n,counter);

}
   fclose(f1);
   fclose(f2);
}


void main()
{
           for(int i=0;i<2;i++)
                   ploter(i);
        printf("the graph is plotted\n");
}
