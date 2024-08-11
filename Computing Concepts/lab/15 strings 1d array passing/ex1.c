#include <stdio.h>
#include <ctype.h>
int main() {
    char string[100], vowel[] = {'a', 'e', 'i', 'o', 'u'};
    int count = 0;
    printf ("Enter a string of length < 100: ");
    gets(string);
    for(int i = 0; string[i] != '\0'; i++)
        for(int j = 0; j < 5; j++)
            if (string[i] == vowel[j] || string[i] == toupper(vowel[j]))    // Checking both cases
                count++;
    printf("Number of vowels = %d\n", count);
    return 0;
}
