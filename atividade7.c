#include <stdio.h>
#include <stdlib.h>

int main (){

    int n, res = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n); 

    for (int i = 0; n >= i; i++){

        if(i % 2 == 0){
          res = i + n; 
        }
    } 

    printf("%d", res);
    
    

return 0;
}