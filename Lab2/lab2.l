%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%%

"void"|"int"|"break"|"char"|"float"|"return"|"for"|"while"|"long"|"const"|"if"|"switch"	{ printf("\n\t%-20s\tKeyword",yytext); }
[0-9]+ 										{ printf("\n\t%-20s\tNumber",yytext); }
("_")*[a-zA-Z]("_"|[a-zA-Z]|[0-9])* 						{ printf("\n\t%-20s\tIdentifier",yytext); }
"+"|"-"|"*"|"/"|"%" 								{ printf("\n\t%-20s\tArithemetic Op",yytext); }
"=" 										{ printf("\n\t%-20s\tAssignment Op",yytext); }
"{"|"}"|"("|")"|"."|";"|"," 							{ printf("\n\t%-20s\tSeparator",yytext); }

%%

int main(int argc,char *argv[]){
	FILE *f1;
	f1 = fopen("input.txt","r");
	if(!f1){
		printf("Input File Not Found!.....");
		return 0;
	}
	yyin = f1;
	yylex();
	fclose(f1);
	printf("\n");
	return 0;
}