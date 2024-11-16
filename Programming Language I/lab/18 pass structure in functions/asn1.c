#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENT 1000    // Arbitrary values
#define SIZE 50
struct Student {
    char name[SIZE];
    int id;
    float CGPA;
};
int count_student = 0; // Global
void view_indexed(struct Student student); // Custom for view()
void view(struct Student student[]);
void edit_indexed(struct Student student[], int index); // Custom for add() & edit()
void add(struct Student student[]);
int search(struct Student student[]);
void edit(struct Student student[]);
void delete_index(struct Student student[]);
int main() {
    int choice;
    struct Student student[MAX_STUDENT];
    while(1) {
        printf("Options:\n[1] View\n[2] Add\n[3] Search\n[4] Edit\n[5] Delete\n[6] Exit\nChoose [1] to [6]: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: view(student); break;
            case 2: add(student); break;
            case 3: search(student); break;
            case 4: edit(student); break;
            case 5: delete_index(student); break;
            case 6: printf("Closing...\n"); exit(0);
            default: printf("Invalid input. Try again.\n");
        }
    }
    return 0;
}
void view_indexed(struct Student student) {
    printf("Name = %s\nID = %d\nCGPA = %.2f\n", student.name, student.id, student.CGPA);
}
void view(struct Student student[]) {
    if(!count_student) {
        printf("Not found.\n");
        return;
    }
    for(int i = 0; i < count_student; i++) {
        printf("Index = %d\n", i);
        view_indexed(student[i]);
    }
}
void edit_indexed(struct Student student[], int index) {
    printf("Enter student's name to add: ");
    fflush(stdin);
    gets(student[index].name);
    printf("Enter student's ID to add: ");
    scanf("%d", &student[index].id);
    printf("Enter student's CGPA to add: ");
    scanf("%f", &student[index].CGPA);
}
void add(struct Student student[]) {
    edit_indexed(student, count_student++); // add to the last + 1 position
    printf("Successfully added.\n");
}
int search(struct Student student[]) {
    int found_flag = 0;
    if(!count_student) {
        printf("Not found.\n");
        return found_flag;
    }
    char search_key[SIZE];
    printf("Enter student's ID or name to search: ");
    fflush(stdin);
    gets(search_key);
    for(int i = 0; i < count_student; i++)
        if((int) atoi(search_key) == student[i].id || !strcmp(search_key, student[i].name)) {
            printf("Index = %d\n", i);
            view_indexed(student[i]);
            found_flag = 1;
        }
    if(!found_flag)
        printf("Not found.\n");
    return found_flag;
}
void edit(struct Student student[]) {
    if(!count_student) {
        printf("Not found.\n");
        return;
    }
    int edit_index;
    if(search(student)) {
        printf("Enter student's index to edit: ");
        scanf("%d", &edit_index);
        if(edit_index < 0 || edit_index >= count_student) {
            printf("Not found.\n");
            return;
        }
        edit_indexed(student, edit_index);
    }
    printf("Successfully edited.\n");
}
void delete_index(struct Student student[]) {
    if(!count_student) {
        printf("Not found.\n");
        return;
    }
    int delete_index;
    view(student);
    printf("Enter student's index to delete: ");
    scanf("%d", &delete_index);
    if(delete_index < 0 || delete_index >= count_student) {
        printf("Not found.\n");
        return;
    }
    --count_student;
    for(; delete_index < count_student; delete_index++) // Shift 1 position left to delete the index
        student[delete_index] = student[delete_index + 1];
    printf("Successfully deleted.\n");
}
