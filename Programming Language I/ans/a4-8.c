#include <stdio.h>
#define SIZE 1000   // Arbitrary input size
void Replace(char arr[], char oldChar, char newChar);
int main() {
    char string[SIZE], oldChar, newChar;
    printf("Input the string: ");
    gets(string);
    printf("Character to replace (old character): ");
    scanf(" %c", &oldChar);
    printf("Character to replace with (new character): ");
    scanf(" %c", &newChar);
    Replace(string, oldChar, newChar);
    printf("After replacing, the Output String: %s\n", string);
    return 0;
}
void Replace(char arr[], char oldChar, char newChar) {
    for(int index = 0; arr[index] != '\0'; index++)
        if(arr[index] == oldChar)   // True condition
            arr[index] = newChar;   // Replace
}
