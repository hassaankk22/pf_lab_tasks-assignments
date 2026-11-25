#include <stdio.h>
#include <string.h>

int countRepeat(char s[], int i) {
    if(s[i] == '\0')
        return 0;

    if(s[i] != s[i+1])
        return 1;

    return 1 + countRepeat(s, i+1);
}

void compress(char s[], int i, char out[], int j) {
    int count;

    if(s[i] == '\0') {
        out[j] = '\0';
        return;
    }

    count = countRepeat(s, i);

    out[j] = s[i];
    out[j+1] = count + '0';

    compress(s, i+count, out, j+2);
}

void expand(char in[], int i, char out[], int j) {
    int count, k;

    if(in[i] == '\0') {
        out[j] = '\0';
        return;
    }

    count = in[i+1] - '0';

    for(k = 0; k < count; k++) {
        out[j] = in[i];
        j++;
    }

    expand(in, i+2, out, j);
}

int main() {
    char s[100], compressed[200], expanded[200];

    printf("Enter original string: ");
    scanf("%s", s);

    compress(s, 0, compressed, 0);
    printf("Original: %s\n", s);
    printf("Compressed: %s\n", compressed);

    expand(compressed, 0, expanded, 0);

    printf("Expanded: %s\n", expanded);

    if(strcmp(s, expanded) == 0)
        printf("Match: Yes\n");
    else
        printf("Match: No\n");
}
