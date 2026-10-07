#include<stdio.h>
#include<math.h>
int main(){
    int num, reversed, remainder,place,j = 0 , original;

    printf("Enter any Number: \n");
    scanf("%d", &original);
    num = original;
    reversed = 0;
    while(num>0)
    {
        remainder = num%10;
        num = num/10;
        reversed = reversed*10 + remainder;
    }
    printf("%d\n", reversed);
    if(original == reversed){
        printf("It is pelindrome\n");
    }
    else
    printf("It is not pelindrome\n" );
}