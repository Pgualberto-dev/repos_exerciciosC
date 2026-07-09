#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;

    printf("Qual a dimensao da area da floresta: ");
    scanf("%d", &n);

    char floresta[n][n];
    char floresta_esp[n][n];
    bool mudou = true;

    printf("Preencher com . (solo vazio) | A (arvore saudavel) | F (arvore em chamas)\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Solo [%d]-[%d]: ", i, j);
            scanf(" %c", &floresta[i][j]);
        }
    }

    while (mudou) {
        mudou = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                floresta_esp[i][j] = floresta[i][j];

                if (floresta[i][j] == 'A') {
                    bool vizinhoQueimando = false;

                    if (i - 1 >= 0 && floresta[i - 1][j] == 'F') {
                        vizinhoQueimando = true;
                    }

                    if (i + 1 < n && floresta[i + 1][j] == 'F') {
                        vizinhoQueimando = true;
                    }

                    if (j - 1 >= 0 && floresta[i][j - 1] == 'F') {
                        vizinhoQueimando = true;
                    }

                    if (j + 1 < n && floresta[i][j + 1] == 'F') {
                        vizinhoQueimando = true;
                    }

                    if (vizinhoQueimando) {
                        floresta_esp[i][j] = 'F';
                        mudou = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                floresta[i][j] = floresta_esp[i][j];
            }
        }
    }

    printf("\nEstado final da floresta:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", floresta[i][j]);
        }
        printf("\n");
    }

    return 0;
}