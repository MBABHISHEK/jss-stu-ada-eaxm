#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int n, i, j, cost[10][10], cnt = 0, visited[10], removed[10];
int heapsize = 0;
int heapcount, graphcount;
struct edge
{
    int v;
    int dist;
    int u;
} heap[10], VT[10];

typedef struct edge edg;

// Function to swap two edges in the heap
void swap(struct edge *a, struct edge *b)
{
    struct edge temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify function to maintain the heap property
void heapify(struct edge arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    heapcount++;
    if (left < n && arr[left].dist < arr[smallest].dist)
        smallest = left;
    if (right < n && arr[right].dist < arr[smallest].dist)
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Heap sort function to build the initial min-heap
void heapSort(struct edge arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// Function to build the graph from user input
void makegraph()
{
    printf("Enter the total number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix of the Graph\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
}

// Function to remove and return the minimum edge from the heap
edg deleteheap(edg heap[])
{
    edg min = heap[0];
    heap[0] = heap[heapsize - 1];
    heapsize = heapsize - 1;
    return min;
}

// Prim's algorithm implementation using a min-heap
void prim()
{
    visited[0] = 1;
    heap[heapsize].v = -1;
    heap[heapsize].u = 0;
    heap[heapsize].dist = 0;
    heapsize++;

    while (cnt != n)
    {
        edg min = deleteheap(heap);
        VT[cnt].v = min.v;
        VT[cnt].u = min.u;
        VT[cnt].dist = min.dist;
        cnt++;
        int v = min.u;
        removed[v] = 1;
        for (i = 1; i < n; i++)
        {
            if (!visited[i] && cost[v][i] != INT_MAX && !removed[i])
            {
                visited[i] = 1;
                heap[heapsize].v = v;
                heap[heapsize].u = i;
                heap[heapsize].dist = cost[v][i];
                heapsize++;
            }
            if (visited[i] && cost[v][i] != INT_MAX && !removed[i])
            {
                graphcount++;
                for (j = 0; j < heapsize; j++)
                {
                    if (heap[j].u == i && cost[v][i] < heap[j].dist)
                    {
                        heap[j].dist = cost[v][i];
                        heap[j].v = v;
                        break;
                    }
                }
            }
        }
        heapSort(heap, heapsize);
    }
}

// Function to run Prim's algorithm and display the results
void run()
{
    makegraph();
    heapcount = 0;
    graphcount = 0;
    prim();

    int sum = 0;
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < cnt; i++)
    {
        printf("%c --> %c == %d\n", VT[i].v + 65, VT[i].u + 65, VT[i].dist);
        sum += VT[i].dist;
    }
    printf("Minimum Distance is: %d\n", sum);

    int max = (graphcount > heapcount) ? graphcount : heapcount;
    printf("Basic operation count (Max of graph and heap counts): %d\n", max);
}

// Main function with a menu-driven approach
void main()
{
    FILE *f1;
    f1 = fopen("primgraph.txt", "a");
    int ch;

    while (1)
    {
        printf("Enter choice 1 to continue and 0 to exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            run();
            fprintf(f1, "Vertices: %d, Max Operation Count: %d\n", n, (graphcount > heapcount) ? graphcount : heapcount);
            break;
        case 0:
            fclose(f1);
            exit(0);
        default:
            printf("Invalid choice. Please enter 1 to continue or 0 to exit.\n");
        }
    }
}
