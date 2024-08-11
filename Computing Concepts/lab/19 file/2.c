#include <stdio.h>
#include <string.h>
void main() {
    FILE *fp;
    char buffer[30];
    fp=fopen("test.txt", "w");
    if(fp == NULL) {
        printf("Error");
        return;
    }
    printf("Enter text to write to file (hit only enter to stop): ");
    while(1) {
        gets(buffer);
        if(strcmp(buffer, "") == 0)
            break;
        fprintf(fp, buffer);
    }
    fclose(fp);
}
