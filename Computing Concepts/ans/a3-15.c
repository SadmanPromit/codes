#include <stdio.h>
#include <stdlib.h> // For exit()
#include <math.h>   // For sqrt()
void findLCM(int n1, int n2);
void findGCD(int n1, int n2);
void perf();
int sumFact();
int mult(int num, int divisor);
int facto(int n);
void ex_it();
int input();    // Custom input function for reuse
int main() {
    while(1) {  // Menu
        printf("::Menu options::\n1. LCM of 2 numbers\n2. GCD of 2 numbers\n3. Perfect number\n4. Sum of Factors of a number\n5. Multiple: If a number is a multiple of another number\n6. Factorial\n7. Exit\nPlease select any from 1 to 7:\n");
        int choice = input();
        printf("Selected %d\n", choice);
        switch(choice) {
            case 1: findLCM(input(), input()); break;
            case 2: findGCD(input(), input()); break;
            case 3: perf(); break;
            case 4: printf("Result = %d\n", sumFact()); break;
            case 5: printf("Result = %d\n", mult(input(), input())); break;
            case 6: printf("Result = %d\n", facto(input())); break;
            case 7: ex_it();    // No need of break
            default: printf("Invalid input. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}
void findLCM(int n1, int n2) {
    int numerator_copy = n1 * n2;
    printf("LCM of %d and %d = ", n1, n2);
    // Euclidean Algorithm
    while(n2 != 0) {
        int temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }
    printf("%d\n", numerator_copy / n1);
}
void findGCD(int n1, int n2) {
    printf("GCD of %d and %d = ", n1, n2);
    // Euclidean Algorithm
    while(n2 != 0) {
        int temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }
    printf("%d\n", n1);
}
void perf() {
    int number = input(), sum = 1;
    for(int i = 2; i <= sqrt(number); i++)  // Optimal
        if(number % i == 0) {
            sum += i;
            int quotient = number / i;  // Temporary variable of optimality
            if(i != quotient)
                sum += quotient;    // The other unique divisor larger than sqrt(num)
        }
    if(sum == number)
        printf("%d is a perfect number\n", number);
    else
        printf("%d is not a perfect number\n", number);
}
int sumFact() {
    int number = input(), sum = 0;
    for(int i = 1; i <= sqrt(number); i++)
        if(number % i == 0)
            sum += i;
    return sum;
}
int mult(int num, int divisor) {
    if(num % divisor == 0)
        return 1;
    return 0;
}
int facto(int n) {
    int factorial = 1;
    for(int i = 2; i <= n; i++)
        factorial *= i;
    return factorial;
}
void ex_it() {
    exit(0);    // Exit successfully
}
int input() {
    int buffer;
    printf("Please enter an integer: ");
    scanf("%d", &buffer);
    return buffer;
}
