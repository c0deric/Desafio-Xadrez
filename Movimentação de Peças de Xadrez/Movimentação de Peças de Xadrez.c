#include <stdio.h>

// Funcao recursiva para movimentar a Torre para a direita
void moverTorre(int casas) {
    if (casas <= 0) return;  // Caso base: nenhuma casa para mover
    printf("Direita\n");
    moverTorre(casas - 1);   // Chamada recursiva para proxima casa
}

// Funcao recursiva para movimentar a Rainha para a esquerda
void moverRainha(int casas) {
    if (casas <= 0) return;  // Caso base
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Funcao recursiva para movimentar o Bispo usando loops aninhados para vertical e horizontal
// Aqui, vertical e o loop externo e horizontal e o interno
void moverBispoRecursivo(int casasVerticais, int casasHorizontais) {
    if (casasVerticais <= 0 || casasHorizontais <= 0) return; // Caso base
    
    // Loop externo: movimento vertical (para cima)
    for (int v = 0; v < casasVerticais; v++) {
        // Loop interno: movimento horizontal (para direita)
        for (int h = 0; h < casasHorizontais; h++) {
            printf("Cima\n");
            printf("Direita\n");
        }
    }
    
    // Recursao diminuindo as casas para movimentar em passos menores
    moverBispoRecursivo(casasVerticais - 1, casasHorizontais - 1);
}

// Funcao para simular movimento do Cavalo com loops aninhados, usando continue e break
// Cavalo move 2 casas para cima + 1 para direita, repetido ate o numero maximo de movimentos
void moverCavalo(int movimentos) {
    int movimentosFeitos = 0;

    for (int i = 0; i < movimentos * 3; i++) { // Complexidade no loop
        for (int j = 0; j < 2; j++) {          // 2 iteracoes para cima

            if (movimentosFeitos >= movimentos) break;

            if ((i + j) % 2 == 0) {
                continue;
            }

            // Imprime duas casas para cima
            printf("Cima\n");

            // Imprime uma casa para direita no segundo passo da iteracao j==1
            if (j == 1) {
                printf("Direita\n");
                movimentosFeitos++;
            }
        }

        if (movimentosFeitos >= movimentos) break;
    }
}

int main() {
    // Definindo a quantidade de movimentos para cada peca
    const int casasTorre = 5;
    const int casasBispoVerticais = 5;
    const int casasBispoHorizontais = 5;
    const int casasRainha = 8;
    const int movimentosCavalo = 3;

    printf("Movimento da Torre (recursivo):\n");
    moverTorre(casasTorre);
    printf("\n");

    printf("Movimento do Bispo (loops aninhados + recursao):\n");
    moverBispoRecursivo(casasBispoVerticais, casasBispoHorizontais);
    printf("\n");

    printf("Movimento da Rainha (recursivo):\n");
    moverRainha(casasRainha);
    printf("\n");

    printf("Movimento do Cavalo (loops aninhados complexos):\n");
    moverCavalo(movimentosCavalo);
    printf("\n");

    return 0;
}
