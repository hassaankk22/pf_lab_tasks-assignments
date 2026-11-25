#include <stdio.h>
void buildScores(int change[], int score[], int i, int n, int current) {
    if(i == n)
        return;

    current += change[i];

    score[i] = current;

    buildScores(change, score, i+1, n, current);
}

int countLow(int score[], int n) {
    if(n == 0)
        return 0;

    if(score[n-1] < 50)
        return 1 + countLow(score, n-1);

    return countLow(score, n-1);
}

void reverse(int arr[], int left, int right) {
    int temp;

    if(left >= right)
        return;
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    reverse(arr, left+1, right-1);
}
int main() {
    int change[10] = {5, -8, -10, -12, 4,
                      6, 3, 7, -2, 5};
    int score[10];
    int i, low;

    buildScores(change, score, 0, 10, 70);
    printf("Daily scores: ");
    for(i = 0; i < 10; i++)
        printf("%d ", score[i]);
    low = countLow(score, 10);
    printf("\nDays below 50: %d\n", low);
    reverse(score, 0, 9);
    printf("Latest first: ");
    for(i = 0; i < 10; i++)
        printf("%d ", score[i]);
    printf("\n");
}
