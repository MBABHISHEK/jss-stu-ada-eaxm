#include<stdio.h>
#include<stdlib.h>

int count = 0;

typedef struct queue {
    int f, r, *arr, cnt;
} QUE;

int s[10];

void indegree(int *a[], int v, int inq[], QUE *temp, int flag[]) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (a[j][i] == 1)
                inq[i] = inq[i] + 1;
        }
        if (inq[i] == 0) {
            temp->r = (temp->r + 1) % v;
            temp->arr[temp->r] = i;
            temp->cnt = temp->cnt + 1;
            flag[i] = 1;
        }
    }
}

void sourceremove(int *a[], int v, QUE *temp, int inq[], int flag[]) {
    int cnt = 0;
    while (temp->cnt != 0) {
        int source = temp->arr[temp->f];
        temp->f = (temp->f + 1) % v;
        s[cnt] = source;
        temp->cnt = temp->cnt - 1;
        cnt++;
        count++;
        for (int i = 0; i < v; i++) {
            if (a[source][i] == 1)
                inq[i] = inq[i] - 1;
            if (inq[i] == 0 && flag[i] == 0) {
                temp->r = (temp->r + 1) % v;
                temp->arr[temp->r] = i;
                temp->cnt = temp->cnt + 1;
                flag[i] = 1;
            }
        }
    }

    if (cnt != v) {
        printf("Cycles exist, no topological sorting possible\n");
    } else {
        printf("The topological sorting is\n");
        for (int i = 0; i < v; i++)
            printf("%c\t", s[i] + 65);
    }
}

void ploter(int k) {
    FILE *f1 = fopen("TopSortBEST.txt", "a");
    FILE *f2 = fopen("TopSortWORST.txt", "a");
    int v;

    for (int i = 1; i <= 10; i++) {
        v = i;
        int *arr[v];
        for (int j = 0; j < v; j++)
            arr[j] = (int *)malloc(sizeof(int) * v);

        if (k == 0) { // Best case: Complete graph (no cycles)
            for (int j = 0; j < v; j++) {
                for (int l = 0; l < v; l++) {
                    if (j != l)
                        arr[j][l] = 1;
                    else
                        arr[j][l] = 0;
                }
            }
        }

        if (k == 1) { // Worst case: Chain graph (linear, no cycles)
            for (int j = 0; j < v; j++) {
                for (int l = 0; l < v; l++)
                    arr[j][l] = 0;
            }
            for (int j = 0; j < v - 1; j++) {
                arr[j][j + 1] = 1;
            }
        }

        QUE q;
        q.f = 0;
        q.r = -1;
        q.cnt = 0;
        q.arr = (int*)malloc(sizeof(int) * v);

        int *inq = (int *)malloc(sizeof(int) * v);
        for (int j = 0; j < v; j++)
            inq[j] = 0;

        int *flag = (int *)malloc(sizeof(int) * v);
        for (int j = 0; j < v; j++)
            flag[j] = 0;

        indegree(arr, v, inq, &q, flag);
        sourceremove(arr, v, &q, inq, flag);

        if (k == 0)
            fprintf(f2, "%d\t%d\n", v, count);
        else
            fprintf(f1, "%d\t%d\n", v, count);

        count = 0; // Reset count for the next graph

        for (int j = 0; j < v; j++)
            free(arr[j]);
        free(q.arr);
        free(inq);
        free(flag);
    }

    fclose(f1);
    fclose(f2);
}

void main() {
    for (int i = 0; i < 2; i++)
        ploter(i);
}
