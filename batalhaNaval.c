#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Declarando variáveis, vetores e matrizes
    int tabuleiro[LINHAS][COLUNAS]; // matriz bidimensional representando as posições do tabuleiro (10 x 10)
    int tamanhoNavio = 3; // quantidade de posições que os navios ocupam no tabuleiro
    int linhaInicialNavio1 = 3; // linha inicial onde o navio será posicionado
    int colunaInicialNavio1 = 3; // coluna inicial onde o navio será posicionado
    int navio1[tamanhoNavio]; // vetor de colunas onde o navio será posicionado (horizontalmente)
    int linhaInicialNavio2 = 5; // linha inicial onde o navio será posicionado
    int colunaInicialNavio2 = 7; // coluna inicial onde o navio será posicionado
    int navio2[tamanhoNavio]; // vetor de linhas onde o navio2 será posionado (verticalmente)
    int linhaInicialNavio3 = 6; // linha inicial onde o navio será posicionado
    int colunaInicialNavio3 = 3; // coluna inicial onde o navio será posicionado
    int navio3[tamanhoNavio]; // vetor de linhas onde o navio3 será posionado (na diagonal)
    int linhaInicialNavio4 = 2; // linha inicial onde o navio será posicionado
    int colunaInicialNavio4 = 7; // coluna inicial onde o navio será posicionado
    int navio4[tamanhoNavio]; // vetor de linhas onde o navio4 será posionado (na diagonal)
    int temSobreposicao = 0; // variavel que controla se navio4 sobrepoe navio1

    // Preenchendo todas as posições do tabuleiro com 0
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Preenchendo as colunas do navio1
    for (int i = 0; i < tamanhoNavio; i++)
    {
        navio1[i] = i + colunaInicialNavio1;
    }
    
    // Preenchendo as linhas do navio2
    for (int i = 0; i < tamanhoNavio; i++)
    {
        navio2[i] = i + linhaInicialNavio2;
    }

    // Verificando se navio2 sobrepoe navio1
    for (int i = 0; i < tamanhoNavio; i++)
    {
        for (int j = 0; j < tamanhoNavio; j++) {
            if (navio1[i] == colunaInicialNavio2 && linhaInicialNavio1 == navio2[j]) {
                temSobreposicao = 1;
                break;
            }     
        }
    }

    // Preenchendo as linhas do navio3
    for (int i = 0; i < tamanhoNavio; i++)
    {
        navio3[i] = i + colunaInicialNavio3;
    }

    // Preenchendo as linhas do navio4
    for (int i = 0; i < tamanhoNavio; i++)
    {
        navio4[i] = linhaInicialNavio4 - i;
    }
    
    // Posicionando o navio1, horizontalmente, no tabuleiro
    for (int i = 0; i < tamanhoNavio; i++)
    {
        if (linhaInicialNavio1 >= 0 && linhaInicialNavio1 <= 9 && navio1[i] >= 0 && navio1[i] <= 9) {
            tabuleiro[linhaInicialNavio1][navio1[i]] = 3;
        } else {
            printf("Coordenadas do navio1 estão fora dos limites do tabuleiro\n");
            break;
        }
    }
    
    // Posicionando o navio2, verticalmente, no tabuleiro 
    for (int i = 0; i < tamanhoNavio; i++)
    {
        if (navio2[i] >= 0 && navio2[i] <= 9 && colunaInicialNavio2 >= 0 && colunaInicialNavio2 <= 9) {
            if (temSobreposicao == 0) {
                tabuleiro[navio2[i]][colunaInicialNavio2] = 3;
            } else {
                printf("Uma das coordenadas do navio2 está sobrepondo uma das coordenadas do navio1\n");
                break;
            }
        } else {
            printf("Coordenadas do navio2 estão fora dos limites do tabuleiro\n");
            break;
        }
    }

    // Posicionando o navio3, na diagonal, no tabuleiro 
    for (int i = 0; i < tamanhoNavio; i++)
    {
        if (navio3[i] >= 0 && navio3[i] < LINHAS && colunaInicialNavio3 >= 0 && colunaInicialNavio3 < COLUNAS) {
            if (temSobreposicao == 0) {
                tabuleiro[linhaInicialNavio3 + i][navio3[i]] = 3;
            } else {
                printf("Uma das coordenadas do navio3 está sobrepondo uma das coordenadas de outro navio\n");
                break;
            }
        } else {
            printf("Coordenadas do navio3 estão fora dos limites do tabuleiro\n");
            break;
        }
    }

    // Posicionando o navio4, na diagonal, no tabuleiro 
    for (int i = 0; i < tamanhoNavio; i++)
    {
        if (navio4[i] >= 0 && navio4[i] < LINHAS && colunaInicialNavio4 >= 0 && colunaInicialNavio4 < COLUNAS) {
            if (temSobreposicao == 0) {
                tabuleiro[navio4[i]][colunaInicialNavio4 + i] = 3;
            } else {
                printf("Uma das coordenadas do navio4 está sobrepondo uma das coordenadas de outro navio\n");
                break;
            }
        } else {
            printf("Coordenadas do navio4 estão fora dos limites do tabuleiro\n");
            break;
        }
    }

    // Exibindo o tabuleiro com os navios posicionados
    printf(" TABULEIRO BATALHA NAVAL\n");
    printf("  ");
    for (char i = 'A'; i < 'K'; i++)
    {
        printf(" %c", i);
    }
    printf("\n");
    for (int i = 0; i < LINHAS; i++)
    {
        if (i + 1 < LINHAS) {
            printf(" %d", i + 1);
        } else {
            printf("%d", i + 1);
        }
        for (int j = 0; j < COLUNAS; j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
