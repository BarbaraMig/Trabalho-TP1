#include <stdio.h>

void lerFuncionario(char *funcao, int *experiencia, int *hrsContratadas, int *hrsTrabalhadas){

// ler os dados do funcionario e devolver por 'parametros de saida' ao main
    int invalido;
    getchar();
    do{
    printf("Insira a funcao do funcionario: ");
    scanf("%c", funcao);
    
    invalido = 0;
    
        switch(*funcao){
            
            case 'a':
            case 'A':
            case 'p':
            case 'P':
            case 'g':
            case 'G':
            break;
            default:
                invalido = 1;
                break;
        }
        
    }while(invalido);
    
    do{
        
        printf("\nInsira os anos de experiencia: ");
        scanf("%d", experiencia);
        
    }while(*experiencia < 0);
    
    printf("\nInsira as horas contratadas no mes: ");
    scanf("%d", hrsContratadas);
    printf("\nInsira as horas trabalhadas no mes: ");
    scanf("%d", hrsTrabalhadas);
}

float calcularSalario(char funcao, int experiencia,  int hrsContratadas, int hrsTrabalhadas, int *hrsExcedentes, float *salarioBruto, float *descontoINSS, float *descontoIR){
//Entrada: a função do funcionario, o tempo de experiência, as horas contradas, e a quantidade de horas realmente trabalhadas. Deve retornar o salario líquido, e conter os 'parametros de saida': salario bruto do mês, o número de horas excedentes, desconto do INSS e do IR

    *hrsExcedentes = hrsTrabalhadas - hrsContratadas;
    int valorHora;
    switch (funcao)
    {

    case 'p':
    case 'P':
        if (experiencia <= 2) valorHora = 25;
        else if (experiencia >= 3 &&  experiencia < 5) valorHora = 30;
        else if (experiencia >= 5) valorHora = 38;
        break;
        
    case 'a':
    case 'A':
        if (experiencia <= 2) valorHora = 45;
        else if (experiencia >= 3 && experiencia < 5) valorHora = 50;
        else if (experiencia >= 5) valorHora = 70;
        break;

    case 'g':
    case 'G':
        if (experiencia <= 2) valorHora = 85;
        else if (experiencia >= 3 && experiencia < 5) valorHora = 102;
        else if (experiencia >= 5) valorHora = 130;
        break;

    default:
        break;
        }

    float aumento;
    if (*hrsExcedentes > 0)   
    {
        if (*hrsExcedentes < 13) aumento = 1.23;
        else if (*hrsExcedentes >= 13 && *hrsExcedentes < 22) aumento = 1.37;
        else if (*hrsExcedentes >= 22) aumento = 1.56;
        
    }

    float valorExcedenteHrsContratadas = *hrsExcedentes * aumento;

//calcula desconto do INSS:
*descontoINSS = *salarioBruto * 0.11;

//calcula desconto do IR:
if (*salarioBruto < 1500) *descontoIR = 0;

else if (*salarioBruto < 2700 && *salarioBruto > 1500) *descontoIR = (*salarioBruto - *descontoINSS) * 0.15;

else if (2700 < *salarioBruto < 4200) *descontoIR = (*salarioBruto - *descontoINSS) * 0.20;

else if (*salarioBruto > 4200) *descontoIR = (*salarioBruto - *descontoINSS) * 0.30;


*salarioBruto = hrsTrabalhadas * valorHora + valorExcedenteHrsContratadas;
return (*salarioBruto - *descontoINSS - *descontoIR);

}

void imprimirFolhaPagamento(float salarioBruto, float descontoINSS, float descontoIR, float salarioLiquido){
//deve printar o salario bruto do mês, as horas excedentes, desconto do INSS e do IR e o salario liquido. Não deve retornar nada
    printf("Folha de pagamento do funcionario \n Salario Bruto...(R$): %.2f \n Desconto INSS...(R$): %.2f \n Desconto IR....(R$): %.2f \n Salario liquido.(R$): %.2f ", salarioBruto, descontoINSS, descontoIR, salarioLiquido);
}
//dentro dos parenteses da subrotina ficam os parametros de entrada
int main(){
    float salarioBruto, descontoINSS, descontoIR, salarioLiquido;
    int N, cont, experiencia, hrsContratadas, hrsTrabalhadas, hrsExcedentes, percentualHrsContratadasTrabalhadas;
    char funcao;
    do
    {
        printf("numero de funcionarios: ");
    scanf("%d", &N);
    } while (N < 1);
    
        for(cont = 0; cont<N; cont++){
            lerFuncionario(&funcao, &experiencia, &hrsContratadas, &hrsTrabalhadas);
            salarioLiquido = calcularSalario(funcao, experiencia, hrsContratadas, hrsTrabalhadas, &hrsExcedentes, &salarioBruto, &descontoINSS, &descontoIR);
            imprimirFolhaPagamento(salarioBruto, descontoINSS, descontoIR, salarioLiquido);
            
        }


}
//implementar os ponteiros e depois ver o motivo da funcao lerfuncionario estar imprimindo mais de uma mensagem de uma vez só
