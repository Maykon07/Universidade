/*
Implemente em C/C++ um AFD genérico. Esse deverá receber uma quíntupla e uma cadeia e seu retorno será ACEITA ou REJEITA a cadeia.
A quíntupla e a cadeia serão fornecidas ao algoritmo via um arquivo texto seguindo o modelo abaixo:
nome do arquivo de entrada: entrada.txt que deverá estar no seguinte formato:
Q= estados do autômato em que cada nome de estado está separado por espaço em branco;
𝛴 = o alfabeto em que cada símbolo está separado por espaço em branco;
δ: a função de transição no formato: estadoOrigem símboloAserConsumido estadoDestino;
q_0= estado inicial;
F= estados finais em que cada nome de estado está separado por espaço em branco;
w= cadeia a ser submetida ao autômato

ATENÇÂO:
O arquivo de entrada nas 4 primeiras linhas deverá conter as informações da quíntupla e a quinta linha a cadeia a ser submetida ao autômato.
cada estado e caractere do alfabeto tem que ser composto por apenas um simbolo e não pode conter espaço em branco.

por exemplo:
o "F" e "C" são estados de aceitão, então no aquivo de entrada.txt tem que estar assim: FC

Segue um exemplo de entrada.txt.
ifr
01
0111
f
i0f
i1r
f0f
f1f
r0r
r1r


Explicação: 
i f r    <- Q= estados do autômato em que cada nome de estado está separado por espaço em branco;
0 1    <-  o alfabeto em que cada símbolo está separado por espaço em branco;
0111  <- cadeia a ser submetida ao autômato
f    <- conjunto de estados finais em que cada nome de estado é um simbolo sem estar separado por espaço em branco;
i 0 f   <-  função de transição no formato: estadoOrigem símboloAserConsumido estadoDestino;
i 1 r    <-  função de transição no formato: estadoOrigem símboloAserConsumido estadoDestino;
f 0 f    <-  função de transição no formato: estadoOrigem símboloAserConsumido estadoDestino;
f 1 f    <-  função de transição no formato: estadoOrigem símboloAserConsumido estadoDestino;
r 0 r    <-  função de transição no formato: estadoOrigem símboloAserConsumido estadoDestino;
r 1 r    <-  função de transição no formato: estadoOrigem símboloAserConsumido estadoDestino;
i          <- estado inicial;
f         <- estado final;
*/



/*função que lê o arquivo de entrada e armazena os dados em variáveis
onde na primeria linha temos os estados do autômato, na segunda linha o alfabeto,
na terceira linha a cadeia a ser submetida ao autômato, na quarta ate o final do arquivo
tem a fun de transição, onde a primeira coluna é o estado de origem, a segunda coluna é o simbolo a ser consumido
e a terceira coluna é o estado de destino*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AFD(char Q[], char E[], char d[][3], char q0, char F[], char palavra[]);
int contarLinhasArquivo(const char *nomeArquivo);

int main() {
    FILE *arq;
    char Q[100], alfabeto[100], cadeia[100];
    char q_0;
    char F[100];
    // Array bidimensional para armazenar múltiplas linhas
    int n = contarLinhasArquivo("entrada.txt");
    char aux[n-4][3];


    arq = fopen("entrada.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    // Lê uma linha inteira do arquivo e armazena em Q
    if (fgets(Q, sizeof(Q), arq) == NULL) {
        printf("Erro ao ler a linha do arquivo\n");
        fclose(arq);
        exit(1);
    }

    // Lê uma linha inteira do arquivo e armazena em alfabeto
    if (fgets(alfabeto, sizeof(alfabeto), arq) == NULL) {
        printf("Erro ao ler a linha do arquivo\n");
        fclose(arq);
        exit(1);
    }

    // Lê uma linha inteira do arquivo e armazena em cadeia
    if (fgets(cadeia, sizeof(cadeia), arq) == NULL) {
        printf("Erro ao ler a linha do arquivo\n");
        fclose(arq);
        exit(1);
    }

     // Lê uma linha inteira do arquivo e armazena em F
    if (fgets(F, sizeof(F), arq) == NULL) {
        printf("Erro ao ler a linha do arquivo\n");
        fclose(arq);
        exit(1);
    }


    // Lê múltiplas linhas do arquivo e armazena em funcaoTransicao
    int i = 0;
    while (fgets(aux[i], sizeof(aux), arq) != NULL) {
        // Processa a função de transição aqui, se necessário
        i++;
    }

    fclose(arq);

    // Copia a primeira linha de funcaoTransicao para aux
    
    //strcpy(aux, funcaoTransicao[0]);

    printf("Estados do automato: %s\n", Q);
    q_0 = Q[0];
    printf("Alfabeto: %s\n", alfabeto);
    printf("Cadeia: %s\n", cadeia);
    printf("Funcao de transicao: %c\n", aux[0][0]);
    for (int i = 0; i < n-4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", aux[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //teste
    AFD(Q, alfabeto, aux, q_0, F, cadeia);
    

    return 0;
}

void AFD(char Q[], char E[], char d[][3], char q0, char F[], char palavra[])
{
    int i = 0;
    int n = contarLinhasArquivo("entrada.txt") - 4;
    char estadoAtual = q0;
    while (palavra[i] != '\0')
    {
        for (int j = 0; j < n; j++)
        {
            if (d[j][0] == estadoAtual && d[j][1] == palavra[i])
            {
                estadoAtual = d[j][2];
                break;
            }
        }
        i++;
    }
    for (int i = 0; F[i] != '\0'; i++)
    {
        if (estadoAtual == F[i])
        {
            printf("ACEITA\n");
            return;
        }
    }
    printf("REJEITA\n");
}

int contarLinhasArquivo(const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return -1;
    }

    int contador = 0;
    char linha[100];

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        contador++;
    }

    fclose(arq);
    return contador;
}