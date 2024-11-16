#include <stdio.h>
#include <ctype.h>
int main() {
    char string[100];
    int first_flag = 0, count = 0;
    printf("Enter a string: ");
    gets(string);
    printf("Frequencies of letters in the input string:\n");
    for(char character = 'a'; character <= 'z'; character++, count = 0) {   // Alphabetical loop
        for(int i = 0; string[i] != '\0'; i++)  // String loop
            if(tolower(string[i]) == character) // Case insensitivity
                count++;
        if(count) { // Excluding zero occurances
            if(first_flag)  // Formatting
                printf(", ");
            else
                first_flag++;
            printf("%c/%c: %d", character, toupper(character), count);
        }
    }
    printf("\n");
    return 0;
}
