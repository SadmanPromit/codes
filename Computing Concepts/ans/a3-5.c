#include <stdio.h>
void printFrequency(int n);
int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printFrequency(n);
    return 0;
}
void printFrequency(int n) {
    int digit, occur = 0;
    printf("Enter digit to look for: ");
    scanf("%d", &digit);
    while(n != 0) {
        if(n % 10 == digit)
            occur++;
        n /= 10;
    }
    printf("Digit %d occurs %d times\n", digit, occur);
}
