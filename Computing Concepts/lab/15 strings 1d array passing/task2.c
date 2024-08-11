#include <stdio.h>
#include <ctype.h>
#define SIZE 100
void changeCase(char s[]) {
    int i;
    for(i = 0; s[i] != NULL; i++)
        if(isupper(s[i]))
            s[i] = tolower(s[i]);
        else if(islower(s[i]))
            s[i] = toupper(s[i]);
}
void main() {
    char str[SIZE];
    printf ("Enter a string of length < %d: ", SIZE);
    gets(str);
    changeCase(str);
    puts(str);
}
