#include <stdio.h>
int main() {
    float number1, number2, output;
    char op;
    printf("Enter two numbers: ");
    scanf("%f%f", &number1, &number2);
    printf("Enter operator: ");
    scanf(" %c", &op);
    switch(op) {
        case '+':
            output = number1 + number2;
            printf("%f + %f = %f", number1, number2, output);
            break;
        case '-':
            output = number1 - number2;
            printf("%f - %f = %f", number1, number2, output);
            break;
        case '*':
            output = number1 * number2;
            printf("%f * %f = %f", number1, number2, output);
            break;
        case '/':
            output = number1 / number2;
            printf("%f / %f = %f", number1, number2, output);
            break;
        default:
            printf("Invalid operator.");
            break;
    }
    return 0;
}
