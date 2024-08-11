#include <stdio.h>
int main() {
    int amount, n500, n100, n50, n20, n10, n5, n2, n1, required_n500 = 0, required_n100 = 0, required_n50 = 0, required_n20 = 0, required_n10 = 0, required_n5 = 0, required_n2 = 0, required_n1 = 0;
    printf("Enter amount: ");
    scanf("%d", &amount);
    printf("Enter number of notes:\n500: ");
    scanf("%d", &n500);
    printf("100: ");
    scanf("%d", &n100);
    printf("50: ");
    scanf("%d", &n50);
    printf("20: ");
    scanf("%d", &n20);
    printf("10: ");
    scanf("%d", &n10);
    printf("5: ");
    scanf("%d", &n5);
    printf("2: ");
    scanf("%d", &n2);
    printf("1: ");
    scanf("%d", &n1);
    if(amount >= 500) {
        required_n500 = amount / 500;
        if(required_n500 > n500)
            required_n500 = n500;
        amount -= required_n500 * 500;
    }
    if(amount >= 100) {
        required_n100 = amount / 100;
        if(required_n100 > n100)
            required_n100 = n100;
        amount -= required_n100 * 100;
    }
    if(amount >= 50) {
        required_n50 = amount / 50;
        if(required_n50 > n50)
            required_n50 = n50;
        amount -= required_n50 * 50;
    }
    if(amount >= 20) {
        required_n20 = amount / 20;
        if(required_n20 > n20)
            required_n20 = n20;
        amount -= required_n20 * 20;
    }
    if(amount >= 10) {
        required_n10 = amount / 10;
        if(required_n10 > n10)
            required_n10 = n10;
        amount -= required_n10 * 10;
    }
    if(amount >= 5) {
        required_n5 = amount / 5;
        if(required_n5 > n5)
            required_n5 = n5;
        amount -= required_n5 * 5;
    }
    if(amount >= 2) {
        required_n2 = amount / 2;
        if(required_n2 > n2)
            required_n2 = n2;
        amount -= required_n2 * 2;
    }
    if(amount >= 1) {
        required_n1 = amount / 1;
        if(required_n1 > n1)
            required_n1 = n1;
        amount -= required_n1;
    }
    if(amount == 0)
        printf("Farhan can pay the bill by using the following counts of different notes:\n500: %d\n100: %d\n50: %d\n20: %d\n10: %d\n5: %d\n2: %d\n1: %d", required_n500, required_n100, required_n50, required_n20, required_n10, required_n5, required_n2, required_n1);
    else
        printf("Farhan cannot pay the bill with his notes.");
    return 0;
}
