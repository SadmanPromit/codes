#include <stdio.h>
#include <math.h>
int main() {
    int first_flag = 0;
    printf("All Armstrong numbers between 1 and 500: ");
    for(int i = 1; i <= 500; i++) {
        int number = i, sum = 0; // Temporary variables for each loop
        while(number != 0) {
            sum += pow(number % 10, (int) (log10(i) + 1));  // Logarithm for digit count instead hard coding 3 to compute 1-digit Armstrong numbers
            number /= 10;
        }
        if(i == sum)
            // Formating the output properly
            if(first_flag)
                printf(", %d", i);
            else {
                printf("%d", i);
                first_flag = 1;
            }
    }
    printf(".\n");
    return 0;
}
