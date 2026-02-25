#include <iostream>
using namespace std;

int main() {
    char board[3][3];
    int row, col;
    char player = 'X';
    int moves = 0;
    int win = 0;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = ' ';

    cout << "Welcome to XO game\n";

    while(moves < 9 && win==0) {
        cout << "\nBoard now:\n";
        cout << "  1 2 3\n";
        for(int i=0;i<3;i++){
            cout << i+1 << " ";
            for(int j=0;j<3;j++){
                cout << board[i][j];
                if(j<2) cout << "|";
            }
            cout << "\n";
            if(i<2) cout << "  -+-+-\n";
        }

        cout << "\nPlayer " << player << ", enter row and column (1-3): ";
        cin >> row >> col;
        row--; col--;

        if(row<0 || row>2 || col<0 || col>2){
            cout << "Invalid spot, try again.\n";
            continue;
        }

        if(board[row][col] != ' '){
            cout << "Already marked, choose another spot.\n";
            continue;
        }

        board[row][col] = player;
        moves++;

        for(int i=0;i<3;i++)
            if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
                win=1;

        for(int i=0;i<3;i++)
            if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
                win=1;

        if(board[0][0]==player && board[1][1]==player && board[2][2]==player) win=1;
        if(board[0][2]==player && board[1][1]==player && board[2][0]==player) win=1;

        if(win==1){
            cout << "\nPlayer " << player << " won!\n";
            break;
        }

        player = (player=='X') ? 'O' : 'X';
    }

    if(win==0)
        cout << "\nIt's a draw!\n";

    return 0;
}