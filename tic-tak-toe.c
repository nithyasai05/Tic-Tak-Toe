#include <stdio.h>
#include <stdlib.h>

char square[10];
int checkWin();
void drawBoard();
void resetBoard();

int main() {
    char playAgain;
    
    do {
        resetBoard();
        int player = 1, i, choice;
        char mark;
        
        do {
            drawBoard();
            player = (player % 2) ? 1 : 2;
            printf("Player %d, enter your choice: ", player);
            
            if (scanf("%d", &choice) != 1) {
                printf("Invalid input! Please enter a number between 1 and 9.\n");
                while (getchar() != '\n');
                continue;
            }

            mark = (player == 1) ? 'X' : 'O';

            if (choice >= 1 && choice <= 9 && square[choice] == ('0' + choice)) {
                square[choice] = mark;
            } else {
                printf("Invalid move! Try again.\n");
                continue;
            }

            i = checkWin();
            player++;

        } while (i == -1);

        drawBoard();
        if (i == 1) {
            printf("==> Player %d won!\n", --player);
        } else {
            printf("==> Game draw!\n");
        }
        
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}

int checkWin() {
    if (square[1] == square[2] && square[2] == square[3]) return 1;
    if (square[4] == square[5] && square[5] == square[6]) return 1;
    if (square[7] == square[8] && square[8] == square[9]) return 1;
    if (square[1] == square[4] && square[4] == square[7]) return 1;
    if (square[2] == square[5] && square[5] == square[8]) return 1;
    if (square[3] == square[6] && square[6] == square[9]) return 1;
    if (square[1] == square[5] && square[5] == square[9]) return 1;
    if (square[3] == square[5] && square[5] == square[7]) return 1;
    if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' &&
        square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    
    return -1;
}

void drawBoard() {
    system("cls");
    printf("\n\n\t Tic Tac Toe \n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[7], square[8], square[9]);
    printf("     |     |     \n");
}

void resetBoard() {
	int i;
    for (i = 1; i <= 9; i++) {
        square[i] = '0' + i;
    }
}
