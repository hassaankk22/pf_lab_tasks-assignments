#include <stdio.h>
int main() {
    int S[3][3], P[3][2], D[3][2];
    int R[3][2], R2[3][2];
    int profit[3], profit2[3];
    int i, j, k, max, max2;

    printf("Quantity #1 = Charger\nQuantity #2 = Earphone\nQuantity #3 = Cover\n");
    printf("Enter sales quantities (3x3):\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Product #%d : \n" , j+1 );
            scanf("%d", &S[i][j]);
        }
        printf("Branch #%d\n\n" , j+1);
    }

    printf("Enter Cost Price and Selling Price:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 2; j++){
        printf("Product #%d: \n" , i+1);
            scanf("%d", &P[i][j]);
        }
        printf("Branch #%d\n\n" , j+1);
    }

        // Multiply 
        
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            R[i][j] = 0;
            for(k = 0; k < 3; k++)
                R[i][j] += S[i][k] * P[k][j];
        }
    }

    printf("\nOriginal Results:\n");
    max = 0;

    for(i = 0; i < 3; i++) {
        profit[i] = R[i][1] - R[i][0];

        printf("Branch %d: Cost = %d, Sales = %d, Profit = %d\n",
               i+1, R[i][0], R[i][1], profit[i]);

        if(profit[i] > max)
            max = profit[i];
    }

    //  discount
    for(i = 0; i < 3; i++) {
        D[i][0] = P[i][0];
        D[i][1] = P[i][1] * 90 / 100;
    }

    // Multiply
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            R2[i][j] = 0;
            for(k = 0; k < 3; k++)
                R2[i][j] += S[i][k] * D[k][j];
        }
    }

    printf("\n\nAfter 10%% Discount:\n");

    for(i = 0; i < 3; i++) {
        profit2[i] = R2[i][1] - R2[i][0];

        printf("Branch %d: Cost = %d, Sales = %d, Profit = %d\n", i+1, R2[i][0], R2[i][1], profit2[i]);
    }
}
