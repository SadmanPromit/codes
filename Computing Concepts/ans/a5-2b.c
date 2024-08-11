#include <stdio.h>
#define STRING_SIZE 100    // Arbitrary size
int findlength(char *s);
int main() {
    char string[STRING_SIZE];
    printf("Enter string: ");
    fgets(string, STRING_SIZE, stdin);
    printf("Length = %d\n", findlength(string));
    return 0;
}
int findlength(char *s) {
    char *ptr = s;
    for(; *ptr != '\0' && *ptr != '\n' && ptr - s < STRING_SIZE; ++ptr);
    return ptr - s;
}
