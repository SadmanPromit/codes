#include <stdio.h>
#define EMPLOYEE_NUMBER 4   // Given value
#define SIZE 50 // Arbitrary value
struct Date {
    int day, month, year;
};
struct Employee {
    char name[SIZE];
    struct Date dob;    // Date of Birth
    struct Date starting_date;
    int salary;
};
int main() {
    struct Employee employee[EMPLOYEE_NUMBER];
    int recent_joined_index = 0;    // Initialize with the first employee
    for(int index = 0; index < EMPLOYEE_NUMBER; index++) {  // Input
        printf("Name: ");
        fflush(stdin);  // Clear input stream
        gets(employee[index].name);
        printf("D.O.B: ");
        scanf("%d/%d/%d", &employee[index].dob.day, &employee[index].dob.month, &employee[index].dob.year);
        printf("Starting date: ");
        scanf("%d/%d/%d", &employee[index].starting_date.day, &employee[index].starting_date.month, &employee[index].starting_date.year);
        printf("Salary: ");
        scanf("%d", &employee[index].salary);
        printf("\n");   // Formatting
        if((employee[recent_joined_index].starting_date.year == employee[index].starting_date.year && (employee[recent_joined_index].starting_date.month == employee[index].starting_date.month && employee[recent_joined_index].starting_date.day < employee[index].starting_date.day) || (employee[recent_joined_index].starting_date.month < employee[index].starting_date.month)) || employee[recent_joined_index].starting_date.year < employee[index].starting_date.year)
            recent_joined_index = index;    // Update index
    }
    printf("Info of employee with the most recently joined is:\nName: %s\nD.O.B: %d/%d/%d\nStarting date: %d/%d/%d\nSalary: %d\n", employee[recent_joined_index].name, employee[recent_joined_index].dob.day, employee[recent_joined_index].dob.month, employee[recent_joined_index].dob.year, employee[recent_joined_index].starting_date.day, employee[recent_joined_index].starting_date.month, employee[recent_joined_index].starting_date.year, employee[recent_joined_index].salary);
    return 0;
}
