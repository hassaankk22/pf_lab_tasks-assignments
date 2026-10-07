#include<stdio.h>
int main(){
    int amount,count =0,totalAmount=0;
    printf("Enter 0 to End the transactions!\n");
    while(1)
    {
        printf("Enter Amount: \n");
        scanf("%d" , &amount);
        totalAmount += amount;
        if(amount!=0)
        count++;
        if(amount ==0)
        break;
    }

    printf("Total Transactions : %d\n" , count);
    printf("Total Transaction Amount : %d" , totalAmount);
}