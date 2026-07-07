#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

#define TAM 50

int main (){ 

    char fraseA [TAM], fraseB [TAM];  
    int pos_finalA = 0, pos_finalB = 0; 
    bool encaixou = true;
    bool achou = false; 
    bool palavra_achou = true;

    //LEITURA E LIMPEZA DA FRASE A 
    // fgets pega a frase inteira (com espaços), depois o while acha o \0
    // e remove o \n que o Enter deixa no final
    printf("Digite a primeira frase: ");
    fgets(fraseA, TAM, stdin);  
    while(fraseA[pos_finalA] != '\0'){
        pos_finalA++;
    }  
    pos_finalA-=1; 
    fraseA[pos_finalA] = '\0';

    printf("Digite a segunda frase: ");
    fgets(fraseB, TAM, stdin);  
    while(fraseB[pos_finalB] != '\0'){
        pos_finalB++;
    }  
    pos_finalB-=1; 
    fraseB[pos_finalB] = '\0';  

    // Q 1: VERIFICA SE UMA FRASE ESTÁ CONTIDA NA OUTRA 
    // decide qual frase é maior (onde procura) e qual é menor (o que procura),
    // já que não dá pra comparar tamanhos diferentes sem saber quem é quem
    if (pos_finalA > pos_finalB){
        printf("A frase maior e\n");
        printf("%s \n", fraseA); 

        // busca de substring: i = cada posição possível de encaixe em fraseA,
        // j = percorre fraseB inteira comparando caractere a caractere.
        // encaixou vira false e dá break assim que um caractere não bate
        for (int i = 0; i <= pos_finalA - pos_finalB; i++){   
            encaixou = true;
            for (int j = 0; j < pos_finalB; j++){
              if (fraseA[i + j] != fraseB[j]){ 
                encaixou = false;
                break;
              }
            }
            // só aqui, depois do teste completo de uma posição i, decide se achou
            if (encaixou == true) {
                printf("Encontrado! A frase menor encaixa a partir da posição %d\n", i); 
                achou = true;
                break;
            }  
        } 
        // só dispara se NENHUM i ao longo de todo o for deu encaixe
        if (achou == false){
            printf("Não encontrado! A frase menor não encaixa na frase maior");
        }
        
    } else if(pos_finalA < pos_finalB){
        // mesma lógica de busca acima, só invertendo quem é maior/menor
        printf("A frase maior e\n");
        printf("%s \n", fraseB);

        for (int i = 0; i <= pos_finalB - pos_finalA; i++){ 
            encaixou = true;
            for (int j = 0; j < pos_finalA; j++){
              if (fraseB[i + j] != fraseA[j]){
                encaixou = false;
                break;
              }
            }
            if (encaixou == true) {
                printf("Encontrado! A frase menor encaixa a partir da posição %d\n", i); 
                achou = true;
                break;
            }  
        } 
        if (achou == false){
            printf("Não encontrado! A frase menor não encaixa na frase maior");
        }
    } else{
        // caso as duas frases tenham exatamente o mesmo tamanho
        printf("As frases: \n %s \n %s \n sao do mesmo tamanho!", fraseA, fraseB);
    } 

    // Q2: VERIFICA SE ALGUMA PALAVRA DE A APARECE EM B 
    // percorre fraseA caractere a caractere, "montando" uma palavra em
    // "palavra" até encontrar um espaço ou o fim da frase
    char palavra [TAM];
    int k = 0; 

    for (int i = 0; i <= pos_finalA; i++){
        if (fraseA[i] != ' ' && fraseA[i] != '\0') {
            palavra[k] = fraseA[i]; 
            k++;
        } else{
            // a palavra está completa: fecha com \0 e testa se ela
            // encaixa em algum ponto de fraseB (mesma lógica de busca da Q1,
            // só que agora com tamanho variável "k" a cada palavra extraída)
            palavra[k] = '\0'; 
            for(int p = 0; p <= pos_finalB - k; p++){
                palavra_achou = true;
                for (int j = 0; j < k; j++){
                   if(fraseB [p+j] != palavra[j]){
                    palavra_achou = false;
                    break;
                   } 
                }
                if (palavra_achou == true){
                    printf("A palavra %s foi encontrada na frase \n %s ", palavra, fraseB);
                    break;
                }
            }
            // reseta k pra começar a montar a próxima palavra do zero
            k = 0;
        } 
    }
    return 0;
}