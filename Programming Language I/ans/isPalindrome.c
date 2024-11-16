#include <stdio.h>
int isPalindrome(int n);
int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    if(isPalindrome(n)) {
        printf("Palindrome Number.\n");
        if(n % 5 == 0)
            printf("Divisible by 5.\n");
        else
            printf("Not divisible by 5.\n");
    }
    else
        printf("not palindrome.\n");
    return 0;
}
int isPalindrome(int n) {
    int n_copy = n, reverse = 0;
    while(n != 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;    // Update
    }
    return reverse == n_copy;   // Relational assignment
}
