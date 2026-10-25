
#include <stdio.h>

#define P 5
#define R 3

int main() {
    int allocation[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int available[R] = {3, 3, 2};

    int need[P][R];
    int finish[P] = {0};
    int safeSeq[P];
    int work[R];
    int count = 0;

    // Step 1: Calculate Need Matrix
    printf("Need Matrix:\n");

    for (int i = 0; i < P; i++) {
        printf("P%d: ", i);

        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }

        printf("\n");
    }

    // Step 2: Initialize Work
    for (int j = 0; j < R; j++)
        work[j] = available[j];

    // Step 3: Apply Safety Algorithm
    while (count < P) {
        int found = 0;

        for (int i = 0; i < P; i++) {
            if (finish[i] == 0) {
                int j;

                for (j = 0; j < R; j++) {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == R) {
                    // Process can complete
                    for (int k = 0; k < R; k++)
                        work[k] += allocation[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("\nSystem is in UNSAFE state.\n");
            return 0;
        }
    }

    // Step 4: Print Safe Sequence
    printf("\nSystem is in SAFE state.\n");
    printf("Safe Sequence: ");

    for (int i = 0; i < P; i++) {
        printf("P%d", safeSeq[i]);

        if (i < P - 1)
            printf(" -> ");
    }

    printf("\n");

    return 0;
}
