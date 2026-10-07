#include<stdio.h>
int main(){
    int students[15], count = 0, afterBonus[15], totalmarks =0;
    double avg;
    int highest = 0;
    int lowest = 105;
    for(int i =0; i<15; i++){
        printf("Enter Marks for Student(%d): \n", i+1);
        scanf("%d" , &students[i]);
        afterBonus[i] = students[i] + 5;
        if(afterBonus[i] > highest){
            highest = afterBonus[i];
        }
        if(afterBonus[i] < lowest){
            lowest = afterBonus[i];
        }
        if(afterBonus[i] >100 || students[i] ==100){
            afterBonus[i] = afterBonus[i] - (afterBonus[i] -100);
            count++;
        }
        totalmarks = totalmarks + afterBonus[i];

    }
    avg = (double)totalmarks / 15;
    printf("Marks Range after Bonus is From %d to %d\n" , lowest , highest);
    printf("Average Marks After Bonus Marks is %.2f\n" , avg);
    printf("Total Number of Students With Marks 100 is %d" , count);
}