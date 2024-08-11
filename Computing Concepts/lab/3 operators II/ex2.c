#include <stdio.h>
#include <math.h>
void main() {
    int m, n, output1, output2, output4;
    float output3;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    output1 = m * pow(2, n);
    output2 = m << n;
    output3 = (float)m / pow(2, n);
    output4 = m >> n;
    printf("\nm * 2^n = %d\nm << n = %d\nm / 2^n = %f\nm >> n = %d\n", output1, output2, output3, output4);
}

