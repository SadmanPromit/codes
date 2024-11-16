#include <stdio.h>
int countSearchKey(int arr[], int size, int key);
int main() {
    int size, key;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Array Elements: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("Search Key: ");
    scanf("%d", &key);
    printf("Search Key appears %d times\n", countSearchKey(arr, size, key));
    return 0;
}
int countSearchKey(int arr[], int size, int key) {
    int count = 0;
    for(int i = 0; i < size; i++)
        if(arr[i] == key)
            count++;
    return count;
}
