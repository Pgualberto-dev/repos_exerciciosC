#include <stdio.h>
#include <stdlib.h>

int main (){

    int n [11]; 
    int aux, count = 1, auxCount = 0;   

    printf("Digite o numero %d - ", 1 ); 
    scanf ("%d", &n[0]);

    for (int i = 1; i < 11; i++) {  
        printf("Digite o numero %d - ", i + 1); 
        scanf ("%d", &n[i]); 
        aux = n[i];
        if (aux == n[i - 1]){
            count++;
        } else 
{   
            if (auxCount < count){
            auxCount = count; 
            }
            count = 1;
        }     
    } 
    if(auxCount > count){
    printf("Sua pontuação foi: %d ", auxCount); 
    
    } else {
        printf("Sua pontuação foi: %d ", count);
    }
    return 0;
}