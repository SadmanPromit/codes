#include <stdio.h>
void main() {
    char ch;
    printf("Enter the first letter of any of the fruits name: ");
    scanf("%c", &ch);
    switch(ch) {
        case 'm':
        case 'M':
            printf("Tk. 500/kg\n", ch);
            break;
        case 'a':
        case 'A':
            printf("Tk. 250/kg\n", ch);
            break;
        case 'b':
        case 'B':
            printf("Tk. 130/kg\n", ch);
            break;
        case 'c':
        case 'C':
            printf("Tk. 270/kg\n", ch);
            break;
        default:
            printf("Wrong input", ch);
            break;
    }
    return 0;
}
