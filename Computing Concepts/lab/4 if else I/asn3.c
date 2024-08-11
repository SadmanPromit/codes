#include <stdio.h>
int main() {
    char character;
    printf("Enter a character: ");
    scanf("%c", &character);
    if((character >= '0' && character <= '9') || (character >= 'a' && character <= 'f') || (character >= 'A' && character <= 'F'))
        printf("Hexadecimal digit.");
    else
        printf("Not hexadecimal digit.");
    return 0;
}
