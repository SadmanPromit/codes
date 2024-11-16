#include <stdio.h>
int main(){
    int c = 22, *pc;
    printf("Address of c: %d\nValue of c: %d\n", &c, c);
    pc = &c;
    printf("Address of pointer pc: %d\nContent of pointer pc: %d\n", pc,*pc);
    c=11;
    printf("Address of pointer pc: %d\nContent of pointer pc: %d\n", pc,*pc);
    *pc = 2;
    printf("Address of c: %d\nValue of c: %d\n", &c, c);
    return 0;
}
