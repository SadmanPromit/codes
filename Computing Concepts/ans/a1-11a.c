#include <stdio.h>
int main() {
    int semester_no;
    printf("Enter Semester No.: ");
    scanf("%d", &semester_no);
    if(semester_no == 0)
        printf("Invalid Semester\n");
    else if(semester_no >= 1 && semester_no <= 3)
        printf("Comment: Freshman\n");
    else if(semester_no >= 4 && semester_no <= 6)
        printf("Comment: Sophomore\n");
    else if(semester_no >= 7 && semester_no <= 9)
        printf("Comment: Junior\n");
    else if(semester_no >= 10 && semester_no <= 12)
        printf("Comment: Senior\n");
    else if(semester_no > 12)
        printf("Comment: You must graduate soon\n");
    return 0;
}

