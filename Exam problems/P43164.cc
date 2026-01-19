#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}} ;

bool valid(int i, int j, const vector<vector<char>>& map) {

    return 0 <= i and i < map.size() and 0 <= j and j < map[0].size() ;
}

int BFS(int start_i, int start_j, vector<vector<char>>& map) {

    int max_dist = -1 ;
    int second_dist = -1 ;
    queue<pair<pair<int, int>, int>> q ;
    q.push({{start_i, start_j}, 0}) ;
    map[start_i][start_j] = 'X' ;

    while (not q.empty()) {
        int i = q.front().first.first ;
        int j = q.front().first.second ;
        int d = q.front().second ;
        q.pop() ;

        for (const pair<int, int>& dir : directions) {
            int next_i = i + dir.first ;
            int next_j = j + dir.second ;

            if (valid(next_i, next_j, map) and map[next_i][next_j] != 'X') {
                if (map[next_i][next_j] == 't') {
                    second_dist = max_dist ;
                    max_dist = d + 1 ;
                }
                q.push({{next_i, next_j}, d + 1}) ;
                map[next_i][next_j] = 'X' ;
            }
        }
    }
    return second_dist ;
}

int main () {

    int n , m ;
    cin >> n >> m ;
    vector<vector<char>> map(n, vector<char>(m)) ;

    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) cin >> map[i][j] ;
    }
    int f , c ;
    cin >> f >> c ;
    int dist = BFS(--f, --c, map) ;

    if (dist == -1) cout << "no es pot arribar a dos o mes tresors" ;
    else cout << "segona distancia maxima: " << dist ;
    cout << endl ;
}