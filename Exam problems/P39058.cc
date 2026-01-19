#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const vector<pair<int, int>> directions{{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}} ;

bool valid(int i, int j, const vector<vector<char>>& map) {

    return 0 <= i and i < map.size() and 0 <= j and j < map[0].size() and map[i][j] != 'a' ;
}

pair<int, double> BFS(int ini_i, int ini_j, const vector<vector<char>>& map) {

    int flowers = 0 ;
    int sum_dist = 0 ;
    vector<vector<int>> dist(map.size(), vector<int>(map[0].size(), INT_MAX)) ;
    queue<pair<int, int>> q ;
    q.push({ini_i, ini_j}) ;
    dist[ini_i][ini_j] = 0 ;

    while (not q.empty()) {
        pair<int, int> pos = q.front() ;
        q.pop() ;

        for (const pair<int, int>& d : directions) {
            int ni = pos.first + d.first ;
            int nj = pos.second + d.second ;

            if (valid(ni, nj, map) and dist[ni][nj] == INT_MAX) {
                dist[ni][nj] = dist[pos.first][pos.second] + 1 ;
                q.push({ni, nj}) ;

                if (map[ni][nj] == 'F') {
                    ++flowers ;
                    sum_dist += dist[ni][nj] ;
                }
            }
        }
    }
    if (flowers) return {flowers, double(sum_dist)/flowers} ;
    return {0, 0} ;
} 

int main () {

    cout.setf(ios::fixed) ;
    cout.precision(4) ;

    int n , m ;
    cin >> n >> m ;
    vector<vector<char>> map(n, vector<char>(m)) ;
    int ini_i = -1 ;
    int ini_j = -1 ;

    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            cin >> map[i][j] ;

            if (map[i][j] == 'C') {
                ini_i = i ;
                ini_j = j ;
            }
        }
    }
    pair<int, double> result = BFS(ini_i, ini_j, map) ;

    if (result.first) {
        cout << "flors accessibles: " << result.first << endl ;
        cout << "distancia mitjana: " << result.second << endl ;
    }
    else cout << "el cavall no pot arribar a cap flor" << endl ;
}