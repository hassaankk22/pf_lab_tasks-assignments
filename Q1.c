#include <stdio.h>
int main() {
    FILE *fp;
    int i, itemNo, qty, stock;
    char name[20];
    float price, total = 0;
    fp = fopen("items.txt", "w");

    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 1, "Rice", 250.00, 40);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 2, "Sugar", 160.00, 25);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 3, "Milk", 220.00, 30);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 4, "CookingOil", 560.00, 12);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 5, "Tea", 450.00, 18);

    fclose(fp);

    fp = fopen("items.txt", "rb+");

    while(1) {
        printf("Item no: ");
        scanf("%d", &itemNo);

        if(itemNo == 0)
            break;

        printf("Quantity: ");
        scanf("%d", &qty);

        if(itemNo < 1 || itemNo > 5 || qty <= 0) {
            printf("Invalid input\n");
            continue;
        }

        fseek(fp, (itemNo - 1) * 42, SEEK_SET);

        fscanf(fp, "%d %s %f %d", &i, name, &price, &stock);

        if(qty <= stock) {
            printf("%s %d x %.2f = %.2f\n",
                   name, qty, price, qty * price);

            total += qty * price;
            stock -= qty;

            fseek(fp, (itemNo - 1) * 42, SEEK_SET);

            fprintf(fp, "%-4d %-20s %9.2f %5d\n",
                    i, name, price, stock);
        }
        else {
            printf("Only %d %s in stock\n", stock, name);
        }
    }

    printf("Total bill: %.2f\n", total);

    fclose(fp);
}
