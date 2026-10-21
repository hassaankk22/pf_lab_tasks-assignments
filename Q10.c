#include <stdio.h>
int main()
{
    int classes, students, subjects, marks;
    int total, classTotal, schoolTotal = 0;
    int pass;
    float average, classAverage, schoolAverage;
    int totalStudents = 0;

    printf("Enter number of classes: ");
    scanf("%d", &classes);

    for (int i = 1; i <= classes; i++)
    {
        printf("Enter number of students in class %d: ", i);
        scanf("%d", &students);

        classTotal = 0;

        for (int j = 1; j <= students; j++)
        {
            printf("Enter number of subjects for student %d: ", j);
            scanf("%d", &subjects);

            total = 0;
            pass = 1;

            for (int k = 1; k <= subjects; k++)
            {
                printf("Enter marks for subject %d: ", k);
                scanf("%d", &marks);

                total += marks;

                if (marks < 40)
                {
                    pass = 0;
                }
            }

            average = (float)total / subjects;

            printf("Class %d, Student %d: Total Marks = %d, Average = %.2f, Result = ",
                   i, j, total, average);

            if (pass == 1)
            {
                printf("Pass\n");
            }
            else
            {
                printf("Fail\n");
            }

            classTotal += total;
            schoolTotal += total;
            totalStudents++;
        }

        classAverage = (float)classTotal / students;

        printf("\nTotal marks of class %d = %d\n", i, classTotal);
        printf("Class average = %.2f\n\n", classAverage);
    }

    schoolAverage = (float)schoolTotal / totalStudents;
    printf("Total marks of all students = %d\n", schoolTotal);
    printf("Overall school average = %.2f\n", schoolAverage);
    return 0;
}
