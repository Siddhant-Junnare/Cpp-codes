#include<iostream>
using namespace std;

void createBoard(char TicTacToeBoard[3][3])
{
    for (int i = 0 ; i < 3 ; i++)
        for (int j = 0 ; j < 3 ; j++)
            TicTacToeBoard[i][j] = ' ' ; 
}

void displayBoard(char TicTacToeBoard[3][3])
{
    for (int i = 0 ; i < 3 ; i++)
    {
        cout << "-------------" << endl;
        cout << "| ";
        for(int j = 0 ; j < 3 ; j++)
            cout << TicTacToeBoard[i][j] << " | ";
        cout << endl;
    }
    cout << "-------------" << endl;
}

void playerMove(char TicTacToeBoard[3][3], char player, int &row, int &col)
{
    while(true)
    {
        cout << "Enter the cell number\n";
        
        cout << "Row : ";
        cin >> row;
        
        cout << "Column : ";
        cin >> col;

        row--;
        col--;

        if(row >= 0 && row < 3 && col >= 0 && col < 3 && TicTacToeBoard[row][col] == ' ')
        {
            TicTacToeBoard[row][col] = player;
            break;
        }
        else
            cout << "Invalid move! Try again." << endl;
        
    }
}


bool isWin(char TicTacToeBoard[3][3], char player, int row, int col)
{
    // checking row win condition
    if(TicTacToeBoard[row][0] == player && TicTacToeBoard[row][1] == player && TicTacToeBoard[row][2] == player)
        return 1;
        
    // checking column wining condn
    if(TicTacToeBoard[0][col] == player && TicTacToeBoard[1][col] == player && TicTacToeBoard[2][col] == player)
        return 1;

    // checking primary diagonal
    if(row == col)
        if(TicTacToeBoard[0][0] == player && TicTacToeBoard[1][1] == player && TicTacToeBoard[2][2] == player)
            return 1;

    // checking secondary diagonal
    if(row + col == 2)
        if(TicTacToeBoard[0][2] == player && TicTacToeBoard[1][1] == player && TicTacToeBoard[2][0] == player)
            return 1;
    
    return 0;
}

void playGame(char TicTacToeBoard[3][3])
{
    char P1 = 'X';
    char P2 = 'O';
    int cntMoves = 0;
    int row, col;

    while(cntMoves <= 9)
    {
        cout << "1st Player's move" << endl;
        playerMove(TicTacToeBoard, P1, row, col);
        displayBoard(TicTacToeBoard);
        cntMoves++;

        if(cntMoves > 4 && isWin(TicTacToeBoard, P1, row, col))
        {
            cout << "Player 1 wins!" << endl;
            return;
        }

        if(cntMoves == 9) 
            break;

        cout << "2nd Player's move" << endl;
        playerMove(TicTacToeBoard, P2, row, col);
        displayBoard(TicTacToeBoard);
        cntMoves++;

        if(cntMoves > 4 && isWin(TicTacToeBoard, P2, row, col))
        {
            cout << "Player 2 wins!" << endl;
            return;
        }
    }

    cout << "Draw" << endl;
}

int main()
{
    char TicTacToeBoard[3][3];
    createBoard(TicTacToeBoard);
    displayBoard(TicTacToeBoard);
    playGame(TicTacToeBoard);
    return 0;
}