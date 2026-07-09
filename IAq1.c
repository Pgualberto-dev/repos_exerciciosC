#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define TAM_S 10

int main() { 

    char senha[TAM_S];  
    int final_senha = 0; 
    bool senha_valida = true; 
    bool temMaiuscula = false;
    bool temDigito = false;

    printf("Digite a senha a ser validada: "); 
    fgets(senha,TAM_S, stdin); 

    while (senha[final_senha] != '\0'){
        final_senha++;
    } 
    final_senha-=1; 
    senha[final_senha] = '\0'; 

    char c; 

    if (final_senha >= 6){
        for (int i = 0; i < final_senha; i++){
        c = senha[i]; 
        if (c >= 'A' && c <= 'Z') {  
            temMaiuscula = true;
        } 
        if (c >= '0' && c <= '9') {  
            temDigito = true;
        } 
        }
        if (!temDigito || !temMaiuscula){
            printf("Senha [%s] Invalida", senha);
        }else{
            printf("A senha [%s] é valida", senha);
        }
    }else{ 
        printf("Senha com menos de 6 digitos senha invalida");
    }
    return 0;
}