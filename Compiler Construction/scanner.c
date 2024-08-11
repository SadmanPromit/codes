#include <stdio.h>

int main(void) {
    FILE *fp;
    int flag = 1, state = 0, tokenIndex = 0;
    char tokenValue[32] = "";

    fp = fopen("source.txt", "r");

    char ch = fgetc(fp);

    while(flag) {
        switch(state) {
        case 0:
            if(ch == ' ' || ch == '\t' || ch == '\n') {
                state = 0;
                //printf("State = %d, char = %c\n", state, ch);
                ch = fgetc(fp);
            }
            else if(ch == '<') {
                state = 1;
                tokenValue[tokenIndex++] = ch;
                ch = fgetc(fp);
            }
            else if(isalpha(ch) != 0) {
                state = 10;
                tokenValue[tokenIndex++] = ch;
                ch = fgetc(fp);
            }
            else if(ch == EOF) {
                printf("Lexical Analysis Ends Successfully\n.");
                flag = 0;
            }
            else
                state = 99;
            break;
        case 1:
            if(ch == '=') {
                tokenValue[tokenIndex++] = ch;
                state = 2;
            }
            else if(ch == '>') {
                tokenValue[tokenIndex++] = ch;
                state = 3;
            }
            else
                state = 4;
            break;
        case 2:
            tokenValue[tokenIndex] = '\0';
            printf("Class = RELOP, Value = %s\n", tokenValue);
            tokenIndex = 0;
            state = 0;
            ch = fgetc(fp);
            break;
        case 3:
            tokenValue[tokenIndex] = '\0';
            printf("Class = RELOP, Value = %s\n", tokenValue);
            tokenIndex = 0;
            state = 0;
            ch = fgetc(fp);
            break;
        case 4:
            tokenValue[tokenIndex] = '\0';
            printf("Class = RELOP, Value = %s\n", tokenValue);
            tokenIndex = 0;
            state = 0;
            break;
        case 10:
            if(isalnum(ch) != 0) {
                state = 10;
                tokenValue[tokenIndex++] = ch;
                ch = fgetc(fp);
            }
            else
                state = 11;
            break;
        case 11:
            tokenValue[tokenIndex] = '\0';
            printf("Class = ID, Value = %s\n", tokenValue);
            tokenIndex = 0;
            state = 0;
            break;
        case 99:
            printf("Error!\n");
            flag = 0;
            break;
        }
    }

    close(fp);
    return 0;

}
