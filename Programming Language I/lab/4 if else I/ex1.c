#include <stdio.h>
void main() {
    int month, number;
    // Read month from user
    printf("Enter month: ");
    scanf("%d", &month);
    // Check for leap year
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        printf("31");
    else if(month == 2)
        printf("28");
    else if(month < 1 || month > 12)
        printf("Invalid month.");
    else
        printf("30");
}
