#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}} ;
const vector<pair<int, int>> surround = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}} ;

void Read(vector<vector<char>>& board, pair<int, int>& start) {

    for (int i = 0 ; i < board.size() ; ++i) {
        for (int j = 0 ; j < board[0].size() ; ++j) {
            cin >> board[i][j] ;

            if (board[i][j] == 'P') start = {i, j} ;
        }
    }
}

bool Ghost_nearby(const vector<vector<char>>& board, int i, int j) {

    for (const pair<int, int>& d : surround) {
        if (board[i + d.first][j + d.second] == 'F') return true ;
    }
    return false ;
}

bool BFS(vector<vector<char>>& board, const pair<int, int>& start) {

    if (board[start.first][start.second] == 'X' or Ghost_nearby(board, start.first, start.second)) return false ;
    queue<pair<int, int>> q ;
    board[start.first][start.second] = 'X' ;
    q.push(start) ;

    while (not q.empty()) {
        pair<int, int> p = q.front() ;
        q.pop() ;

        for (const pair<int, int>& d : directions) {
            int i = p.first + d.first ;
            int j = p.second + d.second ;
              
            if (board[i][j] == 'B' and not Ghost_nearby(board, i, j)) return true ;
            if (board[i][j] != 'X' and board[i][j] != 'F' and not Ghost_nearby(board, i, j)) {
                board[i][j] = 'X' ;
                q.push({i, j}) ;
            }
        }
    }
    return false ;
}

int main () {

    int f , c ;
    
    while (cin >> f >> c) {
        vector<vector<char>> board(f, vector<char>(c)) ;
        pair<int, int> start ;
        Read(board, start) ;
        cout << (BFS(board, start) ? "si" : "no") << endl ;
    }
}

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}} ;
const vector<pair<int, int>> surround = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}} ;

void Read(vector<vector<char>>& board, pair<int, int>& start, queue<pair<int, int>>& ghosts) {

    for (int i = 0 ; i < board.size() ; ++i) {
        for (int j = 0 ; j < board[0].size() ; ++j) {
            cin >> board[i][j] ;

            if (board[i][j] == 'P') start = {i, j} ;
            else if (board[i][j] == 'F') ghosts.push({i, j}) ;
        }
    }
}

bool BFS(vector<vector<char>>& board, const pair<int, int>& start) {

    if (board[start.first][start.second] == 'X') return false ;
    queue<pair<int, int>> q ;
    board[start.first][start.second] = 'X' ;
    q.push(start) ;

    while (not q.empty()) {
        pair<int, int> p = q.front() ;
        q.pop() ;

        for (const pair<int, int>& d : directions) {
            int i = p.first + d.first ;
            int j = p.second + d.second ;

            if (board[i][j] == 'B') return true ;
            if (board[i][j] != 'X') {
                board[i][j] = 'X' ;
                q.push({i, j}) ;
            }
        }
    }
    return false ;
}

int main () {

    int f , c ;
    
    while (cin >> f >> c) {
        vector<vector<char>> board(f, vector<char>(c)) ;
        pair<int, int> start ;
        queue<pair<int, int>> ghosts ;
        Read(board, start, ghosts) ;

        while (not ghosts.empty()) {
            for (const pair<int, int>& d : surround) {
                board[ghosts.front().first + d.first][ghosts.front().second + d.second] = 'X' ;
            }
            ghosts.pop() ;
        }
        cout << (BFS(board, start) ? "si" : "no") << endl ;
    }
}
*/