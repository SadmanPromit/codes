#include<stdio.h>
void main() {
    char s[100];    // Assume that user won't enter a string of size > 100
    int i, numSpace = 0;    // Counter to count # of spaces
    printf("Enter a string: ");
    gets(s);    // Read string from user
    for(i=0; s[i] != '\0'; i++)
        if(s[i] == ' ') numSpace++;
    printf("%d spaces\n", numSpace);
}
