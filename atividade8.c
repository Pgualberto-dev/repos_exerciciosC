#include <stdio.h> 
#include <stdlib.h> 

int main (){


    int num;
    long res_fatorial = 1; 

    printf("Digite o numero a ser fatorado: "); 
    scanf("%d", &num);

    for (int i = 1; num >= i; i++)
    {
        res_fatorial *= i;
    }
    
    printf("A fatorial de %d e %d", num, res_fatorial);

    return 0;
}