#include <stdio.h> 
#include <stdlib.H> 

int main (){

    int n; 

    printf("Defina o tamanho da matriz: "); 
    scanf("%d", &n);

    int matriz [n][n]; 
    int soma1 = 0, soma2 = 0;

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
    //Otimização
    for (int i = 0; i < n; i++) {
    soma1 += matriz[i][i];           // diagonal principal: linha i, coluna i
    soma2 += matriz[i][n - 1 - i];   // diagonal secundária: linha i, coluna (n-1-i)
}   
     printf("Soma da diagonal principal = %d \n", soma1);
    

     //Jeito que eu fiz

  /*  printf("Diagonal principal \n");
    for (int i = 0; i < n; i++){
         for (int j = 0; j < n; j++){ 
            if (i == j){  
                printf("%d ",matriz[i][j]);
                soma1 += matriz[i][j]; 
            }   
    }   
}
        printf("Soma da diagonal principal = %d \n", soma1);

        printf("Diagonal secundaria \n");
      for (int i = 0; i < n; i++){
         for (int j = 0; j < n; j++){ 
            if (i + j == n - 1){  
                
                printf("%d ",matriz[i] [j]);
                soma2 += matriz[i][j]; 
            }   
    }   
} */



        printf("Soma da diagonal secundaria = %d \n", soma2);
    
    return 0;
}