#include <stdio.h>
void main() {
    int age;
    printf("Enter age: ");
    scanf("%d", &age);
    if(age >= 25 && age <= 45)
        printf("You are eligible to work.");
    else
        printf("You are too young or too old.");
}
