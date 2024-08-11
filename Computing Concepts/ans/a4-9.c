#include <stdio.h>
#define SIZE1 100   // Given input sizes
#define SIZE2 50
int main() {
    char A[SIZE1], B[SIZE2];
    int index;
    printf("Enter first string: ");
    gets(A);
    printf("Enter second string: ");
    gets(B);
    for(index = 0; A[index] != '\0'; index++);  // Find the first string's end index
    for(int j = 0; B[j] != '\0'; j++)   // Replace from the null character
        A[index++] = B[j];
    A[index] = '\0';    // Append NULL terminator
    printf("After joining, first string: %s\n", A);
    return 0;
}
