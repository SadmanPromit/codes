#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 1000
int NUM_BOOKS = 0;  // Global variable containing the actual number of books
struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} ;
void readBooks(struct Books b[]) {
    for(int i = 0; i < MAX_BOOKS; i++) {    // read book specifications from user user until s/he enters empty string as title
        printf("Enter book title (press just enter to finish): ");
        gets(b[i].title);
        if(strcmp(b[i].title, "") == 0) break;
        printf("Enter author-names: ");
        gets(b[i].author);
        printf("Enter subject: ");
        gets(b[i].subject);
        printf("Enter id: ");
        scanf("%d", &b[i].book_id);
        fflush(stdin);
        NUM_BOOKS++;    // Update the number of books we have
    }
}
void printBook(struct Books b) {    // Single struct instance display
    printf("We have the following books:\n");
    printf("Book title : %s\n", b.title);
    printf("Book author : %s\n", b.author);
    printf("Book subject : %s\n", b.subject);
    printf("Book book_id : %d\n", b.book_id);
}
void search(struct Books b[], char title[]) {
    for(int i = 0; i < NUM_BOOKS; i++)  // Search
        if(!strcmp(b[i].title, title)) {
            printBook(b[i]);
            return;
        }
    printf("Not found.\n");
}
int main() {
    char title[50];
    struct Books books[MAX_BOOKS];
    readBooks(books);
    printf("Enter book title to search: ");
    gets(title);
    search(books, title);
    return 0;
}
