#include <stdio.h>
#define SIZE 1000   // Arbitrary input size
int main() {
    char string[SIZE];
    int write_position = 0;
    printf("Input the string: ");
    gets(string);
    for(int read_position = 0; string[read_position] != '\0'; read_position++)  // Optimal
        if(string[read_position] >= 'a' && string[read_position] <= 'z' || string[read_position] >= 'A' && string[read_position] <= 'Z')    // True condition
            string[write_position++] = string[read_position];   // Write
    string[write_position] = '\0';  // Append NULL terminator
    printf("After removing, the Output String: %s\n", string);
    return 0;
}
