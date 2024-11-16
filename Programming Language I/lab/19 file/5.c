#include <stdio.h>
void main() {
    FILE *fpointer;
    fpointer = fopen("input.txt", "w");
    fprintf(fpointer, "Bob\n30\n20000\n");
    fprintf(fpointer, "Amanda\n20\n10000\n");
    fclose(fpointer);
}
