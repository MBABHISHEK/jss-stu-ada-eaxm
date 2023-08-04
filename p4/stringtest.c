#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int count = 0;

int stringmatching(char *text, char *pattern, int n, int m) {
    count = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            count++;
            if (pattern[j] != text[i + j])
                break;
            j++;
        }
        if (j == m) {
            printf("THE PATTERN FOUND \n");
            return count;
        }
    }
    printf("THE PATTERN not found \n");
    return count;
}

int main() {
    int m, n;
    char text[100], pattern[100];

    printf("ENTER THE PATTERN LENGTH\n");
    scanf("%d", &m);
    printf("ENTER THE PATTERN\n");
    getchar(); // Consume the newline character left in the input buffer

    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove the newline character from the input

    printf("ENTER THE TEXT LENGTH\n");
    scanf("%d", &n);
    printf("ENTER THE TEXT\n");
    getchar(); // Consume the newline character left in the input buffer

    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove the newline character from the input

    int comparisons = stringmatching(text, pattern, n, m);
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
