#include <stdio.h>

#define TAM_TABULEIRO 10   // Tamanho fixo do tabuleiro
#define TAM_NAVIO 3        // Tamanho fixo de cada navio
#define AGUA 0             // Representa água no tabuleiro
#define NAVIO 3            // Representa parte de um navio no tabuleiro

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int i, j;

    // Inicializar o tabuleiro com água (0)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios
    // Navio 1 → horizontal
    int linha_h = 2;  
    int col_h   = 4;  

    // Navio 2 → vertical
    int linha_v = 5;  
    int col_v   = 7;  

    // Navio 3 → diagonal principal (↘)
    int linha_d1 = 0; 
    int col_d1   = 0; 

    // Navio 4 → diagonal secundária (↙)
    int linha_d2 = 0; 
    int col_d2   = 9; 

    // Validação de limites
    if (col_h + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 1;
    }
    if (linha_v + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 1;
    }
    if (linha_d1 + TAM_NAVIO > TAM_TABULEIRO || col_d1 + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio diagonal ↘ fora do tabuleiro!\n");
        return 1;
    }
    if (linha_d2 + TAM_NAVIO > TAM_TABULEIRO || col_d2 - TAM_NAVIO < -1) {
        printf("Erro: Navio diagonal ↙ fora do tabuleiro!\n");
        return 1;
    }

    // Validação de sobreposição
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_h][col_h + i] == NAVIO) {
            printf("Erro: Sobreposicao detectada no navio horizontal!\n");
            return 1;
        }
        if (tabuleiro[linha_v + i][col_v] == NAVIO) {
            printf("Erro: Sobreposicao detectada no navio vertical!\n");
            return 1;
        }
        if (tabuleiro[linha_d1 + i][col_d1 + i] == NAVIO) {
            printf("Erro: Sobreposicao detectada no navio diagonal ↘!\n");
            return 1;
        }
        if (tabuleiro[linha_d2 + i][col_d2 - i] == NAVIO) {
            printf("Erro: Sobreposicao detectada no navio diagonal ↙!\n");
            return 1;
        }
    }

    // Posicionar navio horizontal
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][col_h + i] = NAVIO;
    }

    // Posicionar navio vertical
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][col_v] = NAVIO;
    }

    // Posicionar navio diagonal ↘
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_d1 + i][col_d1 + i] = NAVIO;
    }

    // Posicionar navio diagonal ↙
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_d2 + i][col_d2 - i] = NAVIO;
    }

    // Exibir o tabuleiro
    printf("\n=== Tabuleiro Batalha Naval ===\n");
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}