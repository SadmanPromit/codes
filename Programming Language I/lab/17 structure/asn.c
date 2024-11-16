#include <stdio.h>
#define SIZE 100    // Given value
int num = 0;
struct Mystruct {
    int integer;
} mystruct[SIZE];   // Part 1
int main() {
    printf("Enter the number of elements (<= 100): ");
    scanf("%d", &num);
    printf("Enter the elements: ");
    for(int index = 0; index < num; index++)    // Part 2
        scanf("%d", &mystruct[index].integer);
    printf("Entered elements are = ");  // Part 3
    for(int index = 0; index < num; index++)
        if(index)   // Formatting
            printf(", %d", mystruct[index].integer);
        else
            printf("%d", mystruct[index].integer);
    printf("\n");
    return 0;
}
