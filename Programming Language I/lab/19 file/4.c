#include <stdio.h>
int main() {
    FILE *fp;
    fp = fopen("test.txt", "a");
    fprintf(fp, "Added stuffs");
    fclose(fp);
    return 0;
}
