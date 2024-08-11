#include <stdio.h>
int i = 6;
int main(int argc, char * argv[]) {
    printf("%d\n", i);
    {
        int i = 7, j = 8;
        printf("%d\n%d\n", i, j);
        {
            int i = 5;
            printf("%d\n%d\n", i, j);
        }
        printf("%d\n", i);
    }
    printf("%d\n", i);
    return 0;
}
