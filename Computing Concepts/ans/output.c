#include <stdio.h>
int main() {
    char character;
    printf("Input: ");
    scanf("%c", &character);
    if(character >= 'A' && character <= 'Z')
        printf("Output: %c\n", character);
    else if(character >= 'a' && character <= 'z')
        printf("Output: %c\n", character - 32);
    else
        printf("Output: Invalid Input!\n");
    return 0;
}
