#include <stdio.h>
int main() {
    FILE *fp;
    char city[5][10], name[10];
    float temp[5], t, max;
    int i, num;

    fp = fopen("temperature.txt", "w");

    for(i = 0; i < 5; i++) {
        printf("Enter city name: ");
        scanf("%s", city[i]);

        printf("Enter temperature: ");
        scanf("%f", &temp[i]);

        fprintf(fp, "%-10s %5.1f\n", city[i], temp[i]);
    }

    fclose(fp);

    fp = fopen("temperature.txt", "rb+");


    printf("City number: ");
    scanf("%d", &num);

    if(num >= 1 && num <= 5) {
        fseek(fp, (num - 1) * 17, SEEK_SET);

        fscanf(fp, "%s %f", name, &t);

        printf("%s %.1f\n", name, t);
    }


    printf("City number to correct: ");
    scanf("%d", &num);

    if(num >= 1 && num <= 5) {
        printf("New temperature: ");
        scanf("%f", &t);

        fseek(fp, (num - 1) * 17, SEEK_SET);

        fscanf(fp, "%s", name);

        fseek(fp, (num - 1) * 17, SEEK_SET);

        fprintf(fp, "%-10s %5.1f\n", name, t);

        printf("%s updated to %.1f\n", name, t);
    }

    rewind(fp);

    max = -1000;

    for(i = 0; i < 5; i++) {
        fscanf(fp, "%s %f", name, &t);

        if(t > max) {
            max = t;
            for(int j = 0; name[j] != '\0'; j++)
                city[0][j] = name[j];
        }
    }

    printf("Hottest city: %s (%.1f)\n", city[0], max);

    fclose(fp);
}
