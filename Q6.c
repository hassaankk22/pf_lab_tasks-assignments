#include<stdio.h>
int main(){
    int gen[10], nextgen[8];
    gen[0] = 10;
    gen[1] = 10;
    printf("%d\n%d\n",gen[0], gen[1]);

    for(int i =2; i<10; i++)
    {
        gen[i] = gen[i-1] + gen[i-2];
        printf("%d\n", gen[i]);
    }
}