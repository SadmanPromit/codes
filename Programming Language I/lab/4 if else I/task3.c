#include <stdio.h>
void main() {
    int year;
    // Read year from user
    printf("Enter year: ");
    scanf("%d", &year);
    // Check for leap year
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        printf("Leap year.");
    else
        printf("Not leap year.");
}
