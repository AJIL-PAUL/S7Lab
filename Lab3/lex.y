%{
    #include<stdio.h>
    int valid=1;   
%}
%token number identifier operator
%%
start : identifier '=' s ';'
s :identifier x       
  | number x     
  | '-' number x   
  | '(' s ')' x 
  ;
x :     operator s        
      | '-' s       
      |             
      ;
%%
int yyerror()
{
    valid=0;
    printf("\nInvalid expression!\n");
    return 0;
}
int main()
{
    printf("\nEnter the expression:\n");

    yyparse();
    if(valid)
    {
        printf("\nValid expression!\n");
    }
}
