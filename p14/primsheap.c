/*prims with min heap*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define V 10 // Maximum number of vertices in the graph

struct Vertex {
    int index;
    int key;
};

struct MinHeap {
    int size;
    int capacity;
    struct Vertex* heapArr;
};

struct Vertex newVertex(int index, int key) {
    struct Vertex vertex;
    vertex.index = index;
    vertex.key = key;
    return vertex;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->heapArr = (struct Vertex*)malloc(capacity * sizeof(struct Vertex)); // <-- Corrected line
    return minHeap;
}

void swap(struct Vertex* a, struct Vertex* b) {
    struct Vertex temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify function
void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < minHeap->size && minHeap->heapArr[leftChild].key < minHeap->heapArr[smallest].key)
        smallest = leftChild;

    if (rightChild < minHeap->size && minHeap->heapArr[rightChild].key < minHeap->heapArr[smallest].key)
        smallest = rightChild;

    if (smallest != index) {
        swap(&minHeap->heapArr[index], &minHeap->heapArr[smallest]);
        minHeapify(minHeap, smallest);
    }
}


void print(struct MinHeap* minHeap)
{
    printf("the heap contents\n");
    for(int i = 0; i < minHeap->size; i++)
    {
    printf("%c ",(minHeap->heapArr[i].index)+65);
        printf("%d ",minHeap->heapArr[i].key);
    }
    printf("\n");
}

// Build min-heap from the given array
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
        minHeapify(minHeap, i);
}

// Extract the minimum node from min-heap
struct Vertex extractMin(struct MinHeap* minHeap) {
    struct Vertex minVertex = minHeap->heapArr[0];
    minHeap->heapArr[0] = minHeap->heapArr[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return minVertex;
}

// Function to decrease the key value of a given vertex index
void decreaseKey(struct MinHeap* minHeap, int index, int newKey)
 {
    int k;
    for(int i = 0; i < minHeap->size;i++)
       {
        if(minHeap->heapArr[i].index==index)
            k=i;
       }
    minHeap->heapArr[k].key = newKey;
    while (index > 0 && minHeap->heapArr[(index - 1) / 2].key > minHeap->heapArr[index].key) {
        swap(&minHeap->heapArr[index], &minHeap->heapArr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

bool isInMinHeap(struct MinHeap* minHeap, int v) {
    for (int i = 0; i < minHeap->size; i++) {
        if (minHeap->heapArr[i].index == v)
            return true;
    }
    return false;
}

// Prim's algorithm using min-heap
void primMST(int graph[V][V], int vertices) {
    struct MinHeap* minHeap = createMinHeap(vertices);
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key values to pick minimum weight edge

    // Initialize key values and parent array
    for (int v = 0; v < vertices; v++) {
        parent[v] = -1;
        key[v] = 999;
        minHeap->heapArr[v] = newVertex(v, key[v]);
    }

    // Make the first vertex the root of MST
    key[0] = 0;
    minHeap->heapArr[0].key = 0;
    minHeap->size = vertices;

    // Loop through all vertices to construct MST
    while (minHeap->size > 0) {
       // print(minHeap);
        struct Vertex minVertex = extractMin(minHeap);
        int u = minVertex.index;
        //if(u !=0)
        //printf("%c-->%c | Cost: %d\n",parent[u]+65,u+65,key[u]);
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && isInMinHeap(minHeap, v) && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
                decreaseKey(minHeap, v, key[v]);
            }
        }

        //print(minHeap);
    }

     int total = 0;
    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%c - %c \t%d\n", parent[i]+65, i+65 ,graph[i][parent[i]]);
        total += key[i];
    }
    printf("THE TOTAL WEIGHT OF THE MST IS %d\n",total);


    free(minHeap->heapArr);
    free(minHeap);
}

int main() {
    int vertices;
    printf("Enter the total number of vertices in the graph: ");
    scanf("%d", &vertices);

    int graph[V][V];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    /* for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }*/

    primMST(graph, vertices);
    return 0;
}
