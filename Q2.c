#include <stdio.h>
int main() {
    FILE *fp;
    int i, roll, lectures, leave;
    char name[15];
    float per;

    fp = fopen("attendance.txt", "w");

    fprintf(fp, "%-3d %-15s %3d\n", 1, "Ayesha", 18);
    fprintf(fp, "%-3d %-15s %3d\n", 2, "Bilal", 14);
    fprintf(fp, "%-3d %-15s %3d\n", 3, "Hamza", 20);
    fprintf(fp, "%-3d %-15s %3d\n", 4, "Sana", 12);
    fprintf(fp, "%-3d %-15s %3d\n", 5, "Zainab", 16);

    fclose(fp);

    fp = fopen("attendance.txt", "rb+");

    printf("Roll number: ");
    scanf("%d", &roll);

    if(roll >= 1 && roll <= 5) {
        fseek(fp, (roll - 1) * 24, SEEK_SET);

        fscanf(fp, "%d %s %d", &i, name, &lectures);

        per = lectures * 100.0 / 20;

        printf("%s: %d / 20 (%.1f%%)", name, lectures, per);

        if(per < 75)
            printf(" Short attendance");

        printf("\n");
    }
    else {
        printf("Invalid roll number\n");
    }

    printf("Roll number for leave: ");
    scanf("%d", &roll);

    printf("Lectures: ");
    scanf("%d", &leave);

    if(roll >= 1 && roll <= 5 && leave >= 0) {
        fseek(fp, (roll - 1) * 24, SEEK_SET);

        fscanf(fp, "%d %s %d", &i, name, &lectures);

        lectures += leave;

        if(lectures > 20)
            lectures = 20;

        fseek(fp, (roll - 1) * 24, SEEK_SET);

        fprintf(fp, "%-3d %-15s %3d\n", i, name, lectures);

        printf("%s: now %d / 20 (%.1f%%)\n",
               name, lectures, lectures * 100.0 / 20);
    }

    fseek(fp, -24, SEEK_END);

    fscanf(fp, "%d %s %d", &i, name, &lectures);

    printf("Last record: %d %s %d\n", i, name, lectures);

    fclose(fp);
}
