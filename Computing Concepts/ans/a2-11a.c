#include <stdio.h>
int main() {
    for(char i = 'E'; i >= 'A'; i--) {
        for(char j = i; j >= 'A'; j--)
            printf("%c ", j);   // Space for formatting properly
        printf("\n");
    }
    return 0;
}
