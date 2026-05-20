#include <stdio.h>
#include <stdlib.h>

int main (){

    int p, q, r;
    printf("Digite as posições das portinhas Q, P e R (0 ou 1): ");
    scanf("%d %d %d", &q, &p, &r); 

    if (q == 0){
        if (p == 0){
            printf("Saida na porta A");
        }else {
            printf("Saida na porta B");
        }
    } else {
        if (r == 0){
            printf("Saida na porta C");
        } else{
            printf("Saida na porta D");
        }
        
    }
    return 0;
}