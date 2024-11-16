#include <stdio.h>
void main() {
    FILE *fp;
    fp = fopen("test.txt", "r");
    if(fp != NULL) {
        printf("File opened");
        fclose(fp);
    }
    else
        printf("Error");
}
