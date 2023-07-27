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

void main() {
    int n, i, j;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
     
    warshall(n);

    printf("\nTransitive closure matrix is:\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}



