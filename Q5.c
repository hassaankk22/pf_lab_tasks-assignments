#include<stdio.h>
int main(){
    int note500[5] = {10,23,32,12,13};
    int note1000[5] = {12,32,22,24,17};
    int note100[5] = {40,35,45,67,23};
    int transaction[5], totalMoney[5];
    
    for(int i = 0; i<5 ; i++){
        printf("Enter Amount: \n");
        scanf("%d" , &transaction[i]);
        totalMoney[i] = (note1000[i]*1000) + (note100[i]*100) + (note500[i] *500);
        printf("Amount Available: %d\n", totalMoney[i] );
        if(transaction[i]> totalMoney[i]){
        printf("Insufficient Funds Available\n");
        }
        else if(transaction[i] %100 !=0){
            printf("Invalid Amount\n");
        }
        else
        printf("Transaction Approved\n");
    }
}