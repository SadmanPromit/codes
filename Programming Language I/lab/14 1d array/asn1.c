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
    for(int i = 0; i < num; i++)
        if(array[i] == search_key) {
            --num;
            for(int j = i; j < num; j++)
                array[j] = array[j + 1];
            break;
        }
    printf("Array after deleting the first element in the array which matches the search key (= %d) = ", search_key);
    for(int i = 0; i < num; i++) {
        if(first_flag)  // Formatting
                printf(", ");
            else
                first_flag++;
        printf("%d", array[i]);
    }
    printf(".\n");
    return 0;
}
