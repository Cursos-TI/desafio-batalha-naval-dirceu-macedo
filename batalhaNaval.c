#include <stdio.h>

#define TAM_TABULEIRO 10   // Tamanho fixo do tabuleiro
#define TAM_NAVIO 3        // Tamanho fixo de cada navio
#define AGUA 0             // Representa água no tabuleiro
#define NAVIO 3            // Representa parte de um navio no tabuleiro

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int i, j;

    // 1️⃣ Inicializar o tabuleiro com água (0)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2️⃣ Coordenadas iniciais dos navios
    // Navio 1 → horizontal
    int linha_h = 2;  // linha inicial
    int col_h   = 4;  // coluna inicial

    // Navio 2 → vertical
    int linha_v = 5;  // linha inicial
    int col_v   = 7;  // coluna inicial

    // 3️⃣ Validação de limites
    if (col_h + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 1;
    }
    if (linha_v + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 1;
    }

    // 4️⃣ Validação de sobreposição
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_h][col_h + i] == NAVIO) {
            printf("Erro: Sobreposicao detectada no navio horizontal!\n");
            return 1;
        }
        if (tabuleiro[linha_v + i][col_v] == NAVIO) {
            printf("Erro: Sobreposicao detectada no navio vertical!\n");
            return 1;
        }
    }

    // 5️⃣ Posicionar navio horizontal
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][col_h + i] = NAVIO;
    }

    // 6️⃣ Posicionar navio vertical
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][col_v] = NAVIO;
    }

    // 7️⃣ Exibir o tabuleiro
    printf("\n=== Tabuleiro Batalha Naval ===\n");
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}