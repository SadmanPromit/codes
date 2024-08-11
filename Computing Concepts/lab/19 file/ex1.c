#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CUSTOMERS 100
#define STRING_SIZE 20
typedef struct {
    char first_name[STRING_SIZE], last_name[STRING_SIZE];
    int account_number;
    float account_balance;
} Customer;
void input(Customer *, int *);
void read(Customer *, int *);
void write(Customer *, int *);
int main() {
    int customer_size = 0;
    Customer customer[MAX_CUSTOMERS];
    read(customer, &customer_size);
    input(customer, &customer_size);
    write(customer, &customer_size);
    return 0;
}
void input(Customer *customer, int *customer_size) {
    for(Customer *ptr = customer + *customer_size; ; ++ptr, ++*customer_size) {
        printf("First Name (just hit enter for menu): ");
        fgets(ptr -> first_name, STRING_SIZE, stdin);
        ptr -> first_name[strcspn(ptr -> first_name, "\n")] = '\0';
        if(strcmp(ptr -> first_name, "\0") == 0)
            break;
        printf("Last Name: ");
        fgets(ptr -> last_name, STRING_SIZE, stdin);
        ptr -> last_name[strcspn(ptr -> last_name, "\n")] = '\0';
        printf ("Account Number: ");
        scanf("%d", &ptr -> account_number);
        printf("Account Balance: ");
        scanf("%f", &ptr -> account_balance);
        getchar();
    }
}
void read(Customer *customer, int *customer_size) {
    FILE *file = fopen("accounts.dat", "r");
    if(!file) {
        fprintf(stderr, "Data not found.\n");
        return;
    }
    printf("Data found.\n");
    *customer_size = fread(customer, sizeof(Customer), MAX_CUSTOMERS, file);
    fclose(file);
}
void write(Customer *customer, int *customer_size) {
    FILE *file = fopen("accounts.dat", "w");
    if(!file) {
        fprintf(stderr, "Error saving.\n");
        return;
    }
    fwrite(customer, sizeof(Customer), *customer_size, file);
    fclose(file);
}
