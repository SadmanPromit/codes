#include <stdio.h>
void main() {
    char ch;
    printf("Enter any character: ");
    scanf("%c", &ch);
    switch(ch) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            printf("%c is vowel.\n", ch);
            break;
        default:
            printf("%c is consonant.\n", ch);
            break;
    }
    return 0;
}

