#include<stdio.h>
int main(){
    int signal[12], cars , total_cars = 0, maxSignal = 0, minSignal = 0; 

    for(int i = 0; i<=11 ; i++){
        printf("Enter Number OF Cars For Signal (%d): \n" , i + 1);
        scanf("%d" , &signal[i]);
        total_cars = total_cars + signal[i];
    }
    double avg = total_cars/12;
    printf("Cars Average is %.2f\n", avg);
    // printf("sum is %d" , total_cars);
    int count = 0;
    int max = signal[0];
    int min = signal[0];
    for(int i = 0; i<=11 ; i++){
        if(signal[i] > avg)
        {
        printf("Signal (%d) Cars is overloaded \n" , i + 1);
        count = count + 1;
        }
        if (signal[i] > max)
        {
            max = signal[i];
            maxSignal = i ;
        }
        if(signal[i] < min)
        {
            min = signal[i];
            minSignal = i;
        }
    }
    printf("Highest cars: %d at Signal %d\n", max, maxSignal + 1);
    printf("Lowest cars: %d at Signal %d\n", min, minSignal + 1);
}
