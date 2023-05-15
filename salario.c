#include <stdio.h>

//o programa deve ler função do funcionário(P-programador, A-analista, G-gerente), Anos de esperiência(int), Horas contratadas(int), Horas trabalhadas(int)
int N=0, cont=0, RSpH, EXP, hrsC, hrsT,hrsE;
char funcao;//não esquecer de jogar dentro das rotinas
float hrsEpt,salB,desINSS,desIR, salLq;


int lerFuncionario(){
// ler os dados do funcionario e devolver por 'parametros de saida' ao main
    printf("Insira a funcao do funcionario: ");
    scanf("%c", &funcao);
    printf("Insira os anos de experiencia: ");
    scanf("%d", &EXP);
    printf("Insira as horas contratadas no mes: ");
    scanf("%d", &hrsC);
    printf("Insira as horas trabalhadas no mes: ");
    scanf("%d", &hrsT);
}


float calcularSalario(char funcao, int EXP, int hrsC, int hrsT){
int hrsE,RSpH, hrsEpt
//Entrada: a função do funcionario, o tempo de experiência, as horas contratadas, e a quantidade de horas realmente trabalhadas. Deve retornar o salario líquido, e conter os 'parametros de saida': salario bruto do mês, o número de horas excedentes, desconto do INSS e do IR
    //porcentagem de horas excedentes
    int lerFuncionario(char *funcao, int *EXP, int *hrsC, int *hrsT);
    if(hrsE<=13){
        hrsEpt=1.23;
    }
    else if(hrsE>13 && hrsE<22){
        hrsEpt=1.37;
    }
    else{
        hrsEpt=1.56;
    }
do{
    switch (funcao)
    {// experiencia e função
    case 'p':
    case 'P':
        if(EXP<=2 && EXP>0){
            RSpH=25.0;
        }
        else if(EXP<=5 && EXP>3){
            RSpH=30.0;
        }
        else if(EXP>5){
            RSpH=38.0;
        }
       break;

    case 'a':
    case 'A':
        if(EXP<=2 && EXP>0){
            RSpH=45.0;
        }
        else if(EXP<=5 && EXP>3){
            RSpH=55.0;
        }
        else if(EXP>5){
            RSpH=70.0;
        }
        break;

    case 'g':
    case 'G':
        if(EXP<=2 && EXP>0){
            RSpH=85.0;
        }
        else if(EXP<=5 && EXP>3){
            RSpH=102.0;
        }
        else if(EXP>5){
            RSpH=130.0;
        }
        break;

    }    
    }while(funcao!='g'||funcao!='G'||funcao!='a'||funcao!='A'||funcao!='p'||funcao!='P');

if(hrsC>hrsT){
    salB= RSpH*hrsT*hrsEpt;
}
else{
    salB=(RSpH*hrsC*hrsEpt)+(hrsE*hrsEpt);
}
desINSS=salB*0.11;
if(salB<=1500){
    desIR=0;
}
else if(salB>1500 && salB<=2700){
    desIR=(salB*0.89)*0.15;
}
else if(salB>2700 && salB<=4200){
    desIR=(salB*0.89)*0.20;
}
else if(salB>4200){
    desIR=(salB*0.89)*0.30;
}

//100% do salario bruto menos 11% do INSS

}


void imprimirFolhaPagamento(int *cont, float *salB, float *desINSS, float *desIR, float *salLq){
//deve printar o salario bruto do mês, as horas excedentes, desconto do INSS e do IR e o salario liquido. Não deve retornar nada
    printf("Folha de pagamento do funcionario %d \n Salario Bruto...(R$): %.2f \n Desconto INSS...(R$): %.2f \n Desconto IR....(R$): %.2f \n Salario liquido.(R$): %.2f ", cont+1, salB, desINSS, desIR, salLq);
}
//dentro dos parenteses da subrotina ficam os parametros de entrada


int main(){
    printf("numero de funcionarios: ");
    scanf("%d", &N);
    while(N<0){
        printf("numero de funcionarios deve ser maior que 0, insira novamente: ");
        scanf("%d", &N);
    }
    //lerFuncionario
        for(cont;cont<N;cont++){
            //chamar as subrotinas e fazer o loop até cont=N
            float calcularSalario(&funcao,&EXP, &hrsC, &hrsT);
            void imprimirFolhaPagamento(&cont, &salB, &desINSS, &desIR, &salLq);
        }


}
