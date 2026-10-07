#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char pass[5][50];
    int i = 0 , score[5] = {0};

    while (i < 5) {
        printf("Enter Your Password: \n");
        scanf("%49s", pass[i]);
        i++;
    }

    // printf("%d\n", i);
    int strongest = 0;
    int count = 0;
    for(int i = 0; i<5 ; i++)
    {
        for(int j = 0 ; pass[i][j]!='\0' ; j++ )
        {
            char ch = pass[i][j];
            if(islower(ch))
            score[i] += 1;
            else if(isupper(ch))
            score[i] += 2;
            else if(isdigit(ch))
            score[i] += 3;
        }
        if(sizeof(pass[i]) >= 8)
        score[i] += 5;
        if(strstr(pass[i] , "123") != NULL)
        score[i] -= 3;
        
        printf("Score of Password %d is %d\n" , i+1 , score[i] );

        if(score[i] > strongest)
        strongest = score[i];

        if(score[i] < 10)
        count+=1;
    }
    printf("Strongest password is %d\n" , strongest);
    printf("There Are %d Weak Passwords" , count);

}