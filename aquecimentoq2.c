#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

int main (){

    int l , c, isolado = 0 ;
    printf("Digite as dimensoes da matriz: L x C: "); 
    scanf("%d %d", &l, &c); 

    int matriz[l][c]; 

    printf("Digite os elementos da matriz com 0s e 1s: \n");
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            printf("Posição %d | %d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) { 
                if( matriz[i][j] == 1){
                    if ((i == 0 || matriz[i - 1][j] == 0) && (i == l - 1 || matriz[i + 1][j] == 0) && (j == 0 || matriz[i][j - 1] == 0) &&
                        (j == c - 1|| matriz[i][j + 1] == 0)) { 
                        isolado++;
                    }
                }
            }
        } 
        printf("Quantidade de asteroides isolados: %d ", isolado);
    return 0;
}