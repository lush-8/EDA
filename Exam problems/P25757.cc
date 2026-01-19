#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}} ;

void label(vector<vector<int>>& cc, const vector<vector<char>>& board, int i, int j, int num) {

    int n = board.size() ;
    int m = board[0].size() ;

    if (i < 0 or n <= i or j < 0 or m <= j or board[i][j] == 'X' or cc[i][j]) return ;
    cc[i][j] = num ;

    for (const pair<int, int>& d : dirs) {
        label(cc, board, i + d.first, j + d.second, num) ;
    }
}

void paint(vector<vector<char>>& board, const vector<pair<int, int>>& pos) {

    int n = board.size() ;
    int m = board[0].size() ;
    vector<vector<int>> cc(n, vector<int>(m, 0)) ;
    int num = 0 ;

    for (const pair<int, int>& p : pos) {
        if (cc[p.first][p.second] == 0) {
            ++num ;
            label(cc, board, p.first, p.second, num) ;
        }
    }
    vector<char> letter_cc(num + 1, 'U') ;

    for (const pair<int, int>& p : pos) {
        int n_cc = cc[p.first][p.second] ;

        if (letter_cc[n_cc] == 'U') letter_cc[n_cc] = board[p.first][p.second] ;
        else if (letter_cc[n_cc] != board[p.first][p.second]) letter_cc[n_cc] = '.' ;
    }
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            int n_cc = cc[i][j] ;

            if (n_cc) board[i][j] = letter_cc[n_cc] ;
        }
    }
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<char>> board(n, vector<char>(m)) ;
        vector<pair<int, int>> pos ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                cin >> board[i][j] ;

                if ('a' <= board[i][j] and board[i][j] <= 'z') {
                    pos.push_back({i, j}) ;
                }
            }
        }
        paint(board, pos) ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                cout << board[i][j] ;
            }
            cout << endl ;
        }
        cout << endl ;
    }
}