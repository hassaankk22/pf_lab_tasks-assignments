#include<stdio.h>
int main(){
    int seats[10][4], reseats,row,column;
    printf("R1   R2   R3   R4\n");
    for(int i =0; i< 10; i++){
        for(int j =0; j<4; j++){
            seats[i][j] = 0;
            printf("%-5d" , seats[i][j]);
        }
        printf("\n");
    }

    printf("Enter Number of seats You wants to book!: \n");
    scanf("%d" , &reseats);
    for(int k = 0; k< reseats; k++){
    if(reseats>40)
    {
    break;
    }
    printf("Enter #%d seat row! : \n" , k+1);
    scanf("%d" , &row);
    printf("Enter #%d Seat Column!: \n" , k+1);
    scanf("%d" , &column);
    if(row>10 || column>4){
        printf("Invalid  Rows or Column");
        break;
    }
    for(int i = 0; i <10; i++){
        for(int j = 0; j<4; j++){
            if(i == (row-1) && j==(column-1))
            {
                if(seats[i][j] == 1){
                printf("Already Booked!");
                k -=1;
                }
                else
                seats[i][j] = 1;
            }
        }
    }
    }
    if(reseats<=40 && row<10 && column<4)
    printf("Here is the Updated Seats Arrangment! \n");
    for(int i = 0; i <10; i++){
    if(reseats>40 || row>=10 || column>=4)
    {
    break;
    }
        for(int j = 0; j<4; j++){
            printf("%-5d" , seats[i][j]);
        }
        printf("\n");
    }
    if(reseats>40)
    printf("Invalid Seat Number (Max Seats 40)\n");


}