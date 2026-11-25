#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp;
    int i, room, nights, r[10], n;
    char status, name[21], guests[10][21], search[21];
    float rate, bill;
    int found;
    fp = fopen("hotel.txt", "w");
    for(i = 0; i < 10; i++) {
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                101+i, 'F', "-", 0, 8000.00);
    }

    fclose(fp);

    fp = fopen("hotel.txt", "rb+");

    printf("Check-in room: ");
    scanf("%d", &room);

    printf("Name: ");
    scanf("%s", name);

    printf("Nights: ");
    scanf("%d", &nights);

    if(room >= 101 && room <= 110 && nights > 0) {
        fseek(fp, (room - 101) * 39, SEEK_SET);

        fscanf(fp, "%d %c %s %d %f",
               &r[0], &status, guests[0], &n, &rate);

        if(status == 'F') {
            fseek(fp, (room - 101) * 39, SEEK_SET);

            fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                    room, 'B', name, nights, 8000.00);

            printf("Room %d booked\n", room);
        }
        else {
            printf("Room already booked\n");
        }
    }

    rewind(fp);

    for(i = 0; i < 10; i++) {
        fscanf(fp, "%d %c %20s %d %f",
               &r[i], &status, guests[i], &n, &rate);
    }

    printf("Search name: ");
    scanf("%s", search);

     found = 0;
    for(i = 0; i < 10; i++) {
        if(strcmp(guests[i], search) == 0) {
            printf("%s is in room %d\n", search, r[i]);
            found = 1;
        }
    }
    if(found == 0)
        printf("Guest not found\n");

    printf("Check-out room: ");
    scanf("%d", &room);

    if(room >= 101 && room <= 110) {
        fseek(fp, (room - 101) * 39, SEEK_SET);

        fscanf(fp, "%d %c %s %d %f",
               &r[0], &status, name, &nights, &rate);

        if(status == 'B') {
            bill = nights * rate;

            printf("Bill: %d x %.2f = %.2f\n",
                   nights, rate, bill);

            fseek(fp, (room - 101) * 39, SEEK_SET);

            fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                    room, 'F', "-", 0, 8000.00);
        }
        else {
            printf("Room is already free\n");
        }
    }
    fclose(fp);
}
