#include <stdio.h>
int main() {
    int semester_no;
    printf("Enter semester no.: ");
    scanf("%d", &semester_no);
    switch(semester_no) {
        case 0:
            printf("Invalid Semester\n");
            break;
        case 1:
        case 2:
        case 3:
            printf("Comment: Freshman\n");
            break;
        case 4:
        case 5:
        case 6:
            printf("Comment: Sophomore\n");
            break;
        case 7:
        case 8:
        case 9:
            printf("Comment: Junior\n");
            break;
        case 10:
        case 11:
        case 12:
            printf("Comment: Senior\n");
            break;
        default:
            printf("Comment: You must graduate soon\n");
            break;
    }
    return 0;
}
