#include <iostream>
#include <limits>

using namespace std;

// Function declarations
void resetBoard(char board[3][3]);
void drawBoard(const char board[3][3]);
bool makeMove(char board[3][3], int slot, char playerMarker);
bool checkWin(const char board[3][3], char playerMarker);
bool checkDraw(const char board[3][3]);
void playGame();

int main() {
    char replayChoice;
    do {
        playGame();
        cout << "\nWould you like to play another match? (Y/N): ";
        cin >> replayChoice;
        replayChoice = toupper(replayChoice);
    } while (replayChoice == 'Y');

    cout << "\nThank you for playing! See you next time.\n";
    return 0;
}

void playGame() {
    char board[3][3];
    char currentMarker = 'X';
    int currentTurn = 1;
    bool isGameWon = false;
    bool isGameDraw = false;

    resetBoard(board);

    while (!isGameWon && !isGameDraw) {
        drawBoard(board);
        int slotChoice;

        cout << "\nPlayer '" << currentMarker << "', pick a slot (1-9): ";
        cin >> slotChoice;

        // Input validation for integers
        if (cin.fail() || slotChoice < 1 || slotChoice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid entry! Please input a single number between 1 and 9.\n";
            continue;
        }

        // Attempt move placement validation
        if (!makeMove(board, slotChoice, currentMarker)) {
            cout << "That slot is already occupied! Try picking a free space.\n";
            continue;
        }

        // Assess conditional game states
        isGameWon = checkWin(board, currentMarker);
        if (isGameWon) {
            drawBoard(board);
            cout << "\n🎉 Congratulations! Player '" << currentMarker << "' wins the match! 🎉\n";
            break;
        }

        isGameDraw = checkDraw(board);
        if (isGameDraw) {
            drawBoard(board);
            cout << "\n🤝 It's a draw! Well played by both sides.\n";
            break;
        }

        // Toggle player turn marker alternate state
        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
        currentTurn++;
    }
}

void resetBoard(char board[3][3]) {
    char countMarker = '1';
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            board[r][c] = countMarker++;
        }
    }
}

void drawBoard(const char board[3][3]) {
    // Refresh clean CLI space simulation 
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif

    cout << "\n======================================";
    cout << "\n       RETRO TIC-TAC-TOE GAME        ";
    cout << "\n======================================";
    cout << "\n\n";
    cout << "             |     |     \n";
    cout << "          " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "        _____|_____|_____\n";
    cout << "             |     |     \n";
    cout << "          " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "        _____|_____|_____\n";
    cout << "             |     |     \n";
    cout << "          " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "             |     |     \n\n";
    cout << "======================================\n";
}

bool makeMove(char board[3][3], int slot, char playerMarker) {
    // Map linear indexing (1-9) safely down to 2D structural array coords
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    // Check if slot has a default number marker remaining
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = playerMarker;
        return true;
    }
    return false;
}

bool checkWin(const char board[3][3], char playerMarker) {
    // Check linear structural horizontal rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == playerMarker && board[i][1] == playerMarker && board[i][2] == playerMarker)
            return true;
    }
    // Check vertical grid alignment columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == playerMarker && board[1][i] == playerMarker && board[2][i] == playerMarker)
            return true;
    }
    // Check crossing angular diagonals 
    if (board[0][0] == playerMarker && board[1][1] == playerMarker && board[2][2] == playerMarker)
        return true;
    if (board[0][2] == playerMarker && board[1][1] == playerMarker && board[2][0] == playerMarker)
        return true;

    return false;
}

bool checkDraw(const char board[3][3]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            // If any numerical marker is left, game isn't a draw yet
            if (board[r][c] != 'X' && board[r][c] != 'O')
                return false;
        }
    }
    return true;
}
