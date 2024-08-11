#include <stdio.h>
//global scope
int n = 1;

//function definitions
print(int x) {
    printf("%d ", x + 2 * n);
}

decrement() {
    n -= 3;
    print(n);
}

main(){
    int n = 300;
    print(7);
    n = 40;
    decrement();
    printf("%d ", n);
}
