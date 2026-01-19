#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<pair<int, int>> directions = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}} ;

bool valid(const vector<vector<char>>& board, int i, int j) {

    return 0 <= i and i < board.size() and 0 <= j and j < board[0].size() and board[i][j] != 'X' ;
}

int BFS(const vector<vector<char>>& board, int f, int c) {

    int n = board.size() ;
    int m = board[0].size() ;
    vector<vector<int>> dist(n, vector<int>(m, -1)) ;
    queue<pair<int, int>> q ;
    q.push({f, c}) ;
    dist[f][c] = 0 ;

    while (not q.empty()) {
        pair<int, int> p = q.front() ;
        q.pop() ;
        int x = p.first ;
        int y = p.second ;

        if (board[x][y] == 'p') return dist[x][y] ;
        for (int k = 0 ; k < 8 ; ++k) {
            int next_x = x + directions[k].first ;
            int next_y = y + directions[k].second ;

            if (valid(board, next_x, next_y) and dist[next_x][next_y] == -1) {
                q.push({next_x, next_y}) ;
                dist[next_x][next_y] = dist[x][y] + 1 ;
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
        int f , c ;
        cin >> f >> c ;
        int dist = BFS(board, --f, --c) ;

        if (dist != -1) cout << dist ;
        else cout << "no" ;
        cout << endl ;
    }
}