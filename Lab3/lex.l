%{
    #include "y.tab.h"
%}

%%
[a-zA-Z_][a-zA-Z_0-9]* return identifier;
[0-9]+(\.[0-9]*)?      return number;
[+/*]                  return operator;
.                      return yytext[0];
\n                     return 0;
%%
int yywrap()
{
return 1;
}
