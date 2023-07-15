#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define min_v 45

typedef struct{
    char nome[30];
    int ponto;
} jogador;

int cont2 = 0;

void preencherMatriz(char matriz[10][10]){
    int seed;

    printf("Digite um numero inteiro para a semente: ");
    scanf("%d", &seed);
    
    srand(seed);

    int v = 0;

    // Preencher a matriz com caracteres aleatórios
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matriz[i][j] = 'a' + rand() % 26;;

            // Verificar se é uma vogal
            if (matriz[i][j] == 'a' || matriz[i][j] == 'e' || matriz[i][j] == 'i' || matriz[i][j] == 'o' || matriz[i][j] == 'u')
                v++;
        }
    }

    // Adicionar vogais adicionais se necessário
    while (v < min_v)
    {
        int l = rand() % 10;
        int c = rand() % 10;

        if (matriz[l][c] != 'a' && matriz[l][c] != 'e' && matriz[l][c] != 'i' && matriz[l][c] != 'o' && matriz[l][c] != 'u'){
            matriz[l][c] = 'a' + rand() % 26;
            v++;
        }
    }
}

int comparar(char matriz[10][10], char palavra[10]){
    char trecho[10];    
    int p = 0;
    
    // verifica verticalmente
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++)
            trecho[j] = matriz[j][i];
        char *ver = strstr(trecho, palavra);
        if(ver)
            p += 1;
    }
    
    // verifica horizontalmente
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++)
            trecho[j] = matriz[i][j];
        char *ver = strstr(trecho, palavra);
        if(ver)
            p += 1;
    }
    
    if(p != 0)
        return p;
    
    printf("\nA palavra não foi encontrada!");
    return -1;
}

int main(){
    //perguntar o número de jogadores e seus nomes
    int NumJ, cont;
    char matriz[10][10], palavra[10];
    
    //verificar o numero de jogadores
    do{
        printf("Quantos jogadores vao jogar? ");
        scanf("%d", &NumJ);
        getchar();
    }while(NumJ < 1);
    
    jogador jog[NumJ];
    //Insira o nome do jogador 0: Insira o nome do jogador 1: 
    for(cont = 0; cont < NumJ; cont++){
        printf("Insira o nome do jogador %d: ", cont+1);
        fgets(jog[cont].nome, 30, stdin);
        jog[cont].nome[strlen(jog[cont].nome)-1] = '\0';
        jog[cont].ponto = 0;
    }

    preencherMatriz(matriz);
    
    do{
        for(int i = 0; i < NumJ; i++){
            // apresenta a matriz
            for (int j = 0; j < 10; j++){
                printf("\n");
                for (int k = 0; k < 10; k++)
                    printf("%c  ", matriz[j][k]);
            }
            
            printf("\n\n%s, qual a sua palavra: ", jog[i].nome);
            scanf("%s", palavra);
            if(i==0 && *palavra == '.')
                break;
            else
                jog[i].ponto += comparar(matriz, palavra);
            printf("\n");
        }
    } while(*palavra != '.');
    
    int ganhador = 0, empate = 0;

    for(int i = 0; i < NumJ; i++)
        if (jog[ganhador].ponto < jog[i].ponto){
            ganhador = i;
        }
        else if (jog[ganhador].ponto == jog[i].ponto){
            ganhador = i;
            empate  += 1;
        }
        
            
    if(empate > 0){
        printf("Vencedores:\n");
        for(int cont = 0; cont < empate; cont++){
            if(jog[cont].ponto == jog[ganhador].ponto){
                printf("%s \n", jog[cont].nome);
            }

        }
    }
       
    else
        printf("\n\nVencedor(es): %s", jog[ganhador].nome);
/*o programa roda além do ponto de finalização, não aparece se a palavra foi encontrada ou não e não aparece one foi encontrada*/

    return 0; 
}
