#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const vector<pair<int, int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}} ;

bool on_border(const pair<int, int>& p, int n) {

    return p.first == 0 or p.second == 0 or p.first == n - 1 or p.second == n - 1 ;
}

int Dijkstra(const vector<vector<int>>& board) {

    int n = board.size() ;
    pair<int, int> center = {n/2, n/2} ;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX)) ;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq ;
    dist[center.first][center.second] = board[center.first][center.second] ;
    pq.push({dist[center.first][center.second], center}) ;

    while (not pq.empty()) {
        pair<int, int> p = pq.top().second ;
        pq.pop() ;

        if (dist[p.first][p.second] != INT_MAX) {
            if (on_border(p, n)) return dist[p.first][p.second] ;
            for (const pair<int, int>& d : directions) {
                pair<int, int> neighbour = {p.first + d.first, p.second + d.second} ;

                if (dist[p.first][p.second] + board[neighbour.first][neighbour.second] < dist[neighbour.first][neighbour.second]) {
                    dist[neighbour.first][neighbour.second] = dist[p.first][p.second] + board[neighbour.first][neighbour.second] ;
                    pq.push({dist[neighbour.first][neighbour.second], neighbour}) ;
                }
            }
        }
    }
    return -1 ;
}

int main () {

    int n ;

    while (cin >> n) {
        vector<vector<int>> board(n, vector<int>(n)) ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < n ; ++j) cin >> board[i][j] ;
        }
        cout << Dijkstra(board) << endl ;
    }
}