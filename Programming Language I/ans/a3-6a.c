#include <stdio.h>
double sumOfTerms(int num_of_terms);
int main() {
    int num_of_terms;
    printf("Enter number of terms: ");
    scanf("%d", &num_of_terms);
    printf("Sum of the series = %lf\n", sumOfTerms(num_of_terms));
    return 0;
}
double sumOfTerms(int num_of_terms) {
    int factorial = 1;
    double sum = 0;
    for(int i = 1; i <= num_of_terms; i++) {
        factorial *= i; // Optimization
        sum += (double) 1 / factorial;
    }
    return sum;
}
