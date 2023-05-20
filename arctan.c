

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
#include <stdio.h>
int main(){

    float x;
    int N;
    int cont = 0;
        printf("insira o valor de n: ");
        scanf("%d",&N);
    while( N<0 ){
        printf("numero invalido. insira novamente o valor de N: ");
        scanf("%d", &N);
    }    
    printf("insira o valor de x: ");
    scanf("%f",&x);
    while( x>=1 || x<=-1 ){
        printf("numero invalido. insira novamente o valor de x: ");
        scanf("%f", &x);
        
    }

float ipot;
float arctan;
float y = x;
//o loop das "rodadas"

while(cont<N){
    int k = (2 * cont) + 1;
//Coloca o k para ser 2i+1 e usa ele no for da potência
//loop da potencia
        x = y;
    for(ipot = 1; ipot<k; ipot++){
        
        //+_(1/k) * x^k        
        x = x * y;
    }
    if(cont % 2 == 0){
        arctan = arctan + (1 * x)/k;
    }
    else{
        arctan = arctan - (1 * x)/k;
    }
    cont++;
}
    
//o problema tava em algum lugar na soma, provavelmente no (2*cont+1)
//agora alguns resultados vão mas outros tem umas diferenças e quanto mais próximo do limite maior a diferença

printf("%f", arctan);

    return 0;
}
