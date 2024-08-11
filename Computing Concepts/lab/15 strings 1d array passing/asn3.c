#include <stdio.h>
void search(char arr[], char key);
int main() {
    char arr[100], key;
    printf("Enter String: ");
    gets(arr);
    printf("Search Key: ");
    scanf(" %c", &key);
    search(arr, key);
    return 0;
}
void search(char arr[], char key) {
    int position = 0;
    while(arr[position] != '\0')
    if(arr[position++] == key) {
        printf("Found\n");
        return;
    }
    printf("No found\n");
}
