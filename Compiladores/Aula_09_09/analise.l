%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

[0-9]+          { fprintf(yyout,"NUM -> %s \n", yytext); }
[+\-]           { fprintf(yyout,"OP -> %s \n", yytext); }
[\(\)]          { fprintf(yyout, "PARENTESES ->%s \n", yytext); }
\n              { fprintf(yyout, "\n"); }
[ \t]           { /* Ignora espaços e tabulações */ }
.               { fprintf(yyout, "Caractere inválido: %s\n", yytext); exit(1); }

%%

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo de entrada> <arquivo de saída>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Erro ao abrir o arquivo de saída");
        fclose(input);
        return 1;
    }

    yyin = input;
    yyout = output;

    yylex();

    fclose(input);
    fclose(output);

    return 0;
}