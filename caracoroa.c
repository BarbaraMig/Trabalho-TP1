#include <stdio.h>
int main(){
    int N=-1, resultado, winsJ = 0, winsM = 0, cont = 0, flag = 0;
// só ta rodando uma vez, tem que rodar enquanto o N for 0
    while (N!=0){

        while(N<1||N>10000){
            printf("\ninsira o numero de rodadas: ");     
            scanf("%d", &N);
            if(N==0){
                printf("programa encerrado");
                break;
            }            
            else if(N<1||N>10000){
                printf("\ninsira o numero de rodadas: ");     
                scanf("%d", &N);
                break;
            }
            else{
                break;
            }
        }
        printf("\ninsira os resultados: ");

        for(cont=0;cont<N;cont++){

            scanf("%d", &resultado);
            switch (resultado)
            {
            case 0:
                winsM++;
                break;
            case 1:
                winsJ++;
                break;
            default:
                flag++;
                break;
            }

        }

        if(flag>0){
            printf("valor(es) invalido(S)");
            break;
            }
            else{
                printf("Maria venceu %d vez(es) e Joao venceu %d vez(es)", winsM, winsJ);
                break;
            }
        
        
    }


    return 0;
}

