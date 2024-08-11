#include <stdio.h>
int main() {
    int n, i = 0, last_palindrome, first_flag = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("The first %d palindrome numbers: ", n);
    while(n > 0) {
        // Temporary variables only needed for each iteration
        int number = i, reverse_number = 0;
        while(number != 0) {
            reverse_number = reverse_number * 10 + number % 10;
            number /= 10;
        }
        if(i == reverse_number) {
            // Formating the output properly
            if(first_flag)
                printf(", %d", i);
            else {
                printf("%d", i);
                first_flag = 1;
            }
            n--;
        }
    i++;
    }
    last_palindrome = --i;
    printf(".\nThe nth palindrome number: %d\n", last_palindrome);
    printf("All factors of %d are: ", last_palindrome);
    // Loop to the half of last palindrome for optimization
    for(i = 1; i <= last_palindrome / 2; i++)
        if(last_palindrome % i == 0)
            printf("%d, ", i);
    // As 1 and itself are factors for every number
    printf("%d.\n", last_palindrome);
    return 0;
}
