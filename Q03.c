#include <stdio.h>

void showRoutes() {
    printf("Bus Ticket Booking\n");
    printf("1. Karachi to Hyderabad - Rs. 800\n");
    printf("2. Karachi to Sukkur - Rs. 2200\n");
    printf("3. Karachi to Multan - Rs. 3500\n");
}

int getRoute() {
    int route;
    do {
        printf("Enter route number (1-3): ");
        scanf("%d", &route);
    } while (route < 1 || route > 3);
    return route;
}

int getSeats() {
    int seats;
    do {
        printf("Enter number of seats (1-6): ");
        scanf("%d", &seats);
    } while (seats < 1 || seats > 6);
    return seats;
}

int seatFare(int route) {
    if (route == 1) return 800;
    if (route == 2) return 2200;
    return 3500;
}

void routeName(int route, char name[]) {
    if (route == 1) {
        sprintf(name, "Karachi to Hyderabad");
    } else if (route == 2) {
        sprintf(name, "Karachi to Sukkur");
    } else {
        sprintf(name, "Karachi to Multan");
    }
}

double finalFare(double total, char type) {
    if (type == 'B' || type == 'b')
        total += total * 0.30;
    return total;
}

int main() {
    double earnings = 0;

    for (int i = 1; i <= 2; i++) {
        printf("\nPassenger %d\n", i);
        showRoutes();
        int route = getRoute();
        int seats = getSeats();
        char type;

        do {
            printf("Seat type Economy (E) or Business (B): ");
            scanf(" %c", &type);
        } while (type != 'E' && type != 'e' && type != 'B' && type != 'b');

        double total = seatFare(route) * seats;
        double fare = finalFare(total, type);

        char name[50];
        routeName(route, name);

        printf("\n----- Bus Ticket -----\n");
        printf("Route: %s\n", name);
        printf("Seats: %d\n", seats);
        printf("Seat Type: %s\n", (type == 'E' || type == 'e') ? "Economy" : "Business");
        printf("Final Fare: Rs. %.2lf\n", fare);

        earnings += fare;
    }

    printf("\nTotal Bus Earnings: Rs. %.2lf\n", earnings);
    return 0;
}