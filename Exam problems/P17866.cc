#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<pair<int, int>> directions{{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}} ;

bool valid(int i, int j, const vector<vector<char>>& board) {
    
    return 0 <= i and i < board.size() and 0 <= j and j < board[0].size() and board[i][j] != 'X' ;
}

int BFS(int ini_i, int ini_j, const vector<vector<char>>& board) {

    int n = board.size() ;
    int m = board[0].size() ;
    queue<pair<int, int>> q ;
    vector<vector<int>> dist(n, vector<int>(m, -1)) ;
    q.push({ini_i, ini_j}) ;
    dist[ini_i][ini_j] = 0 ;

    while (not q.empty()) {
        int i = q.front().first ;
        int j = q.front().second ;
        q.pop() ;

        for (const pair<int, int>& d : directions) {
            int ni = i + d.first ;
            int nj = j + d.second ;

            if (valid(ni, nj, board) and dist[ni][nj] == -1) {
                dist[ni][nj] = dist[i][j] + 1 ;

                if (board[ni][nj] == 'p') return dist[ni][nj] ;
                q.push({ni, nj}) ;
            }
        }
    }
    return -1 ;
}

int main () {
    
    int n , m ;

    while (cin >> n >> m) {
        vector<vector<char>> board(n, vector<char>(m)) ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) cin >> board[i][j] ;
        }
        int ini_i , ini_j ;
        cin >> ini_i >> ini_j ;
        int steps = BFS(--ini_i, --ini_j, board) ;

        if (steps == -1) cout << "no" ;
        else cout << steps ;
        cout << endl ;
    }
}