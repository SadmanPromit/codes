#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct customer {
    char fname[20], lname[20];
    int acct_num;
    float acct_balance;
} cust[100];
void main() {
    FILE *file;
    file = fopen("accounts.dat", "w");
    if(file == NULL) {
        fprintf(stderr, "Error opening accounts.dat\n");
        exit(1);
    }
    int i;
    for(i = 0; ; i++) {
        printf("Firstname (just hit enter to stop): ");
        gets(cust[i].fname);
        if(strcmp(cust[i].fname, "") == 0)
            break;
        fflush(stdin);
        printf("Lastname: ");
        gets(cust[i].lname);
        fflush(stdin);
        printf ("Acct No: ");
        scanf("%d", &cust[i].acct_num);
        fflush(stdin);
        printf("Acct Balance: ");
        scanf("%f", &cust[i].acct_balance);
        fflush(stdin);
    }
    fwrite(cust, sizeof(struct customer), i, file);
    fclose(file);
}
