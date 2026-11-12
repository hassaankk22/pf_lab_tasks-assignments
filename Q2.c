#include <stdio.h>
#include <string.h>

int main() {
    char names[10][50];
    char temp[50];

    for (int i = 0; i < 10; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
    printf("\nNames in alphabetical order:\n");

    for (int i = 0; i < 10; i++) {
        printf("%s\n", names[i]);
    }

}
