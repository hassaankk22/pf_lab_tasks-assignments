#include <stdio.h>
int main() {
    float temp[3][3][3];
    float sum, avg[3];
    float max;
    int maxX = 0, maxY = 0, maxZ = 0;
    int hotLayer = 0;

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                printf("Enter temperature: ");
                scanf("%f", &temp[x][y][z]);
            }
        }
    }
    max = temp[0][0][0];
    for (int z = 0; z < 3; z++) {
        sum = 0;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                sum += temp[x][y][z];
                if (temp[x][y][z] > max) {
                    max = temp[x][y][z];
                    maxX = x;
                    maxY = y;
                    maxZ = z;
                }
            }
        }
        avg[z] = sum / 9;
        printf("Average temperature of layer %d = %.2f\n", z + 1, avg[z]);
        if (avg[z] > avg[hotLayer]) {
            hotLayer = z;
        }
    }
    printf("Hottest layer = %d\n", hotLayer + 1);
    printf("Average temperature = %.2f\n", avg[hotLayer]);
    printf("Maximum temperature = %.2f\n", max);
    printf("Position = (%d, %d, %d)\n", maxX + 1, maxY + 1, maxZ + 1);
}
