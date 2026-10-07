#include<stdio.h>
int main(){
    int seat[15] = {1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0};
    int empty, firstbooked ,lastOpen, book[3],k=0;

    for(int i = 0; i <15 ; i++)
    {
        if(seat[i] == 0)
        {
        printf("First Available seat is %d\n" , i+1);
        break;
        }
    }

    for(int i =0; i<15 ; i++)
    {
        if(seat[i] == 0)
        {
            lastOpen = i+1;
        }
    }
    printf("Last Available Seat is %d\n" , lastOpen);

    for(int i = 0; i<15 ; i++)
    {
        if(seat[i] == 0)
        {
            if(k<3)
            {
            book[k] = i+1;
            k++;
            seat[i] = 1;
            }
        }
    }

    printf("First Three Available seats Are %d, %d, %d" , book[0] , book[1], book[2]);
}