#include <stdio.h>
int facto(int n);
double sumOfTerms(int num_of_terms);
int main() {
    int num_of_terms;
    printf("Enter number of terms: ");
    scanf("%d", &num_of_terms);
    printf("Sum of the series = %lf\n", sumOfTerms(num_of_terms));
    return 0;
}
int facto(int n) {
    int factorial = 1;
    for(int i = 2; i <= n; i++)
        factorial *= i;
    return factorial;
}
double sumOfTerms(int num_of_terms) {
    double sum = 0;
    for(int i = 1; i <= num_of_terms; i++)
        sum += (double) 1 / facto(i);
    return sum;
}
