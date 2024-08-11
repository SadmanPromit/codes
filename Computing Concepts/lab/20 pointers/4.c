#include<stdio.h>
int* getRandom();
int main () {
    int *p;
    p = getRandom();
    printf("Address of p: %d\n", p);
    printf("Value at *p : %d\n", *p );
    return 0;
}
int* getRandom() {
    static int j;
    j = rand() % 10;
    printf("Value of j: %d\n", j);
    printf("Address of j: %d\n", &j);
    return &j;
}
