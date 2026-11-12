#include <stdio.h>

void showRules() {
    printf("Taxi Fare System\n");
    printf("Base fare Rs. 150\n");
    printf("First 10 km: Rs. 60 per km\n");
    printf("After 10 km: Rs. 45 per km\n");
}

double getDistance() {
    double km;
    do {
        printf("Enter distance in km (more than 0 up to 200): ");
        scanf("%lf", &km);
    } while (km <= 0 || km > 200);
    return km;
}

int getWaiting() {
    int minutes;
    do {
        printf("Enter waiting time (0-120 minutes): ");
        scanf("%d", &minutes);
    } while (minutes < 0 || minutes > 120);
    return minutes;
}

double distanceCharge(double km) {
    if (km <= 10)
        return 150 + km * 60;
    return 150 + 10 * 60 + (km - 10) * 45;
}

double waitingCharge(int minutes) {
    if (minutes <= 5) return 0;
    return (minutes - 5) * 10;
}

double nightFare(double fare, int hour) {
    if (hour >= 22 || hour < 6)
        fare += fare * 0.25;
    return fare;
}

int main() {
    double earnings = 0;
    double highest = 0;

    showRules();

    for (int i = 1; i <= 3; i++) {
        printf("\nTrip %d\n", i);
        double km = getDistance();
        int waiting = getWaiting();
        int hour;

        do {
            printf("Enter trip hour (0-23): ");
            scanf("%d", &hour);
        } while (hour < 0 || hour > 23);

        double fare = distanceCharge(km) + waitingCharge(waiting);
        fare = nightFare(fare, hour);

        printf("\n----- Trip Receipt -----\n");
        printf("Distance: %.2lf km\n", km);
        printf("Waiting Time: %d minutes\n", waiting);
        printf("Final Fare: Rs. %.2lf\n", fare);

        earnings += fare;
        if (fare > highest) highest = fare;
    }

    printf("\nTotal Earnings: Rs. %.2lf\n", earnings);
    printf("Highest Fare of the Day: Rs. %.2lf\n", highest);
    return 0;
}