#include <stdio.h>
int findPalin(int num);
int main() {
    int m, n, sum = 0;
    printf("Enter m & n: ");
    scanf("%d %d", &m, &n);
    for(; m <= n; m++)
        if(findPalin(m)) {
            printf("%d ", m);
            sum += m;
        }
    printf("\nSum = %d\n", sum);
    return 0;
}
int findPalin(int num) {
    int num_copy = num, reverse_number = 0;
        while(num != 0) {
            reverse_number = reverse_number * 10 + num % 10;
            num /= 10;
        }
        if(num_copy == reverse_number)
            return 1;
        return 0;
}
