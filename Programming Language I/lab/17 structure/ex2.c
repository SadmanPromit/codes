#include <stdio.h>
#define PERSON_NUMBER 2 // Given value
struct BirthCertificate {
    int day, month, year;   // to represent birth date
    char name[100], fatherName[100], motherName[100];
};
int main() {
    struct BirthCertificate birth_certificate[PERSON_NUMBER];
    int older_person_index = 0; // Initialize with the first person
    for(int index = 0; index < PERSON_NUMBER; index++) {    // Input
        printf("Enter [%d] person's birthdate: ", index + 1);
        scanf("%d/%d/%d", &birth_certificate[index].day, &birth_certificate[index].month, &birth_certificate[index].year);
        printf("Enter [%d] person's name: ", index + 1);
        fflush(stdin);  // Clear input stream
        gets(birth_certificate[index].name);
        printf("Enter [%d] person's fatherName: ", index + 1);
        fflush(stdin);  // Clear input stream
        gets(birth_certificate[index].fatherName);
        printf("Enter [%d] person's motherName: ", index + 1);
        fflush(stdin);  // Clear input stream
        gets(birth_certificate[index].motherName);
        if((birth_certificate[older_person_index].year == birth_certificate[index].year && (birth_certificate[older_person_index].month == birth_certificate[index].month && birth_certificate[older_person_index].day > birth_certificate[index].day) || (birth_certificate[older_person_index].month > birth_certificate[index].month)) || birth_certificate[older_person_index].year > birth_certificate[index].year)
            older_person_index = index; // Update index
    }
    printf("The person's information who is older than the other:\nName = %s\nFather's name = %s\nMother's name = %s\n", birth_certificate[older_person_index].name, birth_certificate[older_person_index].fatherName, birth_certificate[older_person_index].motherName);
    return 0;
}
