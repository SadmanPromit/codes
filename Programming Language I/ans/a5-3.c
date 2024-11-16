#include <stdio.h>
#define STRING_SIZE 100    // Arbitrary size
void changecase(char *s);
int main() {
    char string[STRING_SIZE];
    printf("Enter string: ");
    fgets(string, STRING_SIZE, stdin);
    changecase(string);
    printf("%s", string);
    return 0;
}
void changecase(char *s) {
    for(; *s != '\0' && *s != '\n'; ++s)
        if(*s >= 'A' && *s <= 'Z')
            *s = *s + 'a' - 'A';
        else if(*s >= 'a' && *s <= 'z')
            *s = *s + 'A' - 'a';
}
