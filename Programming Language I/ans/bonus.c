#include <stdio.h>
int main() {
    int year, salary, bonus, new_salary;
    printf("Enter number of years: ");
    scanf("%d", &year);
    if(year >= 5) {
        printf("Enter Salary: ");
        scanf("%d", &salary);
        bonus = salary * (float) 10 / 100; // cast to increase precision
        new_salary = salary + bonus;
        printf("You are eligible for the Bonus\nYour Bonus = %d\nYour New Salary = %d+%d=%d\n", bonus, salary, bonus, new_salary);
    }
    else
        printf("You are not eligible for the Bonus\n");
    return 0;
}
