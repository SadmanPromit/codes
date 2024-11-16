#include<stdio.h>
int main() {
    int a;
    float b;
    double c;
    char d;
    long int longInt;
    signed int no;
    printf("Size of int: %d bytes\n",sizeof(a));
    printf("Size of float: %d bytes\n",sizeof(b));
    printf("Size of double: %d bytes\n",sizeof(c));
    printf("Size of char: %d byte\n",sizeof(d));
    printf("Size of Long int: %d byte\n",sizeof(longInt));
    printf("Size of signed int: %d byte\n",sizeof(no));
}
