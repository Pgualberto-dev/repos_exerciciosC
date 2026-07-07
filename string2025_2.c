#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

#define TAM 50

//funçao de teste pertencente
bool pertence(char c, char alfabeto[], int tamAlfabeto){
    for(int i = 0; i < tamAlfabeto; i++){
        if(alfabeto[i] == c){
            return true;// achou! já pode retornar, sem precisar continuar o loop
        }
    }
    return false;// se o loop terminar sem achar, não pertence
}

int main(){

    char alfabeto[TAM], intercept[TAM]; 
    int pos_finalA = 0,pos_finalB = 0; 
    bool char_teste = true; 
    

    printf("Digite o caracters do alfabeto: ");
    fgets(alfabeto, TAM, stdin); 

    while (alfabeto[pos_finalA] != '\0'){
        pos_finalA++;
    } 
    pos_finalA-=1; 
    alfabeto[pos_finalA] = '\0';
    
    printf("Digite a mensagem interceptada: ");
    fgets(intercept, TAM, stdin);
    while (intercept[pos_finalB] != '\0'){
        pos_finalB++;
    } 
    pos_finalB-=1; 
    intercept[pos_finalB] = '\0';

    for (int i = 0; i<pos_finalB; i++){
        if (pertence(intercept[i], alfabeto, pos_finalA) == false){
            char_teste = false; 
            break;
        }
    } 
    if (char_teste == true) {
        printf("A mensagem poderia ter sido escrita por alienígenas\n");
    } else {
        printf("A mensagem não poderia ter sido escrita por alienígenas\n");
    }
return 0;
}