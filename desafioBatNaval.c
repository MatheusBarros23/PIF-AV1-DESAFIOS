#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

  srand(time(NULL)); //gerar em posicoes randomicas

  int tam = 10;
  int mapa1[tam][tam], mapa2[tam][tam];
  int barcos1 = 10, barcos2 = 10;

  for(int l = 0; l < tam; l++)
    {
      for(int c = 0; c < tam; c++)
        {
          mapa1[l][c] = 0;
          mapa2[l][c] = 0;
        }
    }
 
  for(int barco = 1; barco <= barcos1; )
    {
      int bl = rand()%tam;
      int bc = rand()%tam;

      if(mapa1[bl][bc] == 0)
      {
        mapa1[bl][bc] = 1;
        barco++;
      }
    }

  for(int barco = 1; barco <= barcos2; )
    {
      int bl = rand()%tam;
      int bc = rand()%tam;

      if(mapa2[bl][bc] == 0)
      {
        mapa2[bl][bc] = 2;
        barco++;
      }
    }

  int jAtual = 1;
  do{
    for(int l = 0; l < tam; l++)
    {
      for(int c = 0; c < tam; c++)
        {
          printf("%d ", mapa1[l][c]);
        }
      printf("\n");
    }

  printf("\n\n");

  for(int l = 0; l < tam; l++)
    {
      for(int c = 0; c < tam; c++)
        {
          printf("%d ", mapa2[l][c]);
        }
      printf("\n");
    }
   
    int linha, coluna;
   
    printf("Player%d, digite a coordenada: ", jAtual);
    scanf("%d %d", &linha, &coluna);
    getchar();

    if(jAtual == 1)
    {
      if(mapa2[linha][coluna] == 2)
      {
        mapa2[linha][coluna] = 0;
        barcos2--;

        printf("\nVoce acertou! Afundou o Barco!!\n");
      }
      jAtual = 2;
    }
    else if(jAtual == 2)
    {
      if(mapa1[linha][coluna] == 1)
      {
        mapa1[linha][coluna] = 0;
        barcos1--;

        printf("\nVoce acertou! Afundou o Barco!!\n");
      }
      jAtual = 1;
    }
    printf("\n\n"); 
  }while(1);
  return 0;
}