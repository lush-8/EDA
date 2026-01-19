#include <iostream>
#include <vector>
using namespace std;

const vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}} ;

void Write(const vector<vector<bool>>& v) {

    for (int i = 0 ; i < v.size() ; ++i) {
        for (int j = 0 ; j < v[0].size() ; ++j) {
            if (v[i][j]) cout << 'K' ;
            else cout << '.' ;
        }
        cout << endl ;
    }
    cout << string(10, '-') << endl ;
}

void next(const int& i, const int& j, const int& n, int& next_i, int& next_j) {
    
    if (j < n - 1) {
        next_i = i ;
        next_j = j + 1 ;
    }
    else {
        next_i = i + 1 ;
        next_j = 0 ;
    }
}

bool ok(const int& i, const int& j, const int& n) {
    
    return 0 <= i and i < n and 0 <= j and j < n ;
}

bool safe(const int& i, const int& j, const int& n, const vector<vector<bool>>& m) {

    for (const pair<int, int>& d : directions) {
        int next_i = i + d.first ;
        int next_j = j + d.second ;

        if (ok(next_i, next_j, n) and m[next_i][next_j]) return false ;
    }
    return true ;
}

void BackTrack(int i, int j, int placed, const int& r, vector<vector<bool>>& board, const int& n) {

    if (placed == r) Write(board) ;
    else if (i != n) {
        int next_i , next_j ;
        next(i, j, n, next_i, next_j) ;

        if (safe(i, j, n, board)) {
            board[i][j] = true ;
            BackTrack(next_i, next_j, placed + 1, r, board, n) ;
        }
        board[i][j] = false ;
        BackTrack(next_i, next_j, placed, r, board, n) ;
    }
}

int main () {

    int n , r ;
    cin >> n >> r ;
    vector<vector<bool>> board(n, vector<bool>(n, false)) ;
    BackTrack(0, 0, 0, r, board, n) ;
}