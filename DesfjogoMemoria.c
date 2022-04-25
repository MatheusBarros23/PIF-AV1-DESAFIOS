/*Implemente o jogo da memória. Este jogo deve ser jogado entre duas pessoas e, cada uma
por vez, deve tentar encontrar duas cartas iguais. Caso sejam iguais, o jogador atual ganha
um ponto e passa a vez para o oponente. Caso o jogador erre, as cartas devem ser
desviradas e o oponente passa a jogar. O jogo deve ser encerrado quando não houver mais
cartas a serem desviradas. Imprima na tela o resultado do jogo: empate ou vitória de algum
jogador.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int cont=4;
    int qtdPecas=8;
    int tela[cont][cont];
    srand(time(NULL));

//inicializar tela
    for (int l = 0; l < cont; l++)
    {
        for (int c = 0; c < cont; c++)
        {
            tela[l][c]=0;
        }
    }

//colocar peças
    int cont1=2,cont2=2,cont3=2,cont4=2,cont5=2,cont6=2,cont7=2,cont8=2; //contadores peças
    int numP;
for (int n = 0; n < 30; n++) //rodar quantas vezes necessarias para completar todas as peças!! Sei que prejudica a performace, mas foi como consegui resolver o erro D:
{
     for (int l = 0; l < 4; l++)
        {
            for (int c = 0; c < 4; c++)
            {
                numP=(rand()%8)+1;
                if (numP==1&&cont1>0)
                {
                    if (tela[l][c]==0)
                    {
                        tela[l][c]=numP;
                        cont1--;
                    }

                }else if (numP==2&&cont2>0)
                {
                    if (tela[l][c]==0)
                    {
                        tela[l][c]=numP;
                        cont2--;
                    }
                }else if (numP==3&&cont3>0)
                {
                    if (tela[l][c]==0)
                    {
                        tela[l][c]=numP;
                        cont3--;
                        }
                }else if (numP==4&&cont4>0)
                {
                    if (tela[l][c]==0)
                    {
                        tela[l][c]=numP;
                        cont4--;
                    }
                }else if (numP==5&&cont5>0)
                {
                    if (tela[l][c]==0)
                    {
                        tela[l][c]=numP;
                        cont5--;
                    }
                }else if (numP==6&&cont6>0)
                {
                    if (tela[l][c]==0)
                    {
                        tela[l][c]=numP;
                        cont6--;
                    }
                }else if (numP==7&&cont7>0)
                {
                    if (tela[l][c]==0)
                    {
                        tela[l][c]=numP;
                        cont7--;
                    }
                }else if (numP==8&&cont8>0)
                {
                    if (tela[l][c]==0)
                    {
                        tela[l][c]=numP;
                        cont8--;
                    }
                }
            }
        }
    }
   // printf("%d %d %d %d %d %d %d %d\n",cont1,cont2,cont3,cont4,cont5,cont6,cont7,cont8); //Para saber se todos os numeros tem pares(contn=0)

    /*for (int l = 0; l < cont; l++) //saber as posicoes dos numeros, para teste!
    {
        for (int c = 0; c < cont; c++)
        {
            printf("%d",tela[l][c]);
        }
        printf("\n");
    }*/ 


     //print Tela fechada
    for (int l = 0; l < cont; l++)
    {
        for (int c = 0; c < cont; c++)
        {
            printf(" # ");
        }
        printf("\n");
    }
    int player=1;
    int pts1=0;
    int pts2=0;
do{
//pegar input
    if(player%2==1){
    int lI,cI;
    printf("P1>");
    
    scanf("%d %d",&lI,&cI);

    for (int l = 0; l < cont; l++)
    {
        for (int c = 0; c < cont; c++)
        {
            if(lI==l && cI==c){
                printf(" %d ",tela[l][c]);
            }else{
                printf(" # ");
            }
        }
        printf("\n");
    }
    int lI2,cI2;
    printf("\nP1>");
    
    scanf("%d %d",&lI2,&cI2);

    for (int l = 0; l < cont; l++)
    {
        for (int c = 0; c < cont; c++)
        {
            if(lI2==l && cI2==c ||lI==l && cI==c){
                printf(" %d ",tela[l][c]);
            }else{
                printf(" # ");
            }
        }
        printf("\n");
    }
    if(tela[lI][cI]==tela[lI2][cI2])
    {
        printf("\n==ACERTOU!!==\n");
        pts1++;
    }else{
            printf("\n\t=Errou!!=\n");
            for (int l = 0; l < cont; l++)
            {
                for (int c = 0; c < cont; c++)
                {
                    printf(" # ");
                }
            printf("\n");
            }
        }
    }else if (player%2==0)
    {
        int lI,cI;
    printf("\nP2>");
    
    scanf("%d %d",&lI,&cI);

    for (int l = 0; l < cont; l++)
    {
        for (int c = 0; c < cont; c++)
        {
            if(lI==l && cI==c){
                printf(" %d ",tela[l][c]);
            }else{
                printf(" # ");
            }
        }
        printf("\n");
    }
    int lI2,cI2;
    printf(">");
    scanf("%d %d",&lI2,&cI2);

    for (int l = 0; l < cont; l++)
    {
        for (int c = 0; c < cont; c++)
        {
            if(lI2==l && cI2==c ||lI==l && cI==c){
                printf(" %d ",tela[l][c]);
            }else{
                printf(" # ");
            }
        }
        printf("\n");
    }
        if(tela[lI][cI]==tela[lI2][cI2])
        {
            printf("\n==ACERTOU!!==\n");
            pts2++;
        }else{
            printf("\n\t=Errou!!=\n");
            for (int l = 0; l < cont; l++)
            {
                for (int c = 0; c < cont; c++)
                {
                    printf(" # ");
                }
            printf("\n");
            }
        }
    }
    printf("P1: %d\n",pts1);
    printf("P2: %d\n",pts2);
    player++;
}while(pts1<5||pts2<5);
    
    if(pts1==5)
    {
        printf("\n\t==Player1 GANHOU!!==\n");
    }else if(pts1==5)
    {
        printf("\n\t==Player2 GANHOU!!==\n");
    }else{
        printf("\n\t==DEU EMPATE!!==\n");
    }

    return 0;
}