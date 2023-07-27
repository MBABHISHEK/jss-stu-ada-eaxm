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
        printf("-->%c", start+65);
        for(i=0; i<n; i++){
            orderCount++;
            if (i != parentNode && graph[start][i] && visited[i])
                cyclic = 1;
            if((graph[start][i]) && (visited[i] == 0)){
                queue[++rear] = i;
                parent[rear] = start;
                visited[i] = 1;
                count++;
            }
        }
    }
}

void main(){
    int n, i, j, start;
    printf("Enter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0; 
    }

     printf("the Adjacency Matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
     bfsCount = 0, cyclic=0;
     count = 0;
     orderCount = 0;
    printf("Breadth First Search Traversal:\n");
    bfsCount++;
    bfs(n, 0);
    if(count == n){
        printf("\nGraph is connected.\n");
    }
    else {
        printf("\nThe graph is not connected.\n");
        start = 1;
        while(count != n){
            if(visited[start] != 1) {
                bfsCount++;
                bfs(n, start);
                printf("\n");
            }
            start++;
        }
    }
    printf("\nThe number of components in the graph is %d\n", bfsCount);
    if(cyclic) {
        printf("\nThe graph is cyclic\n");
    } else {
        printf("\nThe graph is acyclic\n");
    }
}




