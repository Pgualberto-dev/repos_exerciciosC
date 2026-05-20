#include <stdio.h>
#include <stdlib.h> 

int main (){

    float vMoto, vEntrada, sDevedor,juros, parcelas; 

    printf ("Digite o valor total da moto: \n"); 
    scanf("%f", &vMoto);
    printf ("Digite o valor da entrada: ");
    scanf("%f", &vEntrada);  

    sDevedor = vMoto - vEntrada; 

    if(vEntrada < vMoto * 20/100){ 

        juros = sDevedor * 0.02 * 36;
        
        sDevedor = sDevedor + juros; 
        parcelas = sDevedor/36; 

        printf("Com a entrada de %.2f, o total a pagar sera %.2f em 36 parcelas de %.2f.", vEntrada, sDevedor, parcelas);

    }else if (vEntrada >= vMoto * 20/100 && vEntrada <= vMoto * 50/100){

        juros = sDevedor * 0.01 * 36;
        
        sDevedor = sDevedor + juros; 
        parcelas = sDevedor/36; 

        printf("Com a entrada de %.2f, o total a pagar sera %.2f em 36 parcelas de %.2f.", vEntrada, sDevedor, parcelas);
    } else { 

        juros = sDevedor * 0.005 * 36;
        
        sDevedor = sDevedor + juros; 
        parcelas = sDevedor/36; 

        printf("Com a entrada de %.2f, o total a pagar sera %.2f em 36 parcelas de %.2f.", vEntrada, sDevedor, parcelas);

    }
    return 0;
}