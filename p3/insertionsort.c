#include <stdio.h>
#include <stdlib.h>

// Insertion Sort Function
void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
}

// Tester for Insertion Sort
void tester() {
    int *arr, n;
    printf("ENTER THE NUMBER OF ELEMENTS\n");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);
    printf("ENTER THE ELEMENTS OF THE ARRAY\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("THE ELEMENTS OF THE ARRAY BEFORE SORTING\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("THE ELEMENTS OF THE ARRAY AFTER SORTING\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

// Plotter for Insertion Sort
void plotter() {
    int *arr, n, count;
    FILE *f1, *f2, *f3;

    f1 = fopen("INSERTIONBEST.txt", "a");
    f2 = fopen("INSERTIONWORST.txt", "a");
    f3 = fopen("INSERTIONAVG.txt", "a");
    n = 10;

    while (n <= 30000) {
        arr = (int *)malloc(sizeof(int) * n);

        // Worst case
        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
        count = 0;
        insertionSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);

        // Best case
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        count = 0;
        insertionSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);

        // Average case
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % n;
        }
        count = 0;
        insertionSort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count);

        if (n < 10000) {
            n = n * 10;
        } else {
            n = n + 10000;
        }
        free(arr);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main() {
    for (;;) {
        int key;
        printf("ENTER THE CHOICE \n1. TO TEST \n2. TO PLOT\n0. TO EXIT\n");
        scanf("%d", &key);

        switch (key) {
            case 1:
                tester();
                break;
            case 2:
                plotter();
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
