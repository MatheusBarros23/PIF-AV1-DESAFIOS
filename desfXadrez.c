/*
Desafio 1:
Crie um programa que inicializa 10 pedras de xadrez aleatoriamente em um tabuleiro 8x8.

Essas 10 pedras pertencem ao jogador1. 
O programa vai inicializar aleatoriamente 1 pedra
para o jogador2, que trata-se de uma torre.

O programa deve informar se a torre do jogador2 é capaz de derrubar ao menos uma pedra
do jogador1.

Em caso positivo, imprima “jogador2 derruba uma pedra”. Caso contrário, imprima “jogador2
não derruba nenhuma pedra”.

A figura abaixo mostra como uma torre se movimenta:

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main (){

    int pecasJ1[10];
    int casasJ1[10];
    int colunasJ1[10];
    int linhasJ1[10];

    printf("\n");

//estabelecendo aleatoriedade das peças do jogador1 e sua correspondencia no tabuleiro.
    for (int i = 0; i < 10; i++)
    {
        pecasJ1[i]=rand() % 63+1;  //de 1 a 64 pois existem 8x8 posicoes no tabuleiro. 

        if (pecasJ1[i]%8!=0)
        {      //variaveis para armazenar em listas todos esses dados que foram printados, para depois apresentar de forma mais otimizada
            casasJ1[i]=pecasJ1[i];
            colunasJ1[i]=(pecasJ1[i]/8)+1; //Isso acontece pois quando dividimos por 8, o inteiro que sobra +1 corresponde a posicao da linha ( +1, pois como o numero "quebra", significa que pertence a prox linha).
            linhasJ1[i]=pecasJ1[i]%8; //enquanto o resto corresponde com a coluna.
            
        }else{ // Diferente modo se da quando temos um divisor de 8 com resto zero, pois neste caso o valor permanece na mesma linha (nao precisando do +1), na ultima casa/coluna. Por isso o 8
            casasJ1[i]=pecasJ1[i];
            colunasJ1[i]=(pecasJ1[i]/8);
            linhasJ1[i]=8;
        }   
    }

//estabelecendo aleatoriedade da torre do jogador2 
    int casaJ2=rand() % 63+1;
    int colunaJ2;
    int linhaJ2;

    if (casaJ2%8!=0) //mesma condicional de cima
        {      //variaveis para armazenar em listas todos esses dados que foram printados, para depois apresentar de forma mais otimizada
           colunaJ2=(casaJ2/8)+1; 
           linhaJ2=casaJ2%8; 
        
        }else{ 
            colunaJ2=(casaJ2/8); 
            linhaJ2=8; 
        } 


//vamos printar as peçasdos j1 e j2:
    for (int i = 0; i < 10; i++)
    {
        printf("[Peça aleatoria J1- %i] Casa: %d Coluna: %d Linha:%d\n",i+1,casasJ1[i],colunasJ1[i],linhasJ1[i]);
    }
        printf("\n--[Peça aleatoria J2- 1] Casa: %d Coluna: %d Linha:%d\n",casaJ2,colunaJ2,linhaJ2);

//for para percorrer as listas e verificar se a posicao da torre do j2 corresponde a alguma das linhas ou colunas das peças do j1
    int cont=0; //so para saber se pelo menos 1 foi derrubada
    for (int i = 0; i < 10; i++)
    {
        if(colunasJ1[i]==colunaJ2 || linhasJ1[i]==linhaJ2){
            printf("\n\t==jogador2 derruba pelo menos uma pedra.==\n");
            cont++;
            break;
        }
    }
   
   if(cont==0){ //so entra se nenhuma peça foi derrubada
            printf("\n\t==“jogador2 não derrubou NENHUMA pedra!”.==\n");
        }
    return 0;
}