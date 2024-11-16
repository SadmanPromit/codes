#include <stdio.h>
int main() {
    int num, search_key, first_flag = 0, first_index = -1, last_index = -1; // Negative indicates no match
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
            last_index = i;
            if(!first_flag) {
                ++first_flag;
                first_index = i;    // Considering the case of single match
            }
        }
    printf("First index = %d\nLast index = %d\n", first_index, last_index);
    return 0;
}
