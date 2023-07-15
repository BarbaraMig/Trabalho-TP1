#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define min_v 45

typedef struct {
    char nome[30];
    int ponto;
} jogador;

int cont2 = 0;

int encontrarPalavra(char matriz[10][10], char palavra[10]) {
    int tamanho = strlen(palavra);
    int linha, coluna, i, j, k;
    int ocorrencias = 0;

    // Verificar horizontalmente
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna <= 10 - tamanho; coluna++) {
            int match = 1;
            for (i = 0; i < tamanho; i++) {
                if (matriz[linha][coluna + i] != palavra[i]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Palavra '%s' encontrada na horizontal! Início: linha %d, coluna %d\n", palavra, linha, coluna);
                ocorrencias++;
            }
        }
    }

    // Verificar verticalmente
    for (coluna = 0; coluna < 10; coluna++) {
        for (linha = 0; linha <= 10 - tamanho; linha++) {
            int match = 1;
            for (i = 0; i < tamanho; i++) {
                if (matriz[linha + i][coluna] != palavra[i]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Palavra '%s' encontrada na vertical! Início: linha %d, coluna %d\n", palavra, linha, coluna);
                ocorrencias++;
            }
        }
    }

    // Verificar diagonalmente (esquerda para a direita, cima para baixo)
    for (linha = 0; linha <= 10 - tamanho; linha++) {
        for (coluna = 0; coluna <= 10 - tamanho; coluna++) {
            int match = 1;
            for (i = 0; i < tamanho; i++) {
                if (matriz[linha + i][coluna + i] != palavra[i]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Palavra '%s' encontrada na descendo a diagonal! Início: linha %d, coluna %d\n", palavra, linha, coluna);
                ocorrencias++;
            }
        }
    }

    // Verificar diagonalmente (esquerda para a direita, baixo para cima)
    for (linha = tamanho - 1; linha < 10; linha++) {
        for (coluna = 0; coluna <= 10 - tamanho; coluna++) {
            int match = 1;
            for (i = 0; i < tamanho; i++) {
                if (matriz[linha - i][coluna + i] != palavra[i]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Palavra '%s' encontrada na subindo a diagonal! Início: linha %d, coluna %d\n", palavra, linha, coluna);
                ocorrencias++;
            }
        }
    }

    return ocorrencias;
}

void preencherMatriz(char matriz[10][10]) {
    int seed;

    printf("Digite um número inteiro para a semente: ");
    scanf("%d", &seed);

    srand(seed);

    int v = 0;

    // Preencher a matriz com caracteres aleatórios
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = 'a' + rand() % 26;;

            // Verificar se é uma vogal
            if (matriz[i][j] == 'a' || matriz[i][j] == 'e' || matriz[i][j] == 'i' || matriz[i][j] == 'o' || matriz[i][j] == 'u')
                v++;
        }
    }

    // Adicionar vogais adicionais se necessário
    while (v < min_v) {
        int l = rand() % 10;
        int c = rand() % 10;

        if (matriz[l][c] != 'a' && matriz[l][c] != 'e' && matriz[l][c] != 'i' && matriz[l][c] != 'o' && matriz[l][c] != 'u') {
            matriz[l][c] = 'a' + rand() % 26;
            v++;
        }
    }
}

int main() {
    int NumJ, cont;
    char matriz[10][10], palavra[10];

    do {
        printf("Quantos jogadores vão jogar? ");
        scanf("%d", &NumJ);
        getchar();
        if (NumJ < 2)
            printf("Mínimo de dois jogadores.\n");
    } while (NumJ < 2);

    jogador jog[NumJ];

    for (cont = 0; cont < NumJ; cont++) {
        printf("Insira o nome do jogador %d: ", cont + 1);
        fgets(jog[cont].nome, 30, stdin);
        jog[cont].nome[strlen(jog[cont].nome) - 1] = '\0';
        jog[cont].ponto = 0;
    }

    preencherMatriz(matriz);

    do {
        for (int i = 0; i < NumJ; i++) {
            printf("\n\n");
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++)
                    printf("%c  ", matriz[j][k]);
                printf("\n");
            }
            
            
            do{
                printf("\n%s, qual é a sua palavra: ", jog[i].nome);
                scanf("%s", palavra);
                if (strcmp(palavra, ".") == 0)
                    break;
                if (strlen(palavra)<2)
                    printf("Min. de letras: 2\n\n");
            }while (strlen(palavra)<2);

            if (strcmp(palavra, ".") == 0)
                break;

            int ocorrencias = encontrarPalavra(matriz, palavra);
            jog[i].ponto += ocorrencias;

            printf("\nA palavra '%s' foi encontrada %d vez(es) na matriz.\n", palavra, ocorrencias);
        }
    } while (strcmp(palavra, ".") != 0);

    int max_pontos = jog[0].ponto;
    int empate = 0;
    printf("\n\nPontuação final:\n");
    for (int i = 0; i < NumJ; i++) {
        printf("%s: %d ponto(s)\n", jog[i].nome, jog[i].ponto);
        if (jog[i].ponto > max_pontos)
            max_pontos = jog[i].ponto;
    }

    if(max_pontos == 0)
        printf("Não ha vencedores!\n");
    else{
        printf("\nVencedor(es):\n");
        for (int i = 0; i < NumJ; i++) {
            if (jog[i].ponto == max_pontos)
                printf("%s\n", jog[i].nome);
        }
    }

    return 0;
}
