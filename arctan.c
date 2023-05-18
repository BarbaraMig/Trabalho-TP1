#include <stdio.h>

//Crie um programa em C que lê primeiramente um valor x (|x| < 1), e em seguida um
//valor n (n ≥ 0) onde n é o número de termos da série e imprime o valor do arco-tangente,
//calculado de acordo com a fórmula acima.

//Restrições:
//a) |x| <1. Se |x| ≥ 1, então solicite novamente o valor até o usuário digitar corretamente.
//b) n ≥ 0. Se n < 0, então solicite novamente o valor até o usuário digitar corretamente.
//c) Não poderá ser usada nenhuma função matemática implementada na biblioteca do
//C/C++ nem em nenhuma outra biblioteca.
//d) Não poderão ser usados vetores nem qualquer outro tipo de estrutura de dados, somente variáveis simples.
//e) Todo o código deverá estar implementado na função main, sem o uso de funções auxiliares, com a exceção das funções scanf, printf e fflush.
int main(){
    double x;
    int N = -1;
    int pot = 1.0;
    int cont = 0;
    printf("insira o valor de x: ");
    scanf("%f",&x);
    while( x>=1 || x<=-1 ){
        printf("insira novamente o valor de x: ");
        scanf("%f", &x);
    }//primeira parte parece certa

        printf("insira o valor de n: ");
        scanf("%d",&N);
    while( N<0 ){
        printf("insira novamente o valor de N: ");
        scanf("%d", &N);
    }


int ip;

while(i<N){

//o loop da potência
for(cont; cont<N; cont++){
int k = (2 * cont) + 1;
    for(ip = 0; ip<k; ip++){
        pot = x * x;
    }
    x = x + (x * pot);
}
}

printf("%lf", x);

    return 0;
}
