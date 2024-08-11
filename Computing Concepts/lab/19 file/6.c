#include <stdio.h>
void main() {
    FILE *fpointer;
    char name[100];
    int age;
    float salary;
    fpointer = fopen("input.txt", "r");
    while(fscanf(fpointer, "%s%d%f", name, &age, &salary) == 3)
        printf("%s\n%d\n%f\n", name, age, salary);
    fclose(fpointer);
}
