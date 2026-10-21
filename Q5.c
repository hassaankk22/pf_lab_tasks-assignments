#include <stdio.h>
int main()
{
    int marks[2][3][3];
    int total[2][3];
    int topper[2];
    int overallClass = 0, overallStudent = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            total[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                printf("Enter marks for class %d student %d subject %d: ", i + 1, j + 1, k + 1);
                scanf("%d", &marks[i][j][k]);
                total[i][j] += marks[i][j][k];
            }
            printf("Total marks = %d\n", total[i][j]);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        topper[i] = 0;
        for (int j = 1; j < 3; j++)
        {
            if (total[i][j] > total[i][topper[i]])
            {
                topper[i] = j;
            }
        }
        printf("Top Performer of Class %d: Student %d with %d marks\n",
               i + 1, topper[i] + 1, total[i][topper[i]]);
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (total[i][j] > total[overallClass][overallStudent])
            {
                overallClass = i;
                overallStudent = j;
            }
        }
    }

    printf("Overall Topper: Class %d Student %d with %d marks\n",
           overallClass + 1, overallStudent + 1,
           total[overallClass][overallStudent]);
}
