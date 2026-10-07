#include<stdio.h>
int main(){
    int stock[10] , minimum[10], reorder, lrg_product;
    int count = 0;
    int largest_reorder = 0;
    int total = 0;
    for(int i = 0; i<10 ; i++){
        printf("Enter Quantity for product(%d): \n" , i+1);
        scanf("%d" , &stock[i]);
        printf("Enter Minimum Quantity for Product(%d)\n" , i+1);
        scanf("%d" , &minimum[i]);

        if(stock[i] < minimum[i]){
            reorder = minimum[i] - stock[i];
            total = total + reorder;
            printf("It needs to be Reorder!\nReorder Quantity: %d\n" , reorder);
            count++;
            if(reorder>largest_reorder){
                largest_reorder = reorder;
                lrg_product = i+1;
            }
        }
    }
    printf("The Largest Order is of Product (%d)\nReorder Quantity: %d\n", lrg_product, largest_reorder);
    printf("Total Reorder Quantity of %d products is : %d\n",count, total);
}