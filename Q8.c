#include <stdio.h>
int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        printf("    |    ");

        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        printf("    |    ");

        for (int j = 0; j < i; j++) {
            printf("%c ", 'A' + j);
        }

        printf("\n");
    }

    printf("\n");

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }

        printf("    |    ");

        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("%d ", j);
        }

        printf("    |    ");

        for (int j = 0; j < 2 * i - 1; j++) {
            printf("%c ", 'A' + j);
        }

        printf("\n");
    }
}
