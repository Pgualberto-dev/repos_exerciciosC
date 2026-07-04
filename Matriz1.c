#include <stdio.h>     
#include <stdlib.h>     
#include <locale.h>     

int main(void) {
    setlocale(LC_ALL,"");

    int tamM;  

    printf("Digite a dimesão da matriz: ");
    
    scanf(" %d", &tamM);

    char M [tamM] [tamM]; 

    int linha, coluna;  
    for (int i = 0; i < tamM; i++) {
        for (int j = 0; j < tamM; j++) {
            printf("Digite as direções e a posição do tesouro:  \n");
            
            scanf(" %c", &M[i][j]);
        }
    }
    for (int i = 0; i < tamM; i++) {
        for (int j = 0; j < tamM; j++) {
            printf(" %c ", M[i][j] );
        }
        printf("\n");  
    } 

    int visitado[tamM][tamM];
    for (int i = 0; i < tamM; i++) {
        for (int j = 0; j < tamM; j++) {
        visitado[i][j] = 0;
        }
    }

    printf("Digite a posicao inicial do jogador [Linha] [Coluna]; \n");
    scanf("%d %d", &linha, &coluna);

    if (linha < 0 || linha >= tamM || coluna < 0 || coluna >= tamM) {
        printf("Erro na leitura do jogador.\n");
    } else { 
        
        int passos = 0;

        while (linha >= 0 && linha < tamM && coluna >= 0 && coluna < tamM 
       && M[linha][coluna] != 'X' 
       && visitado[linha][coluna] != 1) {
        visitado[linha][coluna] = 1; 
        char direcao = M[linha][coluna];
        switch (direcao){
            case 'N':
                linha -=1;   
            break;           
            case 'S':
                linha +=1;   
            break;
            case 'L':
                coluna+=1;   
            break;
            case 'O':
                coluna-=1;   
            break;
        } 
        passos++;
    }

      if (linha < 0 || linha >= tamM || coluna < 0 || coluna >= tamM) {
    printf("Fora dos limites (Derrota)\n");
} else if (M[linha][coluna] == 'X') {
    printf("Vitória! Tesouro alcançado em %d passos\n", passos);
} else if (visitado[linha][coluna] == 1) {
    printf("Preso na Areia (Derrota)\n");
}

        return 0;
    }
}