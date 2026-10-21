#include <stdio.h>
int main() {
    int sales[4][5];
    int total[4] = {0};
    int product[5] = {0};
    int maxProduct = 0;
    float final[4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Enter sales for salesman %d product %d: ", i + 1, j + 1);
            scanf("%d", &sales[i][j]);
            total[i] += sales[i][j];
            product[j] += sales[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("Total sales of salesman %d = %d\n", i + 1, total[i]);

        if (total[i] > 10000) {
            final[i] = total[i] + total[i] * 0.10;
            printf("Bonus applied\n");
        } else {
            final[i] = total[i];
            printf("No bonus\n");
        }

        printf("Final amount = %.2f\n", final[i]);
    }

    for (int j = 0; j < 5; j++) {
        printf("Total sales of product %d = %d\n", j + 1, product[j]);

        if (product[j] > product[maxProduct]) {
            maxProduct = j;
        }
    }

    printf("Best selling product = %d\n", maxProduct + 1);

}
