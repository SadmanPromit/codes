#include <stdio.h>
#include <string.h>
#define SIZE 2  // Arbitrary
#define STRING_SIZE 20  // Given
struct BarcelonaPlayer {
    char name[20];
    int age;
    char country[20];
    char Position[20];
    double Salary;
    double Rating;
};
void inputInfo(struct BarcelonaPlayer *pl, int size);   // Custom
void writeInfo(struct BarcelonaPlayer *pl, char *title);   // Custom
void findPlayers(struct BarcelonaPlayer *pl, int size);
int main() {
    struct BarcelonaPlayer barcelona_player[SIZE];
    inputInfo(barcelona_player, SIZE);
    findPlayers(barcelona_player, SIZE);
    return 0;
}
void inputInfo(struct BarcelonaPlayer *pl, int size) {
    for(struct BarcelonaPlayer *ptr = pl; ptr < pl + size; ++ptr) {
        printf("Enter player's information:\nName: ");
        fgets(ptr -> name, STRING_SIZE, stdin);
        ptr -> name[strcspn(ptr -> name, "\n")] = '\0';
        printf("Age: ");
        scanf("%d", &ptr -> age);
        printf("Country: ");
        getchar();  // Consume the \n
        fgets(ptr -> country, STRING_SIZE, stdin);
        ptr -> country[strcspn(ptr -> country, "\n")] = '\0';
        printf("Position: ");
        fgets(ptr -> Position, STRING_SIZE, stdin);
        ptr -> Position[strcspn(ptr -> Position, "\n")] = '\0';
        printf("Salary: ");
        scanf("%lf", &ptr -> Salary);
        printf("Rating: ");
        scanf("%lf", &ptr -> Rating);
        getchar();
    }
}
void writeInfo(struct BarcelonaPlayer *pl, char *title) {
    FILE *fp = fopen("player_info.txt", "w");
    if(!fp) {
        printf("Error creating file.");
        return;
    }
    fprintf(fp, "%sName: %s\nAge: %d\nCountry: %s\nPosition: %s\nSalary: %.2lf\nRating: %.2lf\n",
           title, pl -> name, pl -> age, pl -> country, pl -> Position, pl -> Salary, pl -> Rating);
    fclose(fp);
}
void findPlayers(struct BarcelonaPlayer *pl, int size) {
    for(struct BarcelonaPlayer *ptr = pl; ptr < pl + size; ++ptr)
        if(!strcmp(ptr -> country, "Argentina")) {
            writeInfo(ptr, "Player's information from Argentina:\n");
        }
}
