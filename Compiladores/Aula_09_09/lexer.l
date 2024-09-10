%{
#include <stdio.h>
%}

DIGITO    [0-9]
OPERADOR  [+-]
PARENTESE [\(\)]

%%

{DIGITO}+          { printf("NUMERO: %s\n", yytext); }
{OPERADOR}         { printf("OPERADOR: %s\n", yytext); }
{PARENTESE}        { printf("PARENTESE: %s\n", yytext); }
\n                 { /* Ignorar novas linhas */ }
[ \t]              { /* Ignorar espaços e tabulações */ }
.                  { /* Ignorar outros caracteres */ }

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("Erro ao abrir o arquivo");
            return 1;
        }
        yyin = file;
    }
    yylex();
    return 0;
}