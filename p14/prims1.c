

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int n, i, j, cost[10][10], cnt = 0, visited[10], removed[10];
int heapsize = 0;

struct edge
{
    int v;
    int dist;
    int u;
} heap[10] /*heapsize*/, VT[10] /*cnt*/;
typedef struct edge edg;
// Min Heap function declaration
void swap(struct edge *a, struct edge *b)
{
    struct edge temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(struct edge arr[], int n, int i)
{
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
void heapSort(struct edge arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
// Min heap function declaration end


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
}
// returns the min of the heap //astey
edg deleteheap(edg heap[])
{
    edg min = heap[0];
    heap[0] = heap[heapsize - 1];
    heapsize = heapsize - 1;
    return min;
}
void prim()
{
    // Appending Souce vertex to heap and incrementing heap size
    visited[0] = 1;
    heap[heapsize].v = -1;
    heap[heapsize].u = 0;
    heap[heapsize].dist = 0;
    heapsize++;

    while (cnt != n)
    {
        // fetching the min and appending to the visited array of edges and deleting from heap
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
                // not visited and not removed from heap
                visited[i] = 1;
                heap[heapsize].v = v;
                heap[heapsize].u = i;
                heap[heapsize].dist = cost[v][i];
                heapsize++;
            }
            if (visited[i] && cost[v][i] != INT_MAX && !removed[i])
            { // visited but not removed from heap --> scope for minimisation?
                for (j = 0; j < heapsize; j++)
                { // finding that edge in the sorted heap
                    if (heap[j].u == i && cost[v][i] < heap[j].dist)
                    { // replacing if optimal
                        heap[j].dist = cost[v][i];
                        heap[j].v = v;
                        break;
                    }
                }
            }
        }
        heapSort(heap, heapsize); // sorting after deletions and value modifications
    }
}
void main()
{
    int sum = 0;
    makegraph();
    prim();
    for (int i = 1; i < cnt; i++)
    {
        printf("%c --> %c == %d\n", VT[i].v + 65, VT[i].u + 65, VT[i].dist);
        sum += VT[i].dist;
    }
    printf("Minimum Distance is: %d", sum);
}
