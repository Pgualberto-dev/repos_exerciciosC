#include <stdio.h> 
#include <stdlib.h> 

int main (){

    float peso1, peso2, cump1, cump2; 

    printf("Digite o peso das crianças: "); 
    scanf("%f %f", &peso1, &peso2); 
    
    printf("Digite os cumprimentos dos lados da gangorra: ");
    scanf("%f %f", &cump1, &cump2);

    float calc1, calc2; 

    calc1 = peso1 * cump1; 
    calc2 = peso2 * cump2;  

    if (calc1 == calc2){ 
        printf("Gangorra em equilibrio");
    } else if (calc1 > calc2) {
       printf("Gangorra pende para o lado 1");
    } else {
        printf("Gangorra pende para o lado 2");
    }
    return 0;
}