#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const vector<pair<int, int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}} ;

void BFS(int ini_i, int ini_j, const vector<vector<char>>& board) {

    int n = board.size() ;
    int m = board[0].size() ;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX)) ;
    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m)) ;
    queue<pair<int, int>> q ;
    dist[ini_i][ini_j] = 0 ;
    q.push({ini_i, ini_j}) ;
    bool found = false ;
    int i_farmer , j_farmer ;

    while (not q.empty() and not found) {
        int i = q.front().first ;
        int j = q.front().second ;
        q.pop() ;

        for (const pair<int, int>& d : directions) {
            int ni = i + d.first ;
            int nj = j + d.second ;

            if (board[ni][nj] != 'X' and dist[ni][nj] == INT_MAX) {
                if (board[ni][nj] == 'F') {
                    i_farmer = ni ;
                    j_farmer = nj ;
                    found = true ;
                }
                dist[ni][nj] = dist[i][j] + 1 ;
                prev[ni][nj] = {i, j} ;
                q.push({ni, nj}) ;
            }
        }
    }
    if (not found) cout << 0 << endl ;
    else {
        cout << dist[i_farmer][j_farmer] + 1 ;
        pair<int, int> current = {i_farmer, j_farmer} ;
        pair<int, int> goal = {ini_i, ini_j} ;
        vector<pair<int, int>> path ;

        while (current != goal) {
            path.push_back(current) ;
            current = prev[current.first][current.second] ;
        }
        path.push_back(goal) ;

        for (int i = path.size() - 1 ; i >= 0 ; --i) cout << "  " << path[i].first << ' ' << path[i].second ;
        cout << endl ;
    }
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<char>> board(n, vector<char>(m)) ;
        int ini_i , ini_j ;
        ini_i = ini_j = -1 ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                cin >> board[i][j] ;

                if (board[i][j] == 'K') {
                    ini_i = i ;
                    ini_j = j ;
                }
            }
        }
        BFS(ini_i, ini_j, board) ;
    }
}