#include <stdio.h>
int main() {
    int a[3][3];
    int valid = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);

            if (a[i][j] < 0 || a[i][j] > 9) {
                valid = 0;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (i != x || j != y) {
                        if (a[i][j] != 0 && a[i][j] == a[x][y]) {
                            valid = 0;
                        }
                    }
                }
            }
        }
    }

    if (valid == 1)
        printf("Valid Grid");
    else
        printf("Invalid Grid");

}
