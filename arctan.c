#include <stdio.h>
int main(){
//
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
    float x, n;
    printf("insira o valor de x: ");
    scanf("%f", &x);
    printf("insira o valor de n: ");
    scanf("%f", &n);
    float arctan;





    return 0;
}
