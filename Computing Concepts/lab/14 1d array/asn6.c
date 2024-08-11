#include <stdio.h>
int main() {
    char string[100];
    int capital_letters_count = 0, small_letters_count = 0;
    printf("Enter an input string: ");
    gets(string);
    for(int i = 0; string[i] != '\0'; i++)
        if(string[i] >= 'A' && string[i] <= 'Z')
            capital_letters_count++;
        else if(string[i] >= 'a' && string[i] <= 'z')
            small_letters_count++;
    printf("The number of capital letters = %d.\nThe number of small letters = %d.\n", capital_letters_count, small_letters_count);
    return 0;
}
