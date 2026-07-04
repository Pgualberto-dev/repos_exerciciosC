#include <stdio.h> 
#include <stdlib.h>

int main (){

    int n; 

    printf("Defina o tamanho da matriz: "); 
    scanf("%d", &n);

    int matriz [n][n]; 
    int aux = 0;

    for (int i = 0; i < n; i++){
       for (int j=0; j<n; j++){
        printf ("Preencha a matriz: ");
        scanf("%d", &matriz[i][j]);
        
       }
       
    } 
     for (int i = 0; i < n; i++){ 
       for (int j = 0; j<n; j++){
        printf("%d ", matriz[i][j]);  
       } 
       printf("\n");
    } 

     for (int i = 0; i < n; i++){  
        aux = 0;
       for (int j=0; j<n; j++){
        aux += matriz [i] [j]; 
       }
        printf("Soma da linha %d é %d  /n", i + 1, aux);
    }
    return 0;
}
