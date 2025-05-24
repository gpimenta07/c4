#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define MAR 0
#define NAVIO 3

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o navio pode ser posicionado sem ultrapassar os limites
int podePosicionar(int linha, int coluna, int orientacao, int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 1 ? i : 0);
        int c = coluna + (orientacao == 0 ? i : 0);

        // Verifica se está dentro dos limites e se já não existe um navio
        if (l >= TAM_TABULEIRO || c >= TAM_TABULEIRO || tabuleiro[l][c] == NAVIO) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int linha, int coluna, int orientacao, int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 1 ? i : 0);   // 1 = vertical
        int c = coluna + (orientacao == 0 ? i : 0);  // 0 = horizontal

        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = MAR;
        }
    }

    // Coordenadas dos navios (definidas no código)
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 7;

    // Verifica se é possível posicionar os navios
    if (podePosicionar(linhaHorizontal, colunaHorizontal, 0, tabuleiro)) {
        posicionarNavio(linhaHorizontal, colunaHorizontal, 0, tabuleiro);
    } else {
        printf("Erro: não foi possível posicionar o navio horizontal.\n");
    }

    if (podePosicionar(linhaVertical, colunaVertical, 1, tabuleiro)) {
        posicionarNavio(linhaVertical, colunaVertical, 1, tabuleiro);
    } else {
        printf("Erro: não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
