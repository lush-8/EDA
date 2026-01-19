#include <iostream>
#include <vector>
using namespace std;

template <typename T>
using V = vector<T> ;
const int n = 9 ;

void read(V<V<char>>& sudoku, V<pair<int, int>>& emptyPos, V<V<bool>>& row, V<V<bool>>& col, V<V<V<bool>>>& block) {

    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < n ; ++j) {
            char c ;
            cin >> c ;
            sudoku[i][j] = c ;

            if (c == '.') emptyPos.push_back({i, j}) ;
            else {
                int val = sudoku[i][j] - '1' ;
                row[i][val] = col[j][val] = block[i/3][j/3][val] = true ;
            }
        }
    }
}

void Write(const V<V<char>>& sudoku) {

    cout << endl ;
    
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < n ; ++j) {
            if (j != 0) cout << ' ' ;
            cout << sudoku[i][j] ;
        }
        cout << endl ;
    }
}

bool BackTrack(int idx, V<V<char>>& sudoku, V<pair<int, int>>& emptyPos, V<V<bool>>& row, V<V<bool>>& col, V<V<V<bool>>>& block) {

    if (idx == emptyPos.size()) {
        Write(sudoku) ;
        return true ;
    }
    int i = emptyPos[idx].first ;
    int j = emptyPos[idx].second ;

    for (int val = 0 ; val < n ; ++val) {
        if (not row[i][val] and not col[j][val] and not block[i/3][j/3][val]) {
            row[i][val] = col[j][val] = block[i/3][j/3][val] = true ;
            sudoku[i][j] = val + '1' ;

            if (BackTrack(idx + 1, sudoku, emptyPos, row, col, block)) {
                return true ;
            }
            row[i][val] = col[j][val] = block[i/3][j/3][val] = false ;
        }
    }
    return false ;
}

void solve(V<V<char>>& sudoku, V<pair<int, int>>& emptyPos, V<V<bool>>& row, V<V<bool>>& col, V<V<V<bool>>>& block) {

    BackTrack(0, sudoku, emptyPos, row, col, block) ;
}

int main () {

    int t ;
    cin >> t ;
    cout << t << endl ;

    for (int i = 0 ; i < t ; ++i) {
        V<V<char>> sudoku(n, V<char>(n)) ;
        V<pair<int, int>> emptyPos ;
        V<V<bool>> row(n, V<bool>(n, false)) ;
        V<V<bool>> col(n, V<bool>(n, false)) ;
        V<V<V<bool>>> block(n/3, V<V<bool>>(n/3, V<bool>(n, false))) ;
        read(sudoku, emptyPos, row, col, block) ;
        solve(sudoku, emptyPos, row, col, block) ;
    }
}