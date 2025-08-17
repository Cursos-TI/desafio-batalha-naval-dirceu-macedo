#include <stdio.h>
#include <stdlib.h> // para abs() usado no octaedro
#include <stdlib.h> // Necessário para usar abs()

#define TAM_TABULEIRO 10   // Tamanho fixo do tabuleiro
#define TAM_NAVIO 3        // Tamanho fixo de cada navio
#define AGUA 0             // Representa água no tabuleiro
#define NAVIO 3            // Representa parte de um navio no tabuleiro
#define HABILIDADE 5       // Representa área afetada por habilidade
#define TAM_HAB 5          // Tamanho fixo das matrizes de habilidade

// ---------------- Funções auxiliares ----------------

// Gera matriz em formato de cone
void gerarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Condição: cone apontando para baixo
            if (j >= (TAM_HAB/2 - i) && j <= (TAM_HAB/2 + i) && i <= TAM_HAB/2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Gera matriz em formato de cruz
void gerarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB/2 || j == TAM_HAB/2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Gera matriz em formato de octaedro (losango)
void gerarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Sobrepõe matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int hab[TAM_HAB][TAM_HAB], int origemX, int origemY) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (hab[i][j] == 1) {
                int x = origemX + (i - centro);
                int y = origemY + (j - centro);

                // Verifica se está dentro dos limites do tabuleiro
                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO) {
                    if (tabuleiro[x][y] == AGUA) // Não sobrescreve navio
                        tabuleiro[x][y] = HABILIDADE;
                }
            }
        }
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// ---------------- Programa principal ----------------
int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializar o tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionar alguns navios
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[2][4 + i] = NAVIO;        // horizontal
        tabuleiro[5 + i][7] = NAVIO;        // vertical
        tabuleiro[i][i] = NAVIO;            // diagonal ↘
        tabuleiro[i][9 - i] = NAVIO;        // diagonal ↙
    }

    // Criar matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 7, 2);
    aplicarHabilidade(tabuleiro, octaedro, 6, 6);

    // Exibir o tabuleiro final
    printf("\n=== Tabuleiro Batalha Naval com Habilidades ===\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
