#include<iostream>
using namespace std;
int CurrentPlayer;
char CurrentMarker;
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;
}

bool placeMarker(int slot)
{
   int row = (slot - 1) / 3;
   int col = (slot - 1) % 3;

   if (board[row][col] != 'X' && board[row][col] != 'O')
   {
       board[row][col] = CurrentMarker;
       return true;
   }
   else
   {
       cout << "Slot already taken. Try again." << endl;
       return false;
   }

}

int winner() {
    //Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return CurrentPlayer;
    }
    //Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return CurrentPlayer;
    }
    //Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return CurrentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return CurrentPlayer;

    return 0; // No winner yet
}

void swapPlayerandMarker()
{
    if (CurrentMarker == 'X')
        CurrentMarker = 'O';
    else
        CurrentMarker = 'X';

    if (CurrentPlayer == 1)
        CurrentPlayer = 2;
    else
        CurrentPlayer = 1;
}
void game()
{
    cout << "Players choose your marker(X or O) :" << endl;
    char MarkerP1;
    cout << "Player 1: ";
    cin >> MarkerP1;

        CurrentPlayer = 1;
        CurrentMarker=MarkerP1;
        drawBoard();
        int playerwon;
        for (int i = 0; i < 9; i++)
        {
           cout << "Player " << CurrentPlayer << " choose your position: ";
           int slot;
           cin >> slot;
           if(slot < 1 || slot > 9)
           {
                cout << "Invalid slot. Try again." << endl;
                i--;
                continue;
           }
           if (!placeMarker(slot)) {
            cout << "Slot already taken. Try again." << endl;
            i--;
            continue;
           }
           drawBoard();
              // Check for win condition
              playerwon = winner();
                if (playerwon == 1) {
                    cout << "Player 1 wins!" << endl;
                    break;
                }
                else if (playerwon == 2) {
                    cout << "Player 2 wins!" << endl;
                    break;
                }
                swapPlayerandMarker();
                if (playerwon == 0 && i == 8) {
                    cout << "It's a draw!" << endl;
                }

        }

}
int main()
{
    cout << "Welcome to Tic Tac Toe!" << endl;
    game();
    return 0;
}