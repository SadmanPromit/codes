#include<stdio.h>
void main() {
    char a;
    printf("Enter a lowercase letter: ");
    scanf("%c", &a);
    a -= 32; //not recommended, since it replaces the original character
    printf("Uppercase of given letter is: %c", a);
    ++a;//not recommended, since it replaces the original character
    printf("\nUppercase of next letter is: %c", a);
}
