#include <stdio.h>

int Verificador(char mat[3][3], int h) { //funcao para verificar as condições de quando determinado jogador vence!!
    for(int l = 0; l < 3; l++) {
        if((mat[l][0] == 'X') &&  (mat[l][1] == 'X') && (mat[l][2] == 'X')) {
            printf("\n\t== Jogador1 venceu!==\n");
            for(int l = 0; l< 3; l++) {
                for(int c = 0; c < 3; c++) {
                    printf(" %c ", mat[l][c]);
                }
                printf("\n");
            }
            return 10;
        }else if ((mat[l][0] == 'O') &&  (mat[l][1] == 'O') && (mat[l][2] == 'O')) {
            printf("\n\t== Jogador2 venceu! ==\n");
            for(int l = 0; l < 3; l++) {
                for(int c = 0; c < 3; c++) {
                    printf(" %c ", mat[l][c]);
                }
                printf("\n");
            }
            return 10;
        }
    }
    for(int c = 0; c < 3; c++) {
        if((mat[0][c] == 'O') &&  (mat[1][c] == 'O') && (mat[2][c] == 'O')) {
            printf("\n\t== Jogador2 venceu! ==\n");
            for(int i = 0; i < 3; i++) {//printar as posições
                for(int j = 0; j < 3; j++) {
                    printf(" %c ", mat[i][j]);
                }
                printf("\n");
            }
            return 10;
        }else if((mat[0][c] == 'X') &&  (mat[1][c] == 'X') && (mat[2][c] == 'X')) {
            printf("\n\t== Jogador1 venceu!==\n");
            for(int i = 0; i < 3; i++) {//printar as posições
                for(int j = 0; j < 3; j++) {
                    printf(" %c ", mat[i][j]);
                }
                printf("\n");
            }
            return 10;
        }
    }

    if((mat[0][0] == 'O') &&  (mat[1][1] == 'O') && (mat[2][2] == 'O')) {
        printf("\n\t== Jogador2 venceu! ==\n");
        for(int i = 0; i < 3; i++) {//printar as posições
            for(int j = 0; j < 3; j++) {
                printf(" %c ", mat[i][j]);
            }
            printf("\n");
        }
        return 10;
    }else if((mat[0][0] == 'X') &&  (mat[1][1] == 'X') && (mat[2][2] == 'X')) {
        printf("\n\t== Jogador1 venceu!==\n");
        for(int i = 0; i < 3; i++) {//printar as posições
            for(int j = 0; j < 3; j++) {
                printf(" %c ", mat[i][j]);
            }
            printf("\n");
        }
        return 10;
    }
    if((mat[0][2] == 'O') &&  (mat[1][1] == 'O') && (mat[2][0] == 'O')) {
        printf("\n\t== Jogador2 venceu! ==\n");
        for(int i = 0; i < 3; i++) {//printar as posições
            for(int j = 0; j < 3; j++) {
                printf(" %c ", mat[i][j]);
            }
            printf("\n");
        }
        return 10;
    }else if((mat[0][2] == 'X') &&  (mat[1][1] == 'X') && (mat[2][0] == 'X')) {
        printf("\n\t== Jogador1 venceu!==\n");
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                printf(" %c ", mat[i][j]);
            }
            printf("\n");
        }
        return 10;
    }
    for(int i = 0; i < 3; i++) { //printar as posições
        for(int j = 0; j < 3; j++) {
            printf(" %c ", mat[i][j]);
        }
        printf("\n");
    }
    return h;
}

int main () {

    char tabJogo[3][3];
    int final = 0;
    int l, c;
    int m=0;
    int p=0;

    for(int l = 0; l < 3; l++) { //criar o tabuleiro
        for(int c = 0; c < 3; c++) {
            tabJogo[l][c] = '#' ;
        }
    }

    //printar o tab
    for(int l = 0; l < 3; l++) { //criar o tabuleiro
        for(int c = 0; c < 3; c++) {
            printf(" %c ",tabJogo[l][c]);
        }
        printf("\n");
    }

    while(final < 5) {
        while(m < 1) {
            printf("Jogador2(O), Informe sua jogada: ");
            scanf("%d %d", &l, &c);
            if(tabJogo[l][c] ==  '#') {
                tabJogo[l][c] = 'O';
                break;
            }else {
                printf("Posição inválida, Jogue novamente! \n");
            }
        }

        final = Verificador(tabJogo, p);

        if(final < 5 && final!= 4) {
            while(m < 1) {
                printf("Jogador1(X), Informe sua jogada: ");
                scanf("%d %d", &l, &c);
                if(tabJogo[l][c] ==  '#') {
                    tabJogo[l][c] = 'X';
                    break;
                }else {
                    printf("Posicão inválida!, Jogue novamente! \n");
                }
            }
        }
        if(final != 10) {//saber quando chegar ao fim
            final = Verificador(tabJogo, final);
        }
        final++;
    }
    if(final == 5) {//empate
        printf("\n\t== Bom jogo!! Deu empate! ==\n");
    }
    return 0;
}
