#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    do {
        printf("Enter number of days (1-10): ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);

    double *temp = (double *)malloc(n * sizeof(double));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        do {
            printf("Enter temperature for day %d (-10 to 55): ", i + 1);
            scanf("%lf", temp + i);
        } while (*(temp + i) < -10 || *(temp + i) > 55);
    }

    double hottest = *temp;
    double coldest = *temp;
    int above40 = 0;
    double *ptr = temp;

    for (int i = 0; i < n; i++) {
        printf("Day %d: %.2lf at address %p\n", i + 1, *ptr, (void *)ptr);

        if (*ptr > hottest) hottest = *ptr;
        if (*ptr < coldest) coldest = *ptr;
        if (*ptr > 40) above40++;

        ptr++;
    }

    printf("Hottest temperature: %.2lf\n", hottest);
    printf("Coldest temperature: %.2lf\n", coldest);
    printf("Days hotter than 40: %d\n", above40);

    free(temp);
    temp = NULL;

    printf("Memory released successfully\n");
    return 0;
}