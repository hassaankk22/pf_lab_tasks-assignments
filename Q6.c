#include <stdio.h>
int main() {
    int data[3][3], key[3][3], encrypted[3][3];
    int max, row = 0, col = 0;

    printf("Enter data matrix:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &data[i][j]);
        }
    }
    printf("Enter key matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            encrypted[i][j] = data[i][j] * key[i][j] + i + j;
        }
    }
    max = encrypted[0][0];
    printf("Encrypted matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", encrypted[i][j]);

            if (encrypted[i][j] > max) {
                max = encrypted[i][j];
                row = i;
                col = j;
            }
        }
        printf("\n");
    }

    printf("Maximum encrypted value = %d\n", max);
    printf("Position = (%d, %d)\n", row + 1, col + 1);
}
