#include <stdio.h>
#include <string.h>

int main() {
    char message[500], updated[1000];
    char *p, *pos;
    char part[500];

    printf("Enter customer feedback: ");
    gets(message);

    printf("Total characters: %d\n", strlen(message));

    if (strstr(message, "good") != NULL)
        printf("The word good exists\n");
    else
        printf("The word good does not exist\n");
    if (strstr(message, "bad") != NULL)
        printf("The word bad exists\n");
    else
        printf("The word bad does not exist\n");
    strcpy(updated, "");
    p = message;

    while ((pos = strstr(p, "bad")) != NULL) {
        strncpy(part, p, pos - p);
        part[pos - p] = '\0';
        strcat(updated, part);
        strcat(updated, "not good");
        p = pos + 3;
    }
    strcat(updated, p);
    printf("Updated feedback: %s\n", updated);
}
