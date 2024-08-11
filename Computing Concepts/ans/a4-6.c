#include <stdio.h>
void shiftArrlPos(int arrl[], int arrSize);
void arrlRotate(int arrl[], int arrSize, int rotFrom);
int main() {
    int size, n;
    printf("Enter array size: ");
    scanf("%d", &size); // Input 1
    int arr1[size]; // VLA
    printf("Enter array elements: ");
    for(int index = 0; index < size; index++)   // Input 2
        scanf("%d", &arr1[index]);
    printf("Enter position, N to rotate array from: ");
    scanf("%d", &n);    // Input 3
    printf("The given array is: ");
    for(int index = 0; index < size; index++)   // Output 1
        printf("%d ", arr1[index]);
    printf("\nFrom %dth position the values of the array are: ", n);
    for(int index = n; index < size; index++)   // Output 2
        printf("%d ", arr1[index]);
    printf("\nBefore %dth position the values of the array are: ", n);
    for(int index = 0; index < n; index++)  // Output 3
        printf("%d ", arr1[index]);
    arrlRotate(arr1, size, n);
    printf("\nAfter rotating from %dth position the array is: ", n);
    for(int index = 0; index < size; index++)   // Output 4
        printf("%d ", arr1[index]);
    printf("\n");
    return 0;
}
void shiftArrlPos(int arrl[], int arrSize) {    // ROL 1 position
    int temp = arrl[0]; // Swap for ROL
    for(int index = 0; index < arrSize - 1; index++)    // Loop until last
        arrl[index] = arrl[index + 1];  // Shift left 1 position
    arrl[arrSize - 1] = temp;   // Swap ROL
}
void arrlRotate(int arrl[], int arrSize, int rotFrom) { // ROL N position
    for(int index = 0; index < rotFrom; index++)    // Loop ROL 1 position rotFrom = N times
        shiftArrlPos(arrl, arrSize);
}
