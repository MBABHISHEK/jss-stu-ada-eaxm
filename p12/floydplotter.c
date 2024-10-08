/* Program to implement Floyd's Algorithm with Plotter */

#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int counter = 0;
int count = 0;

int minimum(int a, int b) {
    return (a < b) ? a : b;
}

void floyd(int n) {
    int t;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            t = graph[i][k];
            for (int j = 1; j <= n; j++) {
                if (t < graph[i][j]) {
                    count++;
                    graph[i][j] = minimum(graph[i][j], (graph[i][k] + graph[k][j]));
                }
                counter++;
            }
        }
    }
}

void plotter(int c) {
    FILE *f1 = fopen("floydBest.txt", "a");
    FILE *f2 = fopen("floydWorst.txt", "a");
    
    for (int i = 1; i <= 10; i++) {
        int n = i;
        if (c == 1) { // Worst case: Dense graph (complete graph)
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i != j) {
                        graph[i][j] = rand() % 10 + 1; // Random weights
                    } else {
                        graph[i][j] = 0; // No self-loops
                    }
                }
            }
        }

        if (c == 0) { // Best case: Sparse graph (minimal edges)
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    graph[i][j] = (i == j) ? 0 : INT_MAX; // Initialize graph with infinity (no direct path)
                }
            }
            for (int i = 1; i < n; i++) {
                graph[i][i+1] = rand() % 10 + 1; // Create a path
            }
            graph[n][1] = rand() % 10 + 1; // Complete the cycle
        }

        counter = 0;
        count = 0;
        floyd(n);

        if (c == 0)
            fprintf(f1, "%d\t%d\t%d\n", n, counter, count);
        else
            fprintf(f2, "%d\t%d\t%d\n", n, counter, count);
    }

    fclose(f1);
    fclose(f2);
}

void main() {
    for (int i = 0; i < 2; i++) {
        plotter(i);
    }
    printf("The graph plotting is completed\n");
}
