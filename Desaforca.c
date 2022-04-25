/*O jogo da forca é um jogo em que o jogador tem que acertar qual é a palavra proposta
DICA: número de letras + tema ligado à palavra. 

A cada letra errada, o usuário perde uma tentativa (o número é determinado pelo programador).

TERMINA: Acerto da palavra ou Acabar as tentativas

Para começar o jogo se imprime um underline correspondente ao lugar de cada letra.
ex.: _ _ _ _ _

O jogador que tenta adivinhar a palavra deve ir dizendo as letras que podem existir na palavra.
Cada letra que ele acerta é escrita no espaço correspondente.


Caso a letra não exista nessa palavra, imprime-se que a letra está incorreta, e reduz-se o
número de tentativas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char palavra[]="arroz";
    int tam = strlen(palavra);//para pegar o tamanho da palavra
    int acertos=0,erros=0,maxTent=4; //variaveis contadoras
    int cont=0;//variavel para controlar dentro do mesmo for a qtd de acertos/erros

    char tentativa[tam+1]; //necessario o +1 pois precisa armazenar 1 valor para o \0

    //inicializar com _
    for (int i = 0; i<tam;i++){
        tentativa[i]='_';
    }

while(acertos<tam && maxTent>=erros){ //deveria ser (acertos <= tam) mas como tem letra repetida, resolvi deixar assim para que desse certo
    printf("\nStatus: ");
    for (int i = 0; i < tam; i++)
    {
        printf("%c ",tentativa[i]);
    }

    char letra; 
    printf("\t\t-- DICAS: Possui 5 letras.\n\t\t\t\t\t  Combina com feijão.");
    printf("\n\nDigite uma letra: ");       
    scanf("%c", &letra);
    getchar(); //retirar o lixo 

    //identificar se ha letra digitada na palavra.
    for (int i = 0; i < tam; i++) //for para rodar o vetor da palavra
    {
        if (letra==palavra[i]) //condicional para saber quando acertar a letra
        {
            tentativa[i]=letra;
            acertos++;
            cont++;
        }
    }
    if (cont==0) //so entra aqui quando nao tiver tido correspondecia
    {
        erros++;
    }
    printf("--ERROS: %d de %d",erros,maxTent);
    cont=0; //resetar a variavel controladora para que no novo loop verifique se houve acerto ou nao. Nao havendo, soma um erro   
}   
    if (acertos<tam){ //normalmente aqui deveria estar com <= tbm!! So esta assim pq repete o r
        printf("\n\t== QUE PENA!! Você não conseguiu acertar a palavra dentro das tentativas necessarias!! ==\n");
    }else{
        printf("\n\t== PARABENS!!! Voce acertou!! ==\n");
    }
    
    return 0;
}
