#include <stdio.h>
#include <stdlib.h>

float media(float temp[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++)
        soma += temp[i];
    return soma / n;
}

float media_descarte(float temp[], int n) {
    float med = media(temp, n);

    int idx_descarte = 0;
    float maior_diff = 0;

    for (int i = 0; i < n; i++) {
        float diff = temp[i] - med;
        if (diff < 0) diff = -diff;

        if (diff > maior_diff) {
            maior_diff = diff;
            idx_descarte = i;
        }
    }

    float soma = 0;
    for (int i = 0; i < n; i++) {
        if (i != idx_descarte)
            soma += temp[i];
    }

    return soma / (n - 1);
} 

float temp_recorrente (float recorre[], int n){
    int contagem = 0, max_contagem = 0; 
    float temp_rec = 0.0;
    for (int i = 0; i < n; i++){
        contagem = 0;
        for (int j = 0; j < n; j++){ 

            if (recorre [i] == recorre [j]) { 
                contagem++;
            }
        }
        if (contagem > max_contagem) {
            max_contagem = contagem ;
            temp_rec = recorre[i];
        } 
    }
    return temp_rec;
}

#define NUM_MED 3  
#define NUM_SEN 10

int main(){ 

float leituras [NUM_MED];  
float soma = 0.0; 
float recorrente [30];
float temp_recorre;

    for (int i = 0; i < NUM_SEN; i++){
    

    printf("Temperatura registrada: \n"); 
    scanf("%f %f %f", &leituras[0], &leituras[1], &leituras[2]); 

    recorrente[i * NUM_MED + 0] = leituras[0];
    recorrente[i * NUM_MED + 1] = leituras[1];
    recorrente[i * NUM_MED + 2] = leituras[2];

    float med = media(leituras, NUM_MED);  
    soma += med;
    
    printf("Media do sensor %d: %.2f\n", i+1, med); 

    float med_descarte = media_descarte(leituras, NUM_MED);
    printf("Media do sensor %d com descarte do valor distante: %.2f\n", i+1, med_descarte);
    
    } 
    printf("Media geral: %.2f\n", soma / NUM_SEN);
    temp_recorre = temp_recorrente(recorrente, NUM_MED * NUM_SEN);
    printf("Temperatura mais recorrente: %.2f\n", temp_recorre);
    return 0;
}