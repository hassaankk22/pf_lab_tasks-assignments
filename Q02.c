#include <stdio.h>

void showRooms() {
    printf("City Hospital\n");
    printf("1. General Ward Rs. 1500/day\n");
    printf("2. Semi-Private Rs. 3500/day\n");
    printf("3. Private Rs. 6000/day\n");
}

int getRoom() {
    int room;
    do {
        printf("Enter room type (1-3): ");
        scanf("%d", &room);
    } while (room < 1 || room > 3);
    return room;
}

int getDays() {
    int days;
    do {
        printf("Enter days stayed (1-30): ");
        scanf("%d", &days);
    } while (days < 1 || days > 30);
    return days;
}

double roomCharges(int room, int days) {
    if (room == 1) return 1500 * days;
    if (room == 2) return 3500 * days;
    return 6000 * days;
}

void roomName(int room, char name[]) {
    if (room == 1) {
        sprintf(name, "General Ward");
    } else if (room == 2) {
        sprintf(name, "Semi-Private");
    } else {
        sprintf(name, "Private");
    }
}

double medicineCharges() {
    double medicine;
    do {
        printf("Enter medicine bill: Rs. ");
        scanf("%lf", &medicine);
    } while (medicine < 0);
    return medicine + medicine * 0.05;
}

double finalBill(double total, int days) {
    if (days >= 7)
        total = total - total * 0.08;
    return total;
}

int main() {
    showRooms();
    int room = getRoom();
    int days = getDays();
    double rooms = roomCharges(room, days);
    double medicine = medicineCharges();
    double total = finalBill(rooms + medicine, days);

    char senior;
    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &senior);

    if (senior == 'y' || senior == 'Y') {
        total -= 1000;
        if (total < 0) total = 0;
    }

    char name[30];
    roomName(room, name);

    printf("\n----- Final Hospital Bill -----\n");
    printf("Room: %s\n", name);
    printf("Days: %d\n", days);
    printf("Room Charges: Rs. %.2lf\n", rooms);
    printf("Medicine Charges: Rs. %.2lf\n", medicine);
    printf("Final Amount: Rs. %.2lf\n", total);
    return 0;
}