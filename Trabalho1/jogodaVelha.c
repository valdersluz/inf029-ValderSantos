#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TAM 3

void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("   1   2   3\n");
    for (int i = 0; i < TAM; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAM - 1) printf("|");
        }
        printf("\n");
        if (i < TAM - 1) printf("  ---+---+---\n");
    }
}

int verificarGanhador(char tabuleiro[TAM][TAM], char jogador) {
    for (int i = 0; i < TAM; i++) {
        // Linhas e colunas
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return 1;
        }
    }
    // Diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return 1;
    }
    return 0;
}

int main() {

    char tabuleiro[TAM][TAM] = {
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' }
    };

    int jogador = 1;
    int jogadas = 0;
    char entrada[3];

    while (1) {
        imprimirTabuleiro(tabuleiro);
        printf("Jogador %d (%c), informe sua jogada (ex: B3): ", jogador, jogador == 1 ? 'X' : 'O');
        scanf("%2s", entrada);

        // Validação de entrada
        if (strlen(entrada) != 2 || !isalpha(entrada[0]) || !isdigit(entrada[1])) {
            printf("Entrada inválida! Use o formato A1, B2, etc.\n");
            continue;
        }

        int linha = toupper(entrada[0]) - 'A';
        int coluna = entrada[1] - '1';

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("Coordenada fora do tabuleiro.\n");
            continue;
        }

        if (tabuleiro[linha][coluna] != ' ') {
            printf("Essa célula já está ocupada. Tente novamente.\n");
            continue;
        }

        // Marca no tabuleiro
        tabuleiro[linha][coluna] = jogador == 1 ? 'X' : 'O';
        jogadas++;

        // Verifica ganhador
        if (verificarGanhador(tabuleiro, jogador == 1 ? 'X' : 'O')) {
            imprimirTabuleiro(tabuleiro);
            printf("Jogador %d venceu!\n", jogador);
            break;
        }

        if (jogadas == 9) {
            imprimirTabuleiro(tabuleiro);
            printf("Empate! Ninguém venceu.\n");
            break;
        }

        jogador = jogador == 1 ? 2 : 1;
    }

    return 0;
}
