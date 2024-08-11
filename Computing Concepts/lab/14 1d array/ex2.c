#include <stdio.h>
int main() {
    int num, search_key, first_flag = 0;
    printf("Enter no. of elements: ");
    scanf("%d", &num);
    int array[num];
    printf("Enter %d numbers: ", num);
    for(int i = 0; i < num; i++)
        scanf("%d", &array[i]);
    printf("Enter search key: ");
        scanf("%d", &search_key);
    printf("All the indexes in which the search key appears = ");
    for(int i = 0; i < num; i++)
        if(array[i] == search_key) {
            if(first_flag)  // Formatting
                printf(", ");
            else
                first_flag++;
            printf("%d", i);
        }
    printf(".\n");
    return 0;
}
