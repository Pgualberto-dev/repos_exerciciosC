#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define M 7 
#define N 19 
#define TAM 18

int main (){ 
    int pos_final = 0;

    char grade[M][N] = {
    "ABLNHEHLLTBQJFRGQH",
    "KJULOCALIZARARVMNT",
    "FEOGEQHTLOIDFMBAOE",
    "RWBNUSGEVIXOIOXGUS",
    "BRDARGTENTATIVAYJT",
    "EARHSOWESLFVCDPZJE",
    "WECSWATLXBMTLCDPNI"
    }; 

    char palavra[TAM];
    /* printf("Digite os caracteres da grade: \n");

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){ 
            printf("posição (%d) (%d) ", i, j); 
            scanf(" %c",&grade[i][j]); 
        }
    } */

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){ 
            printf("%c ",grade[i][j]);
        } 
        printf("\n");
    }   

    printf("Digite a plavra a ser testada: "); 
    fgets(palavra, TAM,stdin); 
    while (palavra[pos_final]!='\0'){
        pos_final++;
    }
    pos_final-=1; 
    palavra[pos_final] = '\0'; 
    printf("A palavra digitada foi: %s\n", palavra);
    int tamPalavra = pos_final;
bool encontrou = false;

/* busca horizontal */
for (int i = 0; i < M; i++) {
    for (int j = 0; j <= (N - 1) - tamPalavra; j++) {
        bool achou = true;

        for (int k = 0; k < tamPalavra; k++) {
            if (grade[i][j + k] != palavra[k]) {
                achou = false;
                break;
            }
        }

        if (achou) {
            encontrou = true;
        }
    }
}

/* busca vertical */
for (int j = 0; j < N - 1; j++) {
    for (int i = 0; i <= M - tamPalavra; i++) {
        bool achou = true;

        for (int k = 0; k < tamPalavra; k++) {
            if (grade[i + k][j] != palavra[k]) {
                achou = false;
                break;
            }
        }

        if (achou) {
            encontrou = true;
        }
    }
}

/* pontuação */
if (encontrou) {
    printf("%d pontos\n", tamPalavra);
} else {
    printf("-5 pontos\n");
}
return 0;
}









