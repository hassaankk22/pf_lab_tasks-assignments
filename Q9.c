#include<stdio.h>
int main(){
    int transfers[10] = {5000, 50, 12000, 500000, 20, 8000, 25000, 300, 450000, 15000};
    int small =0, large = 0, normal = 0, normalSum = 0 , largest = 0, totalFlagged;
    double avg;
    for(int i = 0; i<10 ; i++)
    {
        if(transfers[i] <100)
        {
            printf("Amount too Small for Transfer(%d)\n", i+1);
            small++;
        }

        if(transfers[i] > 200000)
        {
            printf("Amount too large for Transfer(%d)\n" , i+1);
            large++;
        }

        if(transfers[i]>=100 && transfers[i]<=200000)
        {
            normal++;
            normalSum = normalSum + transfers[i];
        }
        if(transfers[i] > largest)
        largest = transfers[i];
    }
    totalFlagged = small + large;
    printf("Total FLagged Transfers is %d\n" , totalFlagged);

    avg = (double)normalSum/normal;
    printf("Average of Normal Transfers is : %.2f\n" , avg);
    printf("Largest Transfer Amount is: %d" , largest);

}