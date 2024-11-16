#include <stdio.h>
int main() {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
    switch(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        case 0:
            printf("Not leap year.");
            break;
        case 1:
            printf("Leap year.");
            break;
    }
    return 0;
}
