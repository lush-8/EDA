#include <iostream>
#include <vector>
using namespace std;

void write(const vector<vector<char>>& board, vector<char>& sol, int i, int j) {

    int n = board.size() ;
    int m = board[0].size() ;

    if (n <= i or m <= j) {
        for (const char& c : sol) cout << c ;
        cout << endl ;
    }
    else if (board[i][j] != 'X') {
        if (board[i][j] != 'D') {
            sol.push_back('A') ;
            write(board, sol, i + 1, j) ;
            sol.pop_back() ;
        }
        if (board[i][j] != 'A') {
            sol.push_back('D') ;
            write(board, sol, i, j + 1) ;
            sol.pop_back() ;
        }
    }
}

void write(const vector<vector<char>>& board) {

    vector<char> sol ;
    write(board, sol, 0, 0) ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<char>> board(n, vector<char>(m)) ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) cin >> board[i][j] ;
        }
        write(board) ;
        cout << string(10, '-') << endl ;
    }
}