#include <stdio.h>
#include <string.h>

void readMarks(int *m1, int *m2, int *m3) {
    do {
        printf("Enter subject 1 marks (0-100): ");
        scanf("%d", m1);
    } while (*m1 < 0 || *m1 > 100);

    do {
        printf("Enter subject 2 marks (0-100): ");
        scanf("%d", m2);
    } while (*m2 < 0 || *m2 > 100);

    do {
        printf("Enter subject 3 marks (0-100): ");
        scanf("%d", m3);
    } while (*m3 < 0 || *m3 > 100);
}

void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest) {
    *total = m1 + m2 + m3;
    *average = *total / 3.0;

    *highest = m1;
    if (m2 > *highest) *highest = m2;
    if (m3 > *highest) *highest = m3;

    *lowest = m1;
    if (m2 < *lowest) *lowest = m2;
    if (m3 < *lowest) *lowest = m3;
}

void swapMarks(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addGraceMarks(int *mark, int grace) {
    if (*mark >= 35 && *mark <= 39) {
        if (grace > 5) grace = 5;
        if (grace < 0) grace = 0;
        *mark += grace;
        if (*mark > 40) *mark = 40;
    }
}

void findGrade(double avg, char *grade, char remarks[]) {
    if (avg >= 80) {
        *grade = 'A';
        strcpy(remarks, "Excellent");
    } else if (avg >= 70) {
        *grade = 'B';
        strcpy(remarks, "Good");
    } else if (avg >= 50) {
        *grade = 'C';
        strcpy(remarks, "Needs Improvement");
    } else {
        *grade = 'F';
        strcpy(remarks, "Needs Improvement");
    }
}

void incrementByValue(int x) {
    x++;
    printf("Inside incrementByValue: %d\n", x);
}

void incrementByReference(int *x) {
    (*x)++;
    printf("Inside incrementByReference: %d\n", *x);
}

int main() {
    printf("Student\tTotal\tAverage\tHighest\tLowest\tGrade\tRemark\n");

    for (int i = 1; i <= 5; i++) {
        printf("\nStudent %d\n", i);

        int m1, m2, m3;
        readMarks(&m1, &m2, &m3);

        int grace;
        do {
            printf("Enter grace marks (0-5): ");
            scanf("%d", &grace);
        } while (grace < 0 || grace > 5);

        addGraceMarks(&m1, grace);
        addGraceMarks(&m2, grace);
        addGraceMarks(&m3, grace);

        if (m1 < m2) swapMarks(&m1, &m2);
        if (m1 < m3) swapMarks(&m1, &m3);
        if (m2 < m3) swapMarks(&m2, &m3);

        int total, highest, lowest;
        double average;
        calculateStats(m1, m2, m3, &total, &average, &highest, &lowest);

        char grade;
        char remarks[30];
        findGrade(average, &grade, remarks);

        printf("Student %d\t%d\t%.2lf\t%d\t%d\t%c\t%s\n",
               i, total, average, highest, lowest, grade, remarks);
    }

    int x = 5;
    printf("\nStarting value: %d\n", x);
    incrementByValue(x);
    printf("After incrementByValue: %d\n", x);
    incrementByReference(&x);
    printf("After incrementByReference: %d\n", x);

    return 0;
}