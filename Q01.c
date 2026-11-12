#include <stdio.h>

void showPacks() {
    printf("Mobile Recharge\n");
    printf("1. Rs. 100\n2. Rs. 200\n3. Rs. 500\n4. Rs. 1000\n");
}

int getPack() {
    int p;
    do {
        printf("Enter pack number (1-4): ");
        scanf("%d", &p);
    } while (p < 1 || p > 4);
    return p;
}

long long getMobile() {
    long long mobile;
    do {
        printf("Enter 11 digit mobile number: ");
        scanf("%lld", &mobile);
    } while (mobile < 10000000000LL || mobile > 99999999999LL);
    return mobile;
}

int getAmount(int p) {
    switch (p) {
        case 1: return 100;
        case 2: return 200;
        case 3: return 500;
        case 4: return 1000;
        default: return 0;
    }
}

double addTax(double amount) {
    return amount + amount * 0.15;
}

double getBonus(double amount) {
    if (amount >= 500)
        return amount * 0.10;
    return 0;
}

void printSlip(long long mobile, double amount, double tax, double total) {
    printf("\n----- Recharge Slip -----\n");
    printf("Mobile Number: %lld\n", mobile);
    printf("Pack Amount: Rs. %.2lf\n", amount);
    printf("Amount with Tax: Rs. %.2lf\n", tax);
    printf("Total Balance: Rs. %.2lf\n", total);
}

int main() {
    double spent = 0;

    for (int i = 1; i <= 3; i++) {
        printf("\nRecharge %d\n", i);
        showPacks();
        int pack = getPack();
        long long mobile = getMobile();
        double amount = getAmount(pack);
        double tax = addTax(amount);
        double bonus = getBonus(amount);
        printSlip(mobile, amount, tax, amount + bonus);
        spent += amount;
    }

    printf("\nTotal money spent: Rs. %.2lf\n", spent);
    return 0;
}