#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int n, i, j, src, cost[10][10], d[10] = {0}, removed[10] = {0}, count = 0;
int heapsize;
int graphcount, heapcount, max;

struct vertex
{
    int id;
    int dist;
} heap[10];

typedef struct vertex ver;

// Function to swap two vertices
void swap(struct vertex *a, struct vertex *b)
{
    struct vertex temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify function to maintain the heap property
void heapify(struct vertex arr[], int n, int i)
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

// Heap sort function to build a min-heap
void heapSort(struct vertex arr[], int n)
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
            if (i == j)
                cost[i][j] = 0; // No self-loop cost
            else if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }

    // Initialize the source vertex distance to 0 and others to infinity (INT_MAX)
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    for (i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
    }
    d[src] = 0;
}

// Function to remove and return the minimum vertex from the heap
ver deleteheap(ver heap[])
{
    ver min = heap[0];
    heap[0] = heap[heapsize - 1];
    heapsize = heapsize - 1;
    heapify(heap, heapsize, 0);
    return min;
}

// Dijkstra's algorithm implementation using a min-heap
void dijkstra()
{
    for (i = 0; i < n; i++)
    {
        heap[i].id = i;
        heap[i].dist = INT_MAX;
    }
    heap[src].dist = 0;
    heapsize = n;

    // Building the initial min-heap
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
                            heap[o].dist = d[i];
                            break;
                        }
                    }
                    // Re-sort heap after updating
                    heapSort(heap, heapsize);
                }
            }
        }
    }
}

// Function to run the Dijkstra algorithm and display the results
void run()
{
    makegraph();
    max = 0;
    graphcount = 0;
    heapcount = 0;
    count = 0;
    dijkstra();

    printf("Shortest paths from vertex %d:\n", src);
    for (i = 0; i < n; i++)
    {
        if (src != i)
            printf("%d -> %d = %d\n", src, i, d[i]);
    }

    max = (graphcount > heapcount) ? graphcount : heapcount;
    printf("Basic operation count (Max of graph and heap counts): %d\n", max);
}

// Main function with a menu-driven approach
void main()
{
    FILE *f1;
    f1 = fopen("dijkstrasgraph.txt", "a");
    int ch;

    while (1)
    {
        printf("Enter choice 1 to continue and 0 to exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            run();
            fprintf(f1, "Vertices: %d, Max Operation Count: %d\n", n, max);
            break;
        case 0:
            fclose(f1);
            exit(0);
        default:
            printf("Invalid choice. Please enter 1 to continue or 0 to exit.\n");
        }
    }
}
