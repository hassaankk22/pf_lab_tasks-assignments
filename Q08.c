#include <stdio.h>
#include <stdlib.h>

void display(int *p, int n) {
    if (n == 0) {
        printf("Stock is empty\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("Item %d: %d\n", i + 1, *(p + i));
}

void showTotalAndLowest(int *p, int n) {
    if (n == 0) {
        printf("No items in stock\n");
        return;
    }

    int total = 0;
    int lowest = *p;

    for (int i = 0; i < n; i++) {
        total += *(p + i);
        if (*(p + i) < lowest) lowest = *(p + i);
    }

    printf("Total stock: %d\n", total);
    printf("Lowest stock: %d\n", lowest);
}

int main() {
    int n;
    do {
        printf("Enter starting size (3-8): ");
        scanf("%d", &n);
    } while (n < 3 || n > 8);

    int *stock = (int *)malloc(n * sizeof(int));

    if (stock == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter stock of item %d: ", i + 1);
        scanf("%d", stock + i);
    }

    int choice;

    do {
        printf("\n1. Display stock\n");
        printf("2. Update stock\n");
        printf("3. Insert item\n");
        printf("4. Delete item\n");
        printf("5. Sort stock\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            display(stock, n);
        } else if (choice == 2) {
            int pos, value;
            printf("Enter item position: ");
            scanf("%d", &pos);

            if (pos >= 1 && pos <= n) {
                printf("Enter new stock value: ");
                scanf("%d", &value);
                stock[pos - 1] = value;
                showTotalAndLowest(stock, n);
            } else {
                printf("Invalid position\n");
            }
        } else if (choice == 3) {
            int pos, value;
            printf("Enter position to insert (1-%d): ", n + 1);
            scanf("%d", &pos);

            if (pos >= 1 && pos <= n + 1) {
                printf("Enter new item stock: ");
                scanf("%d", &value);

                int *newStock = (int *)malloc((n + 1) * sizeof(int));

                if (newStock == NULL) {
                    printf("Memory allocation failed\n");
                } else {
                    for (int i = 0; i < pos - 1; i++)
                        newStock[i] = stock[i];

                    newStock[pos - 1] = value;

                    for (int i = pos; i < n + 1; i++)
                        newStock[i] = stock[i - 1];

                    free(stock);
                    stock = newStock;
                    n++;
                    showTotalAndLowest(stock, n);
                }
            } else {
                printf("Invalid position\n");
            }
        } else if (choice == 4) {
            int pos;
            printf("Enter position to delete: ");
            scanf("%d", &pos);

            if (pos >= 1 && pos <= n) {
                int *newStock = NULL;

                if (n > 1) {
                    newStock = (int *)malloc((n - 1) * sizeof(int));
                    if (newStock == NULL) {
                        printf("Memory allocation failed\n");
                    }
                }

                if (n == 1 || newStock != NULL) {
                    for (int i = 0; i < pos - 1; i++)
                        newStock[i] = stock[i];

                    for (int i = pos - 1; i < n - 1; i++)
                        newStock[i] = stock[i + 1];

                    free(stock);
                    stock = newStock;
                    n--;
                    showTotalAndLowest(stock, n);
                }
            } else {
                printf("Invalid position\n");
            }
        } else if (choice == 5) {
            for (int i = 0; i < n - 1; i++) {
                for (int *p = stock; p < stock + n - i - 1; p++) {
                    if (*p > *(p + 1)) {
                        int temp = *p;
                        *p = *(p + 1);
                        *(p + 1) = temp;
                    }
                }
            }
            display(stock, n);
            showTotalAndLowest(stock, n);
        } else if (choice != 6) {
            printf("Invalid choice\n");
        }

    } while (choice != 6);

    free(stock);
    printf("Memory released\n");
    return 0;
}