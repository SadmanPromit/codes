#include <stdio.h>
#define STRING_SIZE 100 // Arbitrary size
int compare(char *str1, char *str2);
int main() {
    char string1[STRING_SIZE], string2[STRING_SIZE];
    printf("Enter str1: ");
    fgets(string1, STRING_SIZE, stdin);
    printf("Enter str2: ");
    fgets(string2, STRING_SIZE, stdin);
    printf("%d\n", compare(string1, string2));
    return 0;
}
int compare(char *str1, char *str2) {
    int index = 0;
    for(; *str1 != '\0' && *str1 != '\n' && *str2 != '\0' && *str2 != '\n'; ++str1, ++str2)
        if(*str1 > *str2)
            return 1;
        else if(*str1 < *str2)
            return -1;
    if(*str1 != '\0' && *str1 != '\n' && (*str2 == '\0' || *str2 == '\n'))
        return 1;
    else if((*str1 == '\0' || *str1 == '\n') && *str2 != '\0' && *str2 != '\n')
        return -1;
    return 0;
}
