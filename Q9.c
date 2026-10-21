#include <stdio.h>
int main() {
    int departments, employees, days;
    int salary, deptTotal, totalSalary = 0;

    printf("Enter number of departments: ");
    scanf("%d", &departments);

    for (int i = 1; i <= departments; i++) {
        printf("Enter number of employees in department %d: ", i);
        scanf("%d", &employees);

        deptTotal = 0;

        for (int j = 1; j <= employees; j++) {
            printf("Enter days worked by employee %d: ", j);
            scanf("%d", &days);

            salary = days * 500;

            if (days > 25) {
                salary += 2000;
            }

            printf("Department %d, Employee %d: Days Worked = %d, Salary = Rs. %d\n",
                   i, j, days, salary);

            deptTotal += salary;
        }

        printf("\nTotal salary of department %d = Rs. %d\n\n", i, deptTotal);

        totalSalary += deptTotal;
    }

    printf("Total salary of all departments = Rs. %d\n", totalSalary);

}
