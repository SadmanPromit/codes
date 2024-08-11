#include <stdio.h>
struct student {
    char name[50];
    int roll;
    float marks;
} s[10];
void main() {
    int i;
    printf("Enter information of students:\n");
    for(i = 0; i < 10; ++i) {
        s[i].roll = i + 1;
        printf("For roll number %d\nEnter name: ", s[i].roll);
        scanf("%s", s[i].name);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("Displaying information of students:\n");
    for(i = 0; i < 10; ++i) {
        printf("Information for roll number %d:\nName: ", i + 1);
        puts(s[i].name);
        printf("Marks: %.1f\n", s[i].marks);
   }
}
