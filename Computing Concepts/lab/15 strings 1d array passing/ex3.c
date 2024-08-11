#include <stdio.h>
#include <ctype.h>
int main() {
    char string[100];
    int first_flag = 0;
    printf("Enter a string: ");
    gets(string);
    printf("Unique letters in the input string (ignoring differences between lowercase & uppercase letters):\n");
    for(char character = 'a'; character <= 'z'; character++)    // Alphabetical loop
        for(int i = 0; string[i] != '\0'; i++)  // String loop
            if(tolower(string[i]) == character) {   // Case insensitivity
                if(first_flag)  // Formatting
                    printf(", ");
                else
                    first_flag++;
                printf("%c", character);
                break;  // Printing only once
        }
    printf("\n");
    return 0;
}
