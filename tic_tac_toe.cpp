#include <iostream>
#include <limits>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Row check
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))   // Column check
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  // Main diagonal
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))    // Opposite diagonal
        return true;
    
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
    return true;
}

void playGame() {
    int move;
    char player = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";
    printBoard();

    while (!gameOver) {
        cout << "Player " << player << ", enter your move (1-9): ";
        if (!(cin >> move)) {
            // End of input: stop instead of looping forever.
            if (cin.eof()) {
                cout << "\nInput closed, game aborted.\n";
                return;
            }
            // Non-numeric input: without clearing the error state, cin keeps failing and this loop never ends.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid move! Please enter a number from 1 to 9.\n";
            continue;
        }

        if (move < 1 || move > 9) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already occupied! Try again.\n";
            continue;
        }

        board[row][col] = player;
        printBoard();

        if (checkWin(player)) {
            cout << "Player " << player << " wins!\n";
            gameOver = true;
        } else if (isDraw()) {
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            player = (player == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    playGame();
    return 0;
}
