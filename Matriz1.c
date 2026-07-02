#include <stdio.h>      // biblioteca padrão de entrada/saída (printf, scanf)
#include <stdlib.h>     // biblioteca padrão geral (não usada diretamente aqui, mas comum incluir)
#include <locale.h>     // necessária pra função setlocale()

int main(void) {
    // configura o programa pra usar o locale do sistema operacional (UTF-8),
    // em vez do locale padrão "C" (que só entende ASCII puro).
    // Isso é o que resolve o problema de acentuação (ção, ões, etc) aparecerem quebrados no terminal
    setlocale(LC_ALL,"");

    int tamM;  // vai guardar a dimensão M da matriz M x M

    printf("Digite a dimesão da matriz: ");
    // %d lê um inteiro. O & é obrigatório porque o scanf precisa do ENDEREÇO
    // de memória de tamM pra saber onde escrever o valor digitado
    scanf(" %d", &tamM);

    // matriz de char (não int!) porque cada posição guarda uma DIREÇÃO ('N','S','L','O'),
    // que é um caractere, não um número.
    // Isso é um VLA (Variable Length Array) - o tamanho [tamM][tamM] só é definido em tempo
    // de execução, depois que tamM foi lido do usuário
    char M [tamM] [tamM];

    int linha, coluna;  // vão guardar a posição inicial do jogador (lidas mais tarde)

    // ===== LOOP DE PREENCHIMENTO DA MATRIZ =====
    // i percorre as LINHAS, j percorre as COLUNAS
    // para cada posição [i][j], pede e lê uma direção
    for (int i = 0; i < tamM; i++) {
        for (int j = 0; j < tamM; j++) {
            printf("Digite as direções: \n");
            // o espaço ANTES do %c é essencial: ele faz o scanf "pular" qualquer
            // espaço em branco ou \n que sobrou no buffer da leitura anterior.
            // Sem esse espaço, o scanf podia capturar o Enter do usuário
            // em vez do próximo caractere digitado de verdade
            scanf(" %c", &M[i][j]);
        }
    }

    // ===== LOOP DE IMPRESSÃO DA MATRIZ =====
    // só pra conferir visualmente se a matriz foi preenchida corretamente
    for (int i = 0; i < tamM; i++) {
        for (int j = 0; j < tamM; j++) {
            printf(" %c ", M[i][j] );
        }
        printf("\n");  // quebra linha só depois de imprimir todas as colunas daquela linha
    }

    // ===== LEITURA DA POSIÇÃO INICIAL DO JOGADOR =====
    // linha e coluna são duas variáveis SIMPLES (não uma matriz!) -
    // elas só guardam "onde" o jogador está dentro da matriz M
    printf("Digite a posicao inicial do jogador [Linha] [Coluna]; \n");
    scanf("%d %d", &linha, &coluna);

    // ===== VALIDAÇÃO 1: a posição inicial existe na matriz? =====
    // Antes de acessar M[linha][coluna], PRECISA garantir que linha e coluna
    // estão dentro do intervalo válido [0, tamM-1].
    // Usamos >= (não >) porque o último índice válido é sempre tamM-1, não tamM
    // (regra de ouro contra erro de "off-by-one")
    if (linha < 0 || linha >= tamM || coluna < 0 || coluna >= tamM) {
        printf("Erro na leitura do jogador.\n");
    } else {
        // aqui dentro já é seguro acessar M[linha][coluna], porque validamos acima

        // guarda a direção que estava na posição inicial do jogador
        char direcao = M[linha][coluna];

        // ===== MAPEAMENTO DIREÇÃO -> MOVIMENTO =====
        // switch compara "direcao" (um único char) com cada valor possível.
        // N/S mexem na LINHA (sobe/desce), L/O mexem na COLUNA (direita/esquerda)
        switch (direcao){
            case 'N':
                linha -=1;   // Norte: sobe uma linha
            break;           // break impede o "fall-through" pro próximo case
            case 'S':
                linha +=1;   // Sul: desce uma linha
            break;
            case 'L':
                coluna+=1;   // Leste: anda uma coluna pra direita
            break;
            case 'O':
                coluna-=1;   // Oeste: anda uma coluna pra esquerda
            break;
        }

        // ===== VALIDAÇÃO 2: depois do movimento, ainda tá dentro da matriz? =====
        // mesma lógica da validação 1, mas agora aplicada à posição NOVA
        // (depois que linha/coluna já foram alteradas pelo switch)
        if (linha < 0 || linha >= tamM || coluna < 0 || coluna >= tamM) {
            printf("Fora dos limites do MAPA\n");
        } else {
            // só chega aqui se a posição nova é válida - então é seguro
            // acessar M[linha][coluna] de novo, pra saber a direção de lá
            char novaDirecao = M[linha][coluna];
            printf("Nova posição: (%d, %d) - Direção lá: %c\n", linha, coluna, novaDirecao);
        }

        return 0;
    }
}