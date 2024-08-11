%{
#include <stdio.h>
%}
space	[ \t\n]
digit	[0-9]
letter	[A-Za-z]
dot	[\.]
%%
{space}+	{printf("space\n");}
{digit}+{dot}{digit}+	{printf("<REAL>: %s\n",yytext);}
{digit}+	{printf("<INT>: %s\n",yytext);}
"if"	{printf("IF: %s\n",yytext);}
{letter}({letter}|{digit})*	{printf("<ID>: %s\n",yytext);}
"<"	{printf("<LT>: %s\n",yytext);}
"<="	{printf("LE: %s\n",yytext);}
"<>"	{printf("NE: %s\n",yytext);}
<<EOF>>	{printf("EOF:\n"); return 0;}
.	{printf("<OTHER>: %s\n",yytext);}
%%
int yywrap(void) {
	return 1;
}

int yyerror(void) {
	printf("Error\n");
	exit(1);
}

int main() {
	yylex();
}