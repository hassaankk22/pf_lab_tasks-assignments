#include <stdio.h>
int finalBalance(int trans[], int n, int balance) {
    if(n == 0)
        return balance;

    balance += trans[n-1];

    return finalBalance(trans, n-1, balance);
}

int totalDeposits(int trans[], int n) {
    if(n == 0)
        return 0;

    if(trans[n-1] > 0)
        return trans[n-1] + totalDeposits(trans, n-1);

    return totalDeposits(trans, n-1);
}

int copyLarge(int trans[], int i, int n, int large[], int k) {
    if(i == n)
        return k;

    if(trans[i] <= -10000) {
        large[k] = trans[i];
        k++;
    }

    return copyLarge(trans, i+1, n, large, k);
}
int main() {
    int trans[7] = {20000, -5000, -12000, 8000,
                    -25000, -2500, 15000};

    int large[7];
    int balance = 20000;
    int deposits, final, count, i;
    final = finalBalance(trans, 7, balance);
    printf("Final balance: %d\n", final);

    deposits = totalDeposits(trans, 7);
    printf("Total deposits: %d\n", deposits);
    count = copyLarge(trans, 0, 7, large, 0);

    printf("Large withdrawals (%d): ", count);
    for(i = 0; i < count; i++)
        printf("%d ", large[i]);

    printf("\n");
}
