#include <stdio.h>
int main() {
    int age;
    char sts;
    printf("Enter age: ");
    scanf("%d", &age);
    if(age > 59) {
        printf("Enter sts: ");
        scanf(" %c", &sts);
        if(sts == 'w')
            printf("Working senior\n");
        else
            printf("Retired senior\n");
    }
    else {
        if(age > 20)
            printf("Adult\n");
        else {
            if(age > 12)
                printf("Teen\n");
            else
                printf("Child\n");
        }
    }
    return 0;
}
