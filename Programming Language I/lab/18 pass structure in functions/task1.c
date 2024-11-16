#include <stdio.h>
#include <string.h>
struct Books {
   char title[50];
   char author[50];
   char subject[100];
   int book_id;
};
void printBook( struct Books book ) {   // Function that takes a structure variable as a parameter
   printf("Book title: %s\n", book.title);
   printf("Book author: %s\n", book.author);
   printf("Book subject: %s\n", book.subject);
   printf("Book book_id: %d\n", book.book_id);
}
void main( ) {
   struct Books Book1, Book2;
   strcpy(Book1.title, "C Programming");    // Book 1 specifications
   strcpy(Book1.author, "Nuha Ali");
   strcpy(Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
   strcpy(Book2.title, "Telecom Billing");  // Book 2 specification
   strcpy(Book2.author, "Zara Ali");
   strcpy(Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
   printBook(Book1);
   printBook(Book2);
}
