#include <stdio.h>
int main() {
    int int1, int2;
    printf("Enter two integers: ");
    scanf("%d %d", &int1, &int2);
    printf("GCD of %d and %d: ", int1, int2);
    // Euclidean Algorithm
    while(int2 != 0) {
        int temp = int1 % int2;
        int1 = int2;
        int2 = temp;
    }
    printf("%d\n", int1);
    return 0;
}
