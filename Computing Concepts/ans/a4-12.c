#include <stdio.h>
#include <stdlib.h> // Has exit()
#include <string.h> // Has strcmp()
#define SIZE 100   // Arbitrary input size
#define MAX_STUDENTS 100   // Given input size
struct Student {
    int id, age;
    char name[SIZE], gender[SIZE], contact_number[SIZE], address[SIZE];
    float cgpa; // Custom
};
int displayIdNames(struct Student student[], int n);
int insertStudent(struct Student student[], int n);
int modifyContactNumberAddress(struct Student student[], int n, char name_search[]);
int deleteStudentInformation(struct Student student[], int n, int id_search);
int dataPopulate(struct Student student[], int n, int insert_n);    // Custom
void input_string(char buffer[]);   // Custom
int main() {
    struct Student student[MAX_STUDENTS];
    int n;
    do {
        printf("Enter the number, n of students (<= 100): ");
        scanf("%d", &n);
    } while (n > MAX_STUDENTS);
    if(dataPopulate(student, 0, n))    // Initial population 0, insert population n
        printf("Successfully populated.\n\n");
    while(1) {  // Menu
        int choice;
        printf("::Menu options::\n1. Display Id Names\n2. Insert Student\n3. Modify Contact Number & Address\n4. Delete Student Information\n5. Exit\nPlease select any from 1 to 5:\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(!displayIdNames(student, n))
                    printf("Not found.\n");
                break;
            case 2:
                if(insertStudent(student, n))
                    printf("Successfully inserted.\n");
                else
                    printf("Failed to insert.\n");
                break;
            case 3:
                printf("Enter student's ID: ");
                char buffer_string[SIZE];   // Temporary variable
                input_string(buffer_string);
                if(modifyContactNumberAddress(student, n, buffer_string))
                    printf("Successfully modified.\n");
                else
                    printf("Failed to modify.\n");
                break;
            case 4:
                printf("Enter student's ID: ");
                int buffer_int;
                scanf("%d", &buffer_int);
                if(deleteStudentInformation(student, n, buffer_int))
                    printf("Successfully deleted.\n");
                else
                    printf("Not found.\n");
                break;
            case 5:
                printf("Closing...\n");
                exit(0);    // No need of break
            default: printf("Invalid input. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}
int displayIdNames(struct Student student[], int n) {
    int found_flag = 0;
    printf("The ID and names of all students with a CGPA of more than 3.5 are: \n");
    for(int index = 0; index < n; index++)
        if(student[index].cgpa > 3.5) {
            printf("ID = %d, Name = %s\n", student[index].id, student[index].name);
            found_flag = 1;
        }
    return found_flag;
}
int insertStudent(struct Student student[], int n) {
    return dataPopulate(student, n, 1); // Initial population n, insert population 1
}
int modifyContactNumberAddress(struct Student student[], int n, char name_search[]) {
    int found_flag = 0;
    for(int index = 0; index < n; index++)
        if(!strcmp(student[index].name, name_search)) { // Edit operation which considers all names even after match
            found_flag = 1;
            printf("Enter student's new Contact Number: ");
            input_string(student[index].contact_number);
            printf("Enter student's new Address: ");
            input_string(student[index].address);
        }
    return found_flag;
}
int deleteStudentInformation(struct Student student[], int n, int id_search) {
    int index = 0, found_flag = 0;
    for(; index < n; index++)
        if(student[index].id == id_search) {
            --n;    // Update to new n
            found_flag = 1;
            break;  // No need to look further
        }
    for(; index < n; index++)   // Shift 1 position left to delete
        student[index] = student[index + 1];
    return found_flag;
}
int dataPopulate(struct Student student[], int n, int insert_n) {
    int new_n = n + insert_n, found_flag = 0;
    if(new_n > MAX_STUDENTS)    // Bound checking
        return found_flag;
    for(int index = n; index < new_n; index++) {    // Initial population n, insert population insert_n
        printf("[%d] Enter student ID: ", index + 1);
        scanf("%d", &student[index].id);
        printf("[%d] Enter student's Name: ", index + 1);
        input_string(student[index].name);
        printf("[%d] Enter student's Age: ", index + 1);
        scanf("%d", &student[index].age);
        printf("[%d] Enter student's Gender: ", index + 1);
        input_string(student[index].gender);
        printf("[%d] Enter student's Contact Number: ", index + 1);
        input_string(student[index].contact_number);
        printf("[%d] Enter student's Address: ", index + 1);
        input_string(student[index].address);
        printf("[%d] Enter student's CGPA: ", index + 1);
        scanf("%f", &student[index].cgpa);
        printf("\n");   // Formatting
        found_flag = 1;
    }
    return found_flag;
}
void input_string(char buffer[]) {
    fflush(stdin);  // Clearing input stream
    gets(buffer);
}
