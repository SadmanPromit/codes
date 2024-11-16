#include <stdio.h>
struct Student {
    int id;
    double cgpa;
};
void DisplaySecondHighest(struct Student *student, int N);
int main() {
    int N;
    printf("N = ");
    scanf("%d", &N);
    struct Student student[N];  // VLA
    for(struct Student *ptr = student; ptr < student + N; ++ptr) {
        printf("ID: ");
        scanf("%d", &ptr -> id);
        printf("CGPA: ");
        scanf("%lf", &ptr -> cgpa);
        printf("\n");
    }
    DisplaySecondHighest(student, N);
    return 0;
}
void DisplaySecondHighest(struct Student *student, int N) {
    int highestId;
    double highest;
    for(struct Student *ptr = student; ptr < student + N; ++ptr) {
        if(ptr == student) {  // Initialize
            highestId = ptr -> id;
            highest = ptr -> cgpa;
        }
        if(ptr -> cgpa > highest) {
            highestId = ptr -> id;
            highest = ptr -> cgpa;
        }
    }
    int secondHighestId;
    double secondHighest = -1;  // Debug
    for(struct Student *ptr = student; ptr < student + N; ++ptr) {
        if(ptr == student) {  // Initialize
            if(ptr -> cgpa != highest) {    // Debug
                secondHighestId = ptr -> id;
                secondHighest = ptr -> cgpa;
            }
            else {    // Debug
                secondHighestId = (ptr + 1) -> id;    // Debug
                secondHighest = (ptr + 1) -> cgpa;    // Debug
            }
        }
        if(ptr -> cgpa > secondHighest && ptr -> cgpa < highest) {
            secondHighestId = ptr -> id;
            secondHighest = ptr -> cgpa;
        }
    }
    printf("The Second Highest CGPA holder: \nID: %d\nCGPA: %.2lf\n", secondHighestId, secondHighest);
    FILE *fpw = fopen("StudentInformation.txt", "w");
    fprintf(fpw, "The Second Highest CGPA holder: \nID: %d\nCGPA: %.2lf\n", secondHighestId, secondHighest);
    fclose(fpw);    // Debug
}
