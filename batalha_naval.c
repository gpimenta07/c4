#include <stdio.h>

#define SIZE 10

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar navios no tabuleiro
// Neste exemplo, navios fixos para simplificar
void posicionarNavios(int tabuleiro[SIZE][SIZE]) {
    // Navio horizontal tamanho 3 (linha 1, col 1 a 3)
    for (int c = 1; c <= 3; c++) tabuleiro[1][c] = 3;
    
    // Navio vertical tamanho 3 (coluna 5, linha 4 a 6)
    for (int l = 4; l <= 6; l++) tabuleiro[l][5] = 3;

    // Navio diagonal descendente (de cima esquerda para baixo direita), tamanho 3 (linha 7 a 9, col 7 a 9)
    for (int i = 0; i < 3; i++) tabuleiro[7 + i][7 + i] = 3;

    // Navio diagonal ascendente (de baixo esquerda para cima direita), tamanho 3 (linha 8 a 6, col 1 a 3)
    for (int i = 0; i < 3; i++) tabuleiro[8 - i][1 + i] = 3;
}

// Função para criar matriz de habilidade cone 5x5
void criarCone(int cone[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Condição para formar um cone "apontando para baixo"
            if (i >= j && i >= 4 - j) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade cruz 5x5
void criarCruz(int cruz[5][5]) {
    int centro = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade octaedro 5x5 (losango)
void criarOctaedro(int octaedro[5][5]) {
    int centro = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int dist = abs(i - centro) + abs(j - centro);
            if (dist <= 2) { // forma losango
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Função para sobrepor a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[SIZE][SIZE], int habilidade[5][5], int origemLinha, int origemColuna) {
    int tamanho = 5;
    int meio = tamanho / 2;

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int linhaTab = origemLinha - meio + i;
            int colTab = origemColuna - meio + j;

            // Verificar se está dentro dos limites do tabuleiro
            if (linhaTab >= 0 && linhaTab < SIZE && colTab >= 0 && colTab < SIZE) {
                // Se a habilidade afetar a posição e não for navio (3)
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colTab] == 0) {
                    tabuleiro[linhaTab][colTab] = 5;  // Marca área afetada
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[SIZE][SIZE]) {
    printf("Tabuleiro (0=agua, 3=navio, 5=habilidade):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[SIZE][SIZE];
    int cone[5][5], cruz[5][5], octaedro[5][5];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios (4 navios, sendo 2 diagonais)
    posicionarNavios(tabuleiro);

    // Cria as matrizes das habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Define pontos de origem para as habilidades no tabuleiro
    int origemConeLinha = 2, origemConeColuna = 2;
    int origemCruzLinha = 7, origemCruzColuna = 3;
    int origemOctaedroLinha = 5, origemOctaedroColuna = 7;

    // Aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna);

    // Exibe o tabuleiro com navios e áreas de habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}
