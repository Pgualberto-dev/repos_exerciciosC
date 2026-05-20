#include <stdio.h>
#include <stdlib.h>

int main() {
    int a1, a2, a3;
    int s1, s2, s3;
    int soma_dist = 0;
    int diff, caminho1, caminho2;

    printf("Digite o codigo atual: ");
    scanf("%d %d %d", &a1, &a2, &a3);

    printf("Digite a senha: ");
    scanf("%d %d %d", &s1, &s2, &s3);

    // Roda 1
    diff = a1 - s1;
    if (diff < 0) diff = -diff;
    caminho1 = diff;
    caminho2 = 10 - diff;
    if (caminho1 < caminho2)
        soma_dist += caminho1;
    else
        soma_dist += caminho2;

    // Roda 2
    diff = a2 - s2;
    if (diff < 0) diff = -diff;
    caminho1 = diff;
    caminho2 = 10 - diff;
    if (caminho1 < caminho2)
        soma_dist += caminho1;
    else
        soma_dist += caminho2;

    // Roda 3
    diff = a3 - s3;
    if (diff < 0) diff = -diff;
    caminho1 = diff;
    caminho2 = 10 - diff;
    if (caminho1 < caminho2)
        soma_dist += caminho1;
    else
        soma_dist += caminho2;

    printf("menor quantidade de movimentos %d", soma_dist);
    return 0;
}