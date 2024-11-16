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
    int i;
    for(i = 0; i < MAX_BOOKS; i++) {    // read book specifications from user user until s/he enters empty string as title
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
void printBooks(struct Books b[]) {
    int i;
    printf("We have the following books:\n");
    for(i = 0; i < NUM_BOOKS; i++) {
        printf("Book title : %s\n", b[i].title);
        printf("Book author : %s\n", b[i].author);
        printf("Book subject : %s\n", b[i].subject);
        printf("Book book_id : %d\n", b[i].book_id);
    }
}
void main() {
    struct Books books[MAX_BOOKS];
    readBooks(books);
    printBooks(books);
}
