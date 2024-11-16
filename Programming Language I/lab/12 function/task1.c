#include <stdio.h>
// Definition of a non-void function
float computeSquare(float x) {
    return x*x;
}
// Definition of a void function
void printCube(float x) {
    printf("Cube = %f\n", x*x*x);
}
// main function
void main() {
    float m, n;
    printf("Enter a number: ");
    scanf("%f", &m);
    // Call computeSquare function on m
    n = computeSquare(m);
    printf ("Square = %f\n", n);
    // Call printCube function on m
    printCube(m);
}
