#include <stdio.h>
#include <math.h>
int main() {
    int N;
    float sum = 0;
    printf("Enter N: ");
    scanf("%d", &N);
    for(int i = 1; i <= N; i += 3) {
        if(i % 2 == 0)
            sum += sqrt(i);
        else
            sum += i;
    }
    printf("Sum = %.2f\n", sum);
    return 0;
}
