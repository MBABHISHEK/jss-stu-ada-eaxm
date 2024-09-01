#include <stdio.h>
#include <stdlib.h>

int bubblesort(int *a, int n) {
    int count = 0;
    int i, j, t, flag;

    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            count++;
            if (a[j] > a[j + 1]) {
                t = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = t;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    return count;
}

void plotter() {
    int *arr, n;
    FILE *f1, *f2, *f3;

    f1 = fopen("BUBBLEBEST.txt", "a");
    f2 = fopen("BUBBLEWORST.txt", "a");
    f3 = fopen("BUBBLEAVG.txt", "a");
    n = 10;

    while (n <= 30000) {
        arr = (int *)malloc(sizeof(int) * n);

        // Worst case
        for (int i = 0; i < n; i++) {
            *(arr + i) = n - i;
        }
        int count = bubblesort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);

        // Best case
        for (int i = 0; i < n; i++) {
            *(arr + i) = i + 1;
        }
        count = bubblesort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);

        // Average case
        for (int i = 0; i < n; i++) {
            *(arr + i) = rand() % n;
        }
        count = bubblesort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count);

        if (n < 10000) {
            n *= 10;
        } else {
            n += 10000;
        }
        free(arr);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

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

    bubblesort(arr, n);

    printf("THE ELEMENTS OF THE ARRAY AFTER SORTING\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main() {  // Changed to int and added return 0
    for (;;) {
        int key;
        printf("ENTER THE CHOICE \n1.TO TEST \n2.TO PLOT\n0 TO EXIT\n");
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
