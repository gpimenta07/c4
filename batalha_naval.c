#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se as posições do navio são válidas (dentro do tabuleiro e sem sobreposição)
int validarPosicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linhaInicial + i * direcaoLinha;
        int coluna = colunaInicial + i * direcaoColuna;
        
        // Verifica se está dentro dos limites do tabuleiro
        if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
            return 0; // posição inválida
        }
        // Verifica se a posição está livre (não está ocupada por outro navio)
        if (tabuleiro[linha][coluna] == 3) {
            return 0; // sobreposição
        }
    }
    return 1; // posição válida
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linhaInicial + i * direcaoLinha;
        int coluna = colunaInicial + i * direcaoColuna;
        tabuleiro[linha][coluna] = 3; // Marca a posição como navio
    }
}

// Função para imprimir o tabuleiro no console
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas e direções dos navios
    // Navios horizontais/verticais: direcaoLinha ou direcaoColuna = 1 ou 0
    // Navios diagonais: direcaoLinha e direcaoColuna = 1 ou -1 (para diagonal crescente ou decrescente)

    // Navio 1: Horizontal (linha 1, coluna 2) para a direita
    if (validarPosicao(tabuleiro, 1, 2, 0, 1)) {
        posicionarNavio(tabuleiro, 1, 2, 0, 1);
    } else {
        printf("Posição inválida para navio 1\n");
    }

    // Navio 2: Vertical (linha 4, coluna 5) para baixo
    if (validarPosicao(tabuleiro, 4, 5, 1, 0)) {
        posicionarNavio(tabuleiro, 4, 5, 1, 0);
    } else {
        printf("Posição inválida para navio 2\n");
    }

    // Navio 3: Diagonal crescente (linha 6, coluna 6), diagonal para baixo e direita
    if (validarPosicao(tabuleiro, 6, 6, 1, 1)) {
        posicionarNavio(tabuleiro, 6, 6, 1, 1);
    } else {
        printf("Posição inválida para navio 3\n");
    }

    // Navio 4: Diagonal decrescente (linha 8, coluna 2), diagonal para cima e direita
    if (validarPosicao(tabuleiro, 8, 2, -1, 1)) {
        posicionarNavio(tabuleiro, 8, 2, -1, 1);
    } else {
        printf("Posição inválida para navio 4\n");
    }

    // Exibe o tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}
