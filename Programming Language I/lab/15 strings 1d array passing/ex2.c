#include <stdio.h>
#include <ctype.h>
int main() {
    char string[100], no_vowel_string[100], vowel[] = {'a', 'e', 'i', 'o', 'u'};
    int k = 0;
    printf ("Enter a string: ");
    gets(string);
    for(int i = 0; string[i] != '\0'; i++) {
        int vowel_flag = 0; // Temporary variable
        for(int j = 0; j < 5; j++)
            if (string[i] == vowel[j] || string[i] == toupper(vowel[j])) {  // Checking both cases
                vowel_flag++;
                break;  // Optimal
            }
        if(!vowel_flag)
            no_vowel_string[k++] = string[i];
    }
    no_vowel_string[k] = '\0';
    printf("Output string: %s\n", no_vowel_string);
    return 0;
}
