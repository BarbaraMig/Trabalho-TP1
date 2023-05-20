

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

int ipot;
double arctan;
float y = x;
//o loop das "rodadas"

while(cont<=N){
    float k = (2 * cont) + 1;
//Coloca o k para ser 2i+1 e usa ele no for da potência
//loop da potencia
        x = y;
    for(ipot = 1; ipot<k; ipot++){
        
        //+_(1/k) * x^k        
        x =  x * y;
    }
    if(cont % 2 == 0){
        arctan = arctan + (1.0/(float)(2 * cont + 1)) * x;
    }
    else{
        arctan = arctan - (1.0/(float)(2 * cont + 1)) * x;
    }
    cont++;
}
    
//o problema tava em algum lugar na soma, provavelmente no (2*cont+1)
//agora alguns resultados vão mas outros tem umas diferenças e quanto mais próximo do limite maior a diferença
//(X__certo__resultado do programa
//(0.1__0.9966__0.099669)
//(0.2__0.19739__0.197396)
//(0.3__0.29145__0.291457)
//(0.4__0.38050__0.380510)
//(0.5__0.46363__0.463684)
//(0.6__0.54034__0.540673)
//(0.7__0.61020__0.612000)
//(0.8__0.67201__0.679823)
//(0.9__072128__0.749817)
//(0.99__0.74372__0.825115)

printf("%lf", arctan);

    return 0;
}
