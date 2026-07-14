#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#define TAM 100

int main (){ 

    char som_captado[TAM], som_filtrado [TAM]; 
    int pos_final=0;

    printf("Informe o som captado na caverna: "); 
    fgets(som_captado, TAM, stdin); 

    while (som_captado[pos_final]!='\0'){
        pos_final++;
    } 
    pos_final-=1; 
    som_captado[pos_final] = '\0'; 
    char letra_atual;
    int i = 0;
    int j = 0;
    
    while (som_captado[i]!= '\0'){
        if(som_captado[i] != som_captado[i+1]){
            letra_atual = som_captado[i];
            printf("Letra atual é %c", som_captado[i]); 
            som_filtrado[j] = letra_atual;
            j++;
        }  
        i++;
    } 
    printf("Esse foi o som captado na caverna (%s) ", som_captado); 
    printf("Esse é o som sem o eco (%s) ", som_filtrado);
    return 0;
}