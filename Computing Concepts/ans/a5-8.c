#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100   // Given
#define STRING_SIZE 100 // Arbitrary
typedef struct {
    char name[STRING_SIZE], author[STRING_SIZE];
    int index, id, publish_year, present_price;
} Book_info;
void populate(Book_info *, int);    // Custom
void save(int);
void read(Book_info *, int);    // Custom
void displayAll(int);
void displayLowest(int);
void saveCharlesDickensBooks(int);
void saveOthersBooks(int);
int main() {
    int size;
    printf("Enter the number of books: ");
    scanf("%d", &size);
    save(size); // Solution to a
    displayAll(size);   // Solution to b
    displayLowest(size);    // Solution to c
    saveCharlesDickensBooks(size);    // Solution to d
    saveOthersBooks(size);    // Solution to e
    return 0;
}
void populate(Book_info *book_info, int size) {
    printf("::Enter all the books' information::\n");
    for(Book_info *ptr = book_info; ptr < book_info + size; ++ptr) {
        ptr -> index = ptr - book_info;
        printf("Book index: %d\nName: ", ptr -> index);
        getchar();  // Consume \n
        fgets(ptr -> name, STRING_SIZE, stdin);
        ptr -> name[strcspn(ptr -> name, "\n")] = '\0'; // Delete \n from string
        printf("Author: ");
        fgets(ptr -> author, STRING_SIZE, stdin);
        ptr -> author[strcspn(ptr -> author, "\n")] = '\0'; // Delete \n from string
        printf("ID: ");
        scanf("%d", &ptr -> id);
        printf("Publish year: ");
        scanf("%d", &ptr -> publish_year);
        printf("Present price: ");
        scanf("%d", &ptr -> present_price);
    }
}
void save(int size) {
    Book_info book_info[size]; // VLA
    populate(book_info, size);
    FILE *fp = fopen("input.txt", "w");
    if(!fp) {
        printf("Error writing file.");
        return;
    }
    for(Book_info *ptr = book_info; ptr < book_info + size; ++ptr) {
        fprintf(fp, "%d\n%s\n%s\n%d\n%d\n%d\n",
                ptr -> index, ptr -> name, ptr -> author, ptr -> id, ptr -> publish_year, ptr -> present_price);
    }
    fclose(fp);
}
void read(Book_info *book_info, int size) {
    FILE *fp = fopen("input.txt", "r");
    if(!fp) {
        printf("Error reading file.");
        return;
    }
    for(Book_info *ptr = book_info; ptr < book_info + size; ++ptr) {
        fscanf(fp, "%d\n", &ptr -> index);
        fgets(ptr -> name, STRING_SIZE, fp);
        ptr -> name[strcspn(ptr -> name, "\n")] = '\0'; // Delete \n from string
        fgets(ptr -> author, STRING_SIZE, fp);
        ptr -> author[strcspn(ptr -> author, "\n")] = '\0'; // Delete \n from string
        fscanf(fp, "%d\n%d\n%d\n", &ptr -> id, &ptr -> publish_year, &ptr -> present_price);
    }
    fclose(fp);
}
void displayAll(int size) {
    Book_info book_info[size];
    read(book_info, size);
    printf("::All the books' information::\n");
    for(Book_info *ptr = book_info; ptr < book_info + size; ++ptr)
        printf("Book index: %d\nName: %s\nAuthor: %s\nID: %d\n",
               ptr -> index, ptr -> name, ptr -> author, ptr -> id);
}
void displayLowest(int size) {
    Book_info book_info[size];
    read(book_info, size);
    int lowest = book_info -> present_price;
    printf("::Books' information with the lowest price::\n");
    for(Book_info *ptr = book_info + 1; ptr < book_info + size; ++ptr)
        if(ptr -> present_price < lowest)
            lowest = ptr -> present_price;
    for(Book_info *ptr = book_info; ptr < book_info + size; ++ptr)
        if(ptr -> present_price == lowest)
            printf("Book index: %d\nName: %s\nAuthor: %s\nID: %d\nPublish year: %d\nPresent price: %d\n",
                   ptr -> index, ptr -> name, ptr -> author, ptr -> id, ptr -> publish_year, ptr -> present_price);
}
void saveCharlesDickensBooks(int size) {
    Book_info book_info[size];
    read(book_info, size);
    FILE *fp = fopen("charles_dickens_books.txt", "w");
    if(!fp) {
        printf("Error writing file.");
        return;
    }
    fprintf(fp, "::Books' information which are written by Charles Dickens::\n");
    for(Book_info *ptr = book_info; ptr < book_info + size; ++ptr)
        if(!strcmp(ptr -> author, "Charles Dickens"))
            fprintf(fp, "Book index: %d\nName: %s\nAuthor: %s\nID: %d\nPublish year: %d\nPresent price: %d\n",
                    ptr -> index, ptr -> name, ptr -> author, ptr -> id, ptr -> publish_year, ptr -> present_price);
    fclose(fp);
}
void saveOthersBooks(int size) {
    Book_info book_info[size];
    read(book_info, size);
    FILE *fp = fopen("others_books.txt", "w");
    if(!fp) {
        printf("Error writing file.");
        return;
    }
    fprintf(fp, "::Books' information which are not written by Charles Dickens::\n");
    for(Book_info *ptr = book_info; ptr < book_info + size; ++ptr)
        if(strcmp(ptr -> author, "Charles Dickens"))
            fprintf(fp, "Book index: %d\nName: %s\nAuthor: %s\nID: %d\nPublish year: %d\nPresent price: %d\n",
                    ptr -> index, ptr -> name, ptr -> author, ptr -> id, ptr -> publish_year, ptr -> present_price);
    fclose(fp);
}
