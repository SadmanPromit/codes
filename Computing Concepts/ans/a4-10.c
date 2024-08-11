#include <stdio.h>
#define SIZE 1000   // Arbitrary input size
void getridofandshift(char str[], char ch);
int main() {
    char string[SIZE], ch;
    printf("Input string: ");
    gets(string);
    printf("Character to remove: ");
    scanf("%c", &ch);
    getridofandshift(string, ch);
    printf("Output string: %s\n", string);
    return 0;
}
void getridofandshift(char str[], char ch) {
    int write_position = 0;
    for(int read_position = 0; str[read_position] != '\0'; read_position++) // Optimal
        if(str[read_position] != ch)    // True condition
            str[write_position++] = str[read_position]; // Write
    str[write_position] = '\0'; // Append NULL terminator
}
