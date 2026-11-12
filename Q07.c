#include <stdio.h>

int findMax(int *p, int n) {
    int highest = *p;
    for (int i = 1; i < n; i++) {
        if (*(p + i) > highest) highest = *(p + i);
    }
    return highest;
}

int findMin(int *p, int n) {
    int lowest = *p;
    for (int i = 1; i < n; i++) {
        if (*(p + i) < lowest) lowest = *(p + i);
    }
    return lowest;
}

double findAverage(int *p, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += *(p + i);
    return (double)sum / n;
}

int countAbove(int *p, int n, double avg) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(p + i) > avg) count++;
    }
    return count;
}

void reverseArray(int *p, int n) {
    int *start = p;
    int *end = p + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int search(int *p, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (*(p + i) == key) return i + 1;
    }
    return -1;
}

int main() {
    int marks[10];

    for (int i = 0; i < 10; i++) {
        do {
            printf("Enter mark of student %d (0-100): ", i + 1);
            scanf("%d", &marks[i]);
        } while (marks[i] < 0 || marks[i] > 100);
    }

    printf("\nMarks before reversing: ");
    for (int i = 0; i < 10; i++) printf("%d ", marks[i]);

    double avg = findAverage(marks, 10);

    printf("\nHighest: %d\n", findMax(marks, 10));
    printf("Lowest: %d\n", findMin(marks, 10));
    printf("Average: %.2lf\n", avg);
    printf("Students above average: %d\n", countAbove(marks, 10, avg));

    int pass = 0;
    for (int i = 0; i < 10; i++) {
        if (marks[i] >= 40) pass++;
    }
    printf("Pass count: %d\n", pass);

    int key;
    printf("Enter mark to search: ");
    scanf("%d", &key);
    int position = search(marks, 10, key);

    if (position == -1) printf("Mark not found\n");
    else printf("Mark found at position %d\n", position);

    reverseArray(marks, 10);

    printf("Marks after reversing: ");
    for (int i = 0; i < 10; i++) printf("%d ", marks[i]);
    printf("\n");

    return 0;
}