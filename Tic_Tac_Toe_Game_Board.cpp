#include <iostream>
#include <cstdlib> // for system("cls")
using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};

// Function to display the board
void displayBoard() {
    system("cls"); // For Windows to clear the screen
    cout << "\n\tTic Tac Toe\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    cout << "\t     |     |     \n\n";
}

// Function to check win or draw
int checkWin() {
    // Check rows, columns and diagonals
    for (int i = 0; i < 9; i += 3)
        if (board[i] == board[i+1] && board[i+1] == board[i+2])
            return 1;

    for (int i = 0; i < 3; i++)
        if (board[i] == board[i+3] && board[i+3] == board[i+6])
            return 1;

    if (board[0] == board[4] && board[4] == board[8])
        return 1;

    if (board[2] == board[4] && board[4] == board[6])
        return 1;

    // Check draw
    for (int i = 0; i < 9; i++)
        if (board[i] != 'X' && board[i] != 'O')
            return 0;

    return -1; // Draw
}

int main() {
    int player = 1, choice;
    char mark;
    int gameStatus = 0;

    do {
        displayBoard();
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << ", enter a number (1-9): ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && board[choice - 1] != 'X' && board[choice - 1] != 'O') {
            board[choice - 1] = mark;
        } else {
            cout << "Invalid move! Try again.\n";
            cin.ignore();
            cin.get();
            continue;
        }

        gameStatus = checkWin();
        player++;
    } while (gameStatus == 0);

    displayBoard();

    if (gameStatus == 1)
        cout << "==>\aPlayer " << --player << " wins!\n";
    else
        cout << "==>\aGame draw!\n";

    return 0;
}
