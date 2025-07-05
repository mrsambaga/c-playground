#include <stdio.h>
#include <stdbool.h>

void printBoard(char board[3][3]);
int checkWin(char board[3][3]);
void assignInputBoard(int input, int playerTurn, char board[3][3]);

int tictactoe() {
    
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
    
    int playerTurn = 1;
    int moves = 0;
    int input = -1;
    int winner = 0;

    printf("        TIC TAC TOE        \n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");

    while (winner == 0 && moves < 9) {
        printBoard(board);
        
        playerTurn = (moves % 2) + 1;
        
        while (input < 0 || input > 9)
        {
            printf("Player %d, enter a number: ", playerTurn);
            scanf("%d", &input);
            printf("\n");

            if (input < 1 || input > 9) {
                printf("Invalid input! Please enter a number between 1 and 9.\n\n");
                continue; 
            }

            if (board[(input-1)/3][(input-1)%3] == 'X' || board[(input-1)/3][(input-1)%3] == 'O') {
                printf("That spot is already taken! Try again.\n\n");
                continue; 
            }
        }

        assignInputBoard(input, playerTurn, board);
        moves++;
        input = -1;
        
        winner = checkWin(board);
    }

    printBoard(board);

    if (winner != 0) {
        printf("Player %d wins! \n", winner);
    } else {
        printf("It's a draw! 🤝\n");
    }

    return 0;
}

void printBoard(char board[3][3]) {
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

void assignInputBoard(int input, int playerTurn, char board[3][3]) {
    char mark = (playerTurn == 1) ? 'X' : 'O';
    int row = (input - 1) / 3;
    int col = (input - 1) % 3;
    board[row][col] = mark;
}

int checkWin(char board[3][3]) {
    char players[2] = {'X', 'O'};
    
    for (int p = 0; p < 2; p++) {
        char mark = players[p];
        
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) || 
                (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) { 
                return p + 1; 
            }
        }
        
        if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
            (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
            return p + 1;
        }
    }
    
    return 0;
}