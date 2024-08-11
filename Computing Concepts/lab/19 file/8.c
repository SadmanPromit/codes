#include <stdio.h>
#include <stdlib.h>
struct customer {
    char fname[20], lname[20];
    int acct_num;
    float acct_balance;
} cust[100];
int num = 0; //total number of customers
void main() {
    FILE *file;
    file = fopen("accounts.dat", "r");
    if(file == NULL) {
        fprintf(stderr, "Error opening accounts.dat\n");
        exit (1);
    }
    int i;
    num = fread(cust, sizeof(struct customer), 100, file);
    for(i = 0; i < num; i++)
        printf("Name: %s %s, Acct# %d, Balance = %0.2f\n",
                cust[i].fname, cust[i].lname, cust[i].acct_num, cust[i].acct_balance);
    fclose(file);
}
