#include <stdio.h>
#define STUDENT_NUMBER 2    // Given value
struct Student {
    char name[50];
    int id;
    float CGPA;
};
int main() {
    struct Student student[STUDENT_NUMBER];
    int higher_CGPA_index = 0;  // Initialize with the first student
    for(int index = 0; index < STUDENT_NUMBER; index++) {   // Input
        printf("Enter [%d] student's name: ", index + 1);
        fflush(stdin);  // Clear input stream
        gets(student[index].name);
        printf("Enter [%d] student's id: ", index + 1);
        scanf("%d", &student[index].id);
        printf("Enter [%d] student's CGPA: ", index + 1);
        scanf("%f", &student[index].CGPA);
        if(student[higher_CGPA_index].CGPA < student[index].CGPA)
            higher_CGPA_index = index;  // Update index
    }
    printf("The student with name = %s and id = %d has higher CGPA than the other.\n", student[higher_CGPA_index].name, student[higher_CGPA_index].id);
    return 0;
}
