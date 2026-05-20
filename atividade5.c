#include <stdio.h> 
#include <stdlib.h> 

int main (){

    int num, numReverso; 

    printf("Digite um numero de até 4 digitos: ");
    scanf("%d", &num); 

    int mil, cen, dez,uni; 

    mil = (num/1000) % 10; 
    cen = (num/100) % 10; 
    dez = (num/10) % 10;
    uni = num % 10;  

    numReverso = (uni * 1000) + (dez * 100) + (cen * 10) + mil;  

    if (numReverso % 2 == 0){
        numReverso = numReverso + 100;
    }else{
        numReverso = numReverso - 50;
    }

    printf ("%d", numReverso);

    return 0;
}