#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>  

#define WIDTH 100 
#define HEIGHT 100 
#define RGB 3

int main(){ 

    int imagem [WIDTH] [HEIGHT] [RGB];  
    float cinza = 0.0;

    for(int i = 0; i<WIDTH; i++){
        for(int j = 0; j<HEIGHT; j++){
            for(int k = 0; k<RGB; k++){
                imagem[i][j][k]=(i+j+k)%256;
            }
        }
    } 
    
        for(int i = 0; i<WIDTH; i++){
        for(int j = 0; j<HEIGHT; j++){
            cinza = 0.299 * imagem [i][j][0] + 0.587 * imagem [i][j][1] + 0.114 * imagem [i][j][2];
            int cinzaInt = (int) cinza;

            printf("O pixel cinza tera o valor de %d: \n", cinzaInt);
        }
    } 
    return 0;
}