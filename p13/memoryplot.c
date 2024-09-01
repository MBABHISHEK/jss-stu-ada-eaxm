#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int t[100][100], v[100], w[100];
int operationCount = 0; // To count the number of operations

void knapsack(int n, int m) {
    int i, j;
    for (i = 0; i < n + 1; i++) {
        for (j = 0; j < m + 1; j++) {
            operationCount++; // Incrementing operation count for each iteration
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (j < w[i])
                t[i][j] = t[i - 1][j];
            else
                t[i][j] = max(t[i - 1][j], v[i] + t[i - 1][j - w[i]]);
        }
    }

    printf("THE MAXIMUM VALUE IS : %d\n", t[n][m]);

    printf("THE COMPOSITION IS \n");
    for (i = n; i > 0; i--) {
        if (t[i][m] != t[i - 1][m]) {
            printf("%d ", i);
            m = m - w[i];
        }
    }
    printf("\n");
}

void main() {
    FILE *f1;
    f1 = fopen("knapsackgraph.txt", "a");
    int n, m, i;

    printf("ENTER NO OF ITEMS:\n");
    scanf("%d", &n);
    printf("ENTER THE STACK CAPACITY:\n");
    scanf("%d", &m);

    printf("WEIGHT\tVALUE\n");
    for (i = 1; i < n + 1; i++) {
        scanf("%d\t%d", &w[i], &v[i]);
    }

    operationCount = 0; // Resetting the operation count before the function call
    knapsack(n, m);

    printf("Operation Count: %d\n", operationCount);
    fprintf(f1, "Items: %d, Capacity: %d, Operation Count: %d\n", n, m, operationCount);

    fclose(f1);
}
