#include <stdio.h>
int main() {
    FILE *fp;
    int i, num;
    char category[12];
    float amount, total = 0;
    fp = fopen("expenses.txt", "w");

    fprintf(fp, "%-12s %9.2f\n", "Food", 1200.00);
    fprintf(fp, "%-12s %9.2f\n", "Transport", 500.00);
    fprintf(fp, "%-12s %9.2f\n", "Books", 850.00);
    fprintf(fp, "%-12s %9.2f\n", "Mobile", 300.00);

    fclose(fp);

    printf("Category: ");
    scanf("%s", category);

    printf("Amount: ");
    scanf("%f", &amount);

    fp = fopen("expenses.txt", "ab");

    fprintf(fp, "%-12s %9.2f\n", category, amount);

    fclose(fp);

    fp = fopen("expenses.txt", "rb+");
    fseek(fp, -2 * 23, SEEK_END);

    printf("Latest two:\n");

    for(i = 0; i < 2; i++) {
        fscanf(fp, "%s %f", category, &amount);

        printf("%s %.2f\n", category, amount);
    }

    printf("Entry to fix: ");
    scanf("%d", &num);

    printf("Correct amount: ");
    scanf("%f", &amount);

    if(num >= 1 && num <= 5) {
        fseek(fp, (num - 1) * 23, SEEK_SET);

        fscanf(fp, "%s", category);

        fseek(fp, (num - 1) * 23, SEEK_SET);

        fprintf(fp, "%-12s %9.2f\n", category, amount);
    }

    rewind(fp);

    total = 0;

    for(i = 0; i < 5; i++) {
        fscanf(fp, "%s %f", category, &amount);

        printf("%s %.2f\n", category, amount);

        total += amount;
    }
    printf("Total: %.2f\n", total);
    fclose(fp);
}
