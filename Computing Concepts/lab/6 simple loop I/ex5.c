#include <stdio.h>
int main() {
    int m, n;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    printf("All even numbers between %d and %d in reverse order: ", m, n);
    for(int i = n; i >= m; i--)
        if(i % 2 == 0)
            printf("%d, ", i);
    return 0;
}
