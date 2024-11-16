#include <stdio.h>
int getNum();
int getSquare(int n);
int getCube(int l);
int main() {
    int number = getNum();
    printf("The square of the number is: %d\nThe cube of the number is: %d\n", getSquare(number), getCube(number));
    return 0;
}
int getNum() {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    return number;
}
int getSquare(int n) {
    return n * n;
}
int getCube(int l) {
    return l * l * l;
}


