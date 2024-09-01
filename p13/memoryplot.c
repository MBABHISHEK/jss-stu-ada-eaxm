#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int t[100][100], v[100], w[100], n, m, i, j;
int operationCount = 0; // To count the number of operations

int knap(int i, int j) {
    operationCount++; // Incrementing operation count for each call

    if (t[i][j] == -1) {
        if (j < w[i])
            t[i][j] = knap(i - 1, j);
        else
            t[i][j] = max(knap(i - 1, j), v[i] + knap(i - 1, j - w[i]));
    }
    return t[i][j];
}

void initializeMemoizationTable() {
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            t[i][j] = -1;
        }
    }

    // Initialize the base cases
    for (i = 0; i <= n; i++) {
        t[i][0] = 0;
    }
    for (j = 0; j <= m; j++) {
        t[0][j] = 0;
    }
}

void printComposition(int n, int m) {
    printf("THE COMPOSITION IS \n");
    for (int i = n; i > 0; i--) {
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

    printf("ENTER NO OF ITEMS:\n");
    scanf("%d", &n);
    printf("ENTER THE STACK CAPACITY:\n");
    scanf("%d", &m);

    printf("WEIGHT\tVALUE\n");
    for (i = 1; i <= n; i++) {
        scanf("%d\t%d", &w[i], &v[i]);
    }

    operationCount = 0; // Resetting the operation count before the function call

    // Initialize the memoization table
    initializeMemoizationTable();

    int maxValue = knap(n, m);

    printf("THE MAXIMUM VALUE IS : %d\n", maxValue);
    printComposition(n, m);

    printf("Operation Count: %d\n", operationCount);
    fprintf(f1, "Items: %d, Capacity: %d, Operation Count: %d\n", n, m, operationCount);

    fclose(f1);
}
