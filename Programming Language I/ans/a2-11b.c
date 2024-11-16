#include <stdio.h>
int main() {
    for(int i = 1, count = 0; i <= 6; i++) {
        for(int j = 1; j <= 6; j++)
            if(j <= 6 - i)
                printf(" ");
            else
                printf("%d", count++ % 10);    // Remainder for truncating digits
        printf("\n");
    }
    return 0;
}
