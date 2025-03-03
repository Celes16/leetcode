#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para contar quantos peões o bispo pode capturar
int numRookCaptures(char** board, int boardSize, int* boardColSize) {
    int x = 0, y = 0, res = 0;

    // Encontrar a posição do bispo ('R')
    for (int i = 0; i < boardSize; i++) { // Linhas
        for (int j = 0; j < *boardColSize; j++) { // Colunas
            if (board[i][j] == 'R') {
                x = i;
                y = j;
                break;
            }
        }
    }

    // Direções possíveis: cima, baixo, esquerda, direita
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Verificar em cada direção
    for (int d = 0; d < 4; d++) {
        int a = x + dirs[d][0];
        int b = y + dirs[d][1];

        // Continuar até sair do tabuleiro ou encontrar um obstáculo
        while (a >= 0 && a < boardSize && b >= 0 && b < *boardColSize) {
            if (board[a][b] == 'p') { // Encontrou um peão
                res++;
                break;
            } else if (board[a][b] == 'B') { // Encontrou um bispo (obstáculo)
                break;
            }
            a += dirs[d][0];
            b += dirs[d][1];
        }
    }

    return res;
}

// Função principal para testar o código
int main() {
    // Exemplo de tabuleiro de xadrez
    char* board[] = {
        ". . . . . . . .",
        ". p . p . . . .",
        ". . R . . . . .",
        ". . . B . . . .",
        ". . . . . . . .",
        ". . . . . . . .",
        ". . . . . . . .",
        ". . . . . . . ."
    };

    // Tamanho do tabuleiro e número de colunas
    int boardSize = 8;
    int boardColSize = 8;

    // Alocar memória para o tabuleiro
    char** boardArray = (char**)malloc(boardSize * sizeof(char*));
    for (int i = 0; i < boardSize; i++) {
        boardArray[i] = (char*)malloc((boardColSize + 1) * sizeof(char));
        strcpy(boardArray[i], board[i]);
    }

    // Chamar a função e imprimir o resultado
    int result = numRookCaptures(boardArray, boardSize, &boardColSize);
    printf("Número de peões capturáveis: %d\n", result);

    // Liberar memória alocada
    for (int i = 0; i < boardSize; i++) {
        free(boardArray[i]);
    }
    free(boardArray);

    return 0;
}
