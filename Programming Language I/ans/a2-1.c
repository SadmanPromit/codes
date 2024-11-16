#include <stdio.h>
int main() {
    int i = 200, first_flag = 0;
    printf("All the integers between 100 and 200 which are divisible by 8 in descending order: ");
    while(i >= 100) {
        if(i % 8 == 0)
            // Formating the output properly
            if(first_flag)
                printf(", %d", i);
            else {
                printf("%d", i);
                first_flag = 1;
            }
        i--;
    }
    printf(".\n");
    return 0;
}
