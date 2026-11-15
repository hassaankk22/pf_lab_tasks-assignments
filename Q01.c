#include <stdio.h>

void recharge(int *pack_number, long long *num, int *amount, double *tax, double *bonus, double *after_bonus, double *final_balance, int *another)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Here are the available 4Recharge Packages: \n");
        printf("1. Rs 100\n2. Rs 200\n3. Rs 500\n4. Rs 1000\n");
        scanf("%d", pack_number);
        printf("Enter Your Mobile Numbers: \n");
        scanf("%lld", num);
        switch (*pack_number)
        {
        case 1:
            *amount = 100;
            break;
        case 2:
            *amount = 200;
            break;
        case 3:
            *amount = 500;
            break;
        case 4:
            *amount = 1000;
            break;
        default:
            printf("Invalid Pack Number!\n");
            continue;
        }
        *after_bonus = *amount;
        *tax = *amount * 0.15;
        if (*amount >= 500)
        {
            *bonus = *amount * 0.1;
            *after_bonus = *amount + *bonus;
        }
        *final_balance = *final_balance + (*after_bonus - *tax);
        *bonus = 0;
        printf("ANother Charge: (0 = Yes 1 = No)\n");
        scanf("%d", another);
        if (*another == 1)
            break;
    }
}

int main()
{
    int pack_number = 0;
    long long num = 0;
    int amount = 0, another = 0;
    double tax = 0, bonus = 0, after_bonus = 0, final_balance = 0;
    for (int i = 0; i < 3; i++)
    {
        recharge(&pack_number, &num, &amount, &tax, &bonus, &after_bonus, &final_balance, &another);
        printf("\n========== RECHARGE DETAILS ==========\n");

        printf("Pack Number: %d\n", pack_number);
        printf("Mobile Number: %lld\n", num);
        printf("Amount Before Tax: Rs %d\n", amount);
        printf("Bonus: Rs %.2lf\n", bonus);
        printf("Tax: Rs %.2lf\n", tax);
        printf("Amount After Tax: Rs %.2lf\n", final_balance);
        if (another == 1)
            break;
    }
}
