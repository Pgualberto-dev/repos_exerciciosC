#include <stdio.h> 
#include <stdlib.h>

int main() { 
    float valor;
    int num, num_sorteado; 
    
    printf("Valor da aposta: "); 
    scanf("%f", &valor); // 'valor' agora é float
    printf("Digite o numero apostado: "); 
    scanf("%d", &num); 
    printf("Digite o valor sorteado: ");
    scanf("%d", &num_sorteado);
    
    // Pegando apenas os dois últimos dígitos (dezena e unidade) 
    // Exemplo: 14302 % 100 = 02
    int dez_apost = num % 100;
    int dez_sorte = num_sorteado % 100;
    
    // -----------------------------------------
    // LÓGICA DO GRUPO (Sua matemática estava ótima!)
    // -----------------------------------------
    int grupo_apost;
    if (dez_apost == 0) {
        grupo_apost = 25;
    } else {
        grupo_apost = dez_apost / 4;
        if (dez_apost % 4 != 0) {
            grupo_apost++;
        }
    }
    
    int grupo_sorte;
    if (dez_sorte == 0) {
        grupo_sorte = 25;
    } else {
        grupo_sorte = dez_sorte / 4;
        if (dez_sorte % 4 != 0) {
            grupo_sorte++;
        }
    }
    // -----------------------------------------
    // VERIFICAÇÃO DE PRÊMIOS (Do maior para o menor)
    // -----------------------------------------
    if (num % 10000 == num_sorteado % 10000) {
        // Últimos 4 dígitos iguais
        printf("Premio: %.2f\n", valor * 3000);
    } 
    else if (num % 1000 == num_sorteado % 1000) {
        // Últimos 3 dígitos iguais
        printf("Premio: %.2f\n", valor * 500);
    } 
    else if (num % 100 == num_sorteado % 100) {
        // Últimos 2 dígitos iguais
        printf("Premio: %.2f\n", valor * 50);
    } 
    else if (grupo_apost == grupo_sorte) {
        // Grupos iguais (Corrigido para * 16)
        printf("Premio: %.2f\n", valor * 16);
    } 
    else {
        // Nenhum critério atendido
        printf("Premio: 0.00\n");
    }
    
    return 0;
}