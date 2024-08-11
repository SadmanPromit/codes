#include <stdio.h>
void printNum(int *, int);
int main() {
    int a[4] = {4, 10, 1, 5};
    printNum(a, 4);
    return 0;
}
void printNum(int *ptr,int len) {
    for(int i = 0; i < len ; ++i)
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
        // printf("ptr[%d]= %d\n", i, ptr[i]);
}
