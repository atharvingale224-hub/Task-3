#include <stdio.h>

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void displayBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i < 2)
            printf("\n---|---|---\n");
    }
    printf("\n\n");
}

int checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentPlayer &&
           board[i][1] == currentPlayer &&
           board[i][2] == currentPlayer)
            return 1;

        if(board[0][i] == currentPlayer &&
           board[1][i] == currentPlayer &&
           board[2][i] == currentPlayer)
            return 1;
    }

    if(board[0][0] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][2] == currentPlayer)
        return 1;

    if(board[0][2] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][0] == currentPlayer)
        return 1;

    return 0;
}

int checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == ' ')
                return 0;
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int row, col;
    char playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';

        while(1) {
            displayBoard();
            printf("Player %c, enter row and column (1-3): ", currentPlayer);
            scanf("%d %d", &row, &col);

            if(row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
                printf("Invalid move. Try again.\n");
                continue;
            }

            board[row-1][col-1] = currentPlayer;

            if(checkWin()) {
                displayBoard();
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            if(checkDraw()) {
                displayBoard();
                printf("Game is a draw!\n");
                break;
            }

            switchPlayer();
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}
