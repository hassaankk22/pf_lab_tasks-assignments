#include <stdio.h>

int main() {
    double costPrice, sellPrice, quantity;
    double totalCost, totalSales, result, percentage;

    double *costPtr = &costPrice;
    double *sellPtr = &sellPrice;
    double *quantityPtr = &quantity;
    double *totalCostPtr = &totalCost;
    double *totalSalesPtr = &totalSales;
    double *resultPtr = &result;
    double *percentagePtr = &percentage;

    printf("Enter cost price: ");
    scanf("%lf", costPtr);
    printf("Enter selling price: ");
    scanf("%lf", sellPtr);
    printf("Enter quantity sold: ");
    scanf("%lf", quantityPtr);

    *totalCostPtr = *costPtr * *quantityPtr;
    *totalSalesPtr = *sellPtr * *quantityPtr;
    *resultPtr = *totalSalesPtr - *totalCostPtr;

    if (*resultPtr > 0) {
        printf("Profit\n");
        if (*totalCostPtr != 0)
            *percentagePtr = (*resultPtr / *totalCostPtr) * 100;
        else
            *percentagePtr = 0;
    } else if (*resultPtr < 0) {
        printf("Loss\n");
        if (*totalCostPtr != 0)
            *percentagePtr = (-*resultPtr / *totalCostPtr) * 100;
        else
            *percentagePtr = 0;
    } else {
        printf("No profit no loss\n");
        *percentagePtr = 0;
    }

    printf("Total Cost: %.2lf\n", *totalCostPtr);
    printf("Total Sales: %.2lf\n", *totalSalesPtr);
    printf("Profit/Loss: %.2lf\n", *resultPtr);
    printf("Percentage: %.2lf%%\n", *percentagePtr);

    double *larger;
    if (*costPtr >= *sellPtr) {
        larger = costPtr;
        printf("Pointer points to costPrice: %.2lf\n", *larger);
    } else {
        larger = sellPtr;
        printf("Pointer points to sellPrice: %.2lf\n", *larger);
    }

    printf("\nVariable and pointer addresses\n");
    printf("costPrice: %p\n", (void *)&costPrice);
    printf("sellPrice: %p\n", (void *)&sellPrice);
    printf("quantity: %p\n", (void *)&quantity);
    printf("costPtr: %p\n", (void *)&costPtr);
    printf("sellPtr: %p\n", (void *)&sellPtr);
    printf("quantityPtr: %p\n", (void *)&quantityPtr);
    printf("totalCostPtr: %p\n", (void *)&totalCostPtr);
    printf("totalSalesPtr: %p\n", (void *)&totalSalesPtr);
    printf("resultPtr: %p\n", (void *)&resultPtr);
    printf("percentagePtr: %p\n", (void *)&percentagePtr);
    printf("larger: %p\n", (void *)&larger);

    return 0;
}