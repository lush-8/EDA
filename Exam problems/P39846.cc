#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Tuple {
    int i ;
    int j ;
    int dist ;
};

vector<vector<char>> read_map(int n, int m) {

    vector<vector<char>> result(n, vector<char>(m)) ;

    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) cin >> result[i][j] ;
    }
    return result ;
}

bool valid(int i, int j, const vector<vector<char>>& map) {

    return 0 <= i and i < map.size() and 0 <= j and j < map[0].size() ;
}

void BFS(vector<vector<char>>& map, int i, int j, int& max_dist) {

    if (map[i][j] == 't') {
        max_dist = max(max_dist, 0) ;
    }
    const vector<int> directions{-1, 0, 1, 0, -1} ;
    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size())) ;
    visited[i][j] = true ;
    queue<Tuple> q ;
    q.push({i, j, 0}) ;
    
    while (not q.empty()) {
        Tuple t = q.front() ;
        q.pop() ;         
            
        for (int i = 0 ; i < 4 ; ++i) {
            int next_i = t.i + directions[i] ;
            int next_j = t.j + directions[i + 1] ;

            if (valid(next_i, next_j, map) and not visited[next_i][next_j] and map[next_i][next_j] != 'X') {
                if (map[next_i][next_j] == 't') {
                    max_dist = max(max_dist, t.dist + 1) ;
                }
                visited[next_i][next_j] = true ;
                q.push({next_i, next_j, t.dist + 1}) ;
            }
        }
    }
}

int main () {

    int n , m ;
    cin >> n >> m ;
    vector<vector<char>> map = read_map(n, m) ;
    int x , y ;
    cin >> x >> y ;
    int max_dist = -1 ;
    BFS(map, --x, --y, max_dist) ;

    if (max_dist != -1) cout << "distancia maxima: " << max_dist ;
    else cout << "no es pot arribar a cap tresor" ;
    cout << endl ;
}