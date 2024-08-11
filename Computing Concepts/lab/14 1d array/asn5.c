#include <stdio.h>
#define SIZE 1000   // Arbitrary input size
int main() {
    char string[SIZE];
    int length = 0;
    printf("Input a string to check if it is a palindrome: ");
    gets(string);
    for(length = 0; string[length] != '\0'; length++);  // Determine string length
    for(int read_position = 0; read_position < length / 2; read_position++) // Optimal
        if(string[length - 1 - read_position] != string[read_position]) {   // False condition
            printf("Given string is not a palindrome.\n");  // No need to check any further
            return 0;   // Exit
        }
    printf("Given string \"%s\" is a palindrome.\n", string);   // True condition
    return 0;
}
