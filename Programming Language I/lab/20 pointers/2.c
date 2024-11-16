#include <stdio.h>
int main () {
    int var = 3000, *ptr = &var, **pptr = &ptr; // Take the address of var, take the address of ptr using address of operator &
    printf("Value of var = %d\nValue available at *ptr = %d\nValue available at **pptr = %d\n",
           var, *ptr, **pptr);  // Take the value using pptr
    return 0;
}
