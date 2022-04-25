/*Questão 1: Um sistema de controle de estoque armazena o código (inteiro), a quantidade
em estoque (inteiro) e o preço unitário (float) das mercadorias. Fazer um aplicativo que
exiba um menu com as seguintes opções:
MENU
1 - Cadastrar mercadoria
2 - Consultar mercadoria
3 - Valor total em mercadorias
4 - Sair
Inicialmente a não há nenhuma mercadoria cadastrada. A primeira opção permitirá que o
usuário cadastre uma nova mercadoria, informando todos os dados citados anteriormente.

A segunda opção permitirá que o usuário consulte o cadastro, informando o código da
mercadoria.

A terceira opção permitirá a consulta do valor total do estoque, levando em conta todas as
mercadorias cadastradas.

A quarta opção permitirá o término do aplicativo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){

    int op;
    int codProd[20];
    int qtdEstoq[20];
    float precoProd[20];

    int cont=0; //serve como variavel de incremento para quando o loop continuar, seguir para a prox posicao

    //printf("%d\n",sizeof(codProd)/sizeof(qtdEstoq[0])); //para saber a quantidade eu utilizo o sizeof(nome)/sizeof(nome[0]) Prob que isso so funciona quando consigo trabalhar com nome[]={1,2,3}, pq quando coloco a qtd nao funciona mais ex.:nome[10]={1,2,3}
    
    while(1){
        printf("\n\t\t==SISTEMA DE CADASTROS DE MERCADORIAS==\n");
        printf("     MENU: \n\t1 - Cadastrar Mercadoria\n\t2 - Consultar Mercadoria\n\t3 - Valor Total das Mercadorias\n\t4 - SAIR\nO que deseja fazer?");
        scanf("%d",&op);

        if (op==1) //cadastrar mercadorias 
        {
            int qtdAtual; //variaveis para trabalhar so no cadastro
            int codAtual;
            float precoAtual;

            printf("\n--CADASTRO MERCADORIAS: ");

        //cod produto
            printf("\n\tInforme o código da mercadoria: ");
            scanf("%d",&codAtual);
            codProd[cont]=codAtual;
        //qtd produto    
            printf("\n\tAgora, nos informe sua qtd: ");
            scanf("%d",&qtdAtual);
            qtdEstoq[cont]=qtdAtual;
        //preco Produto    
            printf("\n\tInforme o preço unitario das mercadorias: ");
            scanf("%f",&precoAtual);
            precoProd[cont]=precoAtual;
            cont++; 
        
        }else if (op==2) //Consultar mercadorias 
        {
            int codAtual;
            printf("\n--CONSULTA DE MERCADORIAS: ");

        //cod produto
            printf("\n\tInforme o código da mercadoria que deseja consultar: ");
            scanf("%d",&codAtual);
            
            int c=0; //para saber que o codigo esta errado
            for (int i = 0; i < cont; i++) //posso fazer isso pq como o cont esta contando a quantidade de loops, entao posso usar como limite do for, para economizar processamento
            {
                if(codAtual==codProd[i]){
                    printf("\nACHEI!");
                    printf("\n\t[Codigo: %d]| Qtd: %d| Preço(unidade): R$%.2f\n",codAtual,qtdEstoq[i],precoProd[i]);
                    c= 1;
                }
            }
            if(c==0){
                    printf("\nDESCULPE, mas não consegui encontrar pelo codigo informado! Tente novamente");
            }
        
        }else if (op==3) //Valor Total Mercadorias 
        {
            float soma=0; //importante atribuir valor 0 para que no prox loop o valor nao fique salvo
            printf("\n--VALOR TOTAL DAS MERCADORIAS: ");

        //for para rodar as listas e pegar a qtd e valores
            for (int i = 0; i < cont; i++) //posso usar o mesmo for para as 2 listas pois estao em ordem
            {
                soma+=qtdEstoq[i]*precoProd[i];
            }
            printf("\n\tO preço TOTAL das mercadorias é de R$%.2f\n",soma);
        }
        else if (op==4) //SAIR
        {
            printf("\n --Até a proxima!! o/-- ");
            break;
        }
              
    }

    return 0;
}