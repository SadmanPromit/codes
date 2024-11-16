#include <stdio.h>
#include <ctype.h>
int main() {
    char string[100];
    int read_position = 0, write_position = 0, alphabet_count[26] = {0};
    printf("Enter a string: ");
    gets(string);
    while(string[read_position] != '\0') {  // Loop the string
        char character = tolower(string[read_position]);    // Temporary variable
        if(character >= 'a' && character <= 'z') {  // Check only for alphabets
            int index = character - 'a';    // Temporary variable
            alphabet_count[index]++;    // Increment for per alphabet count
            if(alphabet_count[index] == 1)
                string[write_position++] = string[read_position];   // Shift left for single occurence
        }
        else
            string[write_position++] = string[read_position];   // Shift left for non alphabets
        read_position++;    // Mandatory position read
    }
    string[write_position] = '\0';
    printf("Output string: %s\n", string);
    return 0;
}
