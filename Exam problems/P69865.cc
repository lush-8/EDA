#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int r , c ;
};

const int N_DIRS_KNIGHT = 8 ;
const vector<pair<int, int>> DIRECTIONS_KNIGHT = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}} ;
const int N_DIRS_BISHOP = 4 ;
const vector<pair<int, int>> DIRECTIONS_BISHOP = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}} ;

bool ok(int n, int m, const Point& p) {
    
    return 0 <= p.r and p.r < n and 0 <= p.c and p.c < m ;
}

int DFS(int n, int m, const Point& p, vector<vector<char>>& board, vector<vector<bool>>& marked, const int N_DIRS, const vector<pair<int, int>>& DIRECTIONS) {

    int coins = 0 ;
    marked[p.r][p.c] = true ;

    for (int i = 0 ; i < N_DIRS ; ++i) {
        Point q = {p.r + DIRECTIONS[i].first, p.c + DIRECTIONS[i].second} ;

        if (ok(n, m, q) and board[q.r][q.c] != 'T' and not marked[q.r][q.c]) coins += DFS(n, m, q, board, marked, N_DIRS, DIRECTIONS) ;
    }
    if ('0' <= board[p.r][p.c] and board[p.r][p.c] <= '9') {
        coins += board[p.r][p.c] - '0' ;
        board[p.r][p.c] = '.' ;
    }
    return coins ;
} 
 
int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<Point> knights ;
        vector<Point> bishops ;
        vector<vector<char>> board(n, vector<char>(m)) ;
        
        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                cin >> board[i][j] ;

                if (board[i][j] == 'K') knights.push_back({i, j}) ;
                else if (board[i][j] == 'B') bishops.push_back({i, j}) ; 
            }
        }
        int coins = 0 ;
        vector<vector<bool>> marked_knight(n, vector<bool>(m, false)) ;
        
        for (int i = 0 ; i < knights.size() ; ++i) {
            Point p = knights[i] ;
            
            if (not marked_knight[p.r][p.c]) coins += DFS(n, m, p, board, marked_knight, N_DIRS_KNIGHT, DIRECTIONS_KNIGHT) ;
        }
        vector<vector<bool>> marked_bishop(n, vector<bool>(m, false)) ;

        for (int i = 0 ; i < bishops.size() ; ++i) {
            Point p = bishops[i] ;

            if (not marked_bishop[p.r][p.c]) coins += DFS(n, m, p, board, marked_bishop, N_DIRS_BISHOP, DIRECTIONS_BISHOP) ;
        }
        cout << coins << endl ;
    }
}