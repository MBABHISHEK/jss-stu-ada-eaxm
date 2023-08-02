#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define AL 10;

int n, i, j, src, cost[10][10], d[10] = {0}, removed[10] = {0}, count = 0;

int heapcount,graphcount;
int heapsize;
struct vertex
{
    int id;
    int dist;
} heap[10];

typedef struct vertex ver;

// Min Heap function declaration
void swap(struct vertex *a, struct vertex *b)
{
    struct vertex temp = *a;
    *a = *b;
    *b = temp;
}
void heapSort(struct vertex arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
// Min heap function declaration end
int dcount=0;
void heapify(struct vertex arr[], int n, int i)
{
    heapcount++;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].dist < arr[largest].dist)
        largest = left;
    if (right < n && arr[right].dist < arr[largest].dist)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void makegraph()
{
    // Make Graph
    printf("Enter the total number of vertices:");
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

    // Initialise the source vertex distance to 0 and rest all to infinity(INT_MAX)
    printf("Enter the source vertex:");
    scanf("%d", &src);
    for (i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
    }
    d[src] = 0;
}


// returns the min of the heap and heapifies the rest of the elements
ver deleteheap(ver heap[])
{
    ver min = heap[0];
    heap[0] = heap[heapsize - 1];
    heapsize = heapsize - 1;
  //  heapify(heap, heapsize, 0);
    return min;
}


void dijkstra()
{
    for (i = 0; i < n; i++)
    {
        heap[i].id = i;
        heap[i].dist = INT_MAX;
    }
    heap[src].dist = 0;
    heapsize = n;
    // pulling source to index 0

    heapSort(heap, heapsize);
    while (count < n)
    {
        ver minvertex = deleteheap(heap);
        int u = minvertex.id;
        removed[u] = 1;
        count++;

        for (i = 0; i < n; i++)
        {
            if (!removed[i] && cost[u][i] != INT_MAX)
            {
                graphcount++;
                if ((d[u] + cost[u][i]) < d[i])
                {
                    d[i] = (d[u] + cost[u][i]);
                    for (int o = 0; o < heapsize; o++)
                    {
                        if (heap[o].id == i)
                        {
                            heap[o].dist = heap[o].dist < d[i] ? heap[o].dist : d[i];
                            break;
                        }
                    }

            
                }
            }
        }

         heapSort(heap, heapsize);
    }
}


void main()
{
    heapcount=0;
    graphcount=0;
    makegraph();
    dijkstra();
    printf("Shortest path id %d is:\n", src);
    for (i = 0; i < n; i++)
    {
        if (src != i)
            printf("%d -> %d = %d\n", src, i, d[i]);
    }
     int max=(graphcount<heapcount)?heapcount:graphcount;
    printf("THE COUNT IS %d\n",max);
}
