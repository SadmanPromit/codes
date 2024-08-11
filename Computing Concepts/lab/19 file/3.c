#include <stdio.h>
void main() {
    FILE *fp;
    fp = fopen("test.txt", "r");
    char c;
    while((c = getc(fp)) != EOF)
        putchar(c);
    fclose(fp);
}
