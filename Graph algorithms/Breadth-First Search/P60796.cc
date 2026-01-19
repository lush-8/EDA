#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int x ;
    int y ;
    int dist ;
};

vector<vector<char>> read_map(int n, int m) {

    vector<vector<char>> result(n, vector<char>(m)) ;

    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) cin >> result[i][j] ;
    }
    return result ;
}

int BFS(const vector<vector<char>>& map, int f, int c) {

    if (map[f][c] == 't') return 0 ;
    else {
        const vector<int> directions = {-1, 0, 1, 0, -1} ;
        vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false)) ;
        queue<Node> q ;
        int min_dist = 0 ;
        q.push({f, c, min_dist}) ;
        visited[f][c] = true ;

        while (not q.empty()) {
            Node node = q.front() ;
            q.pop() ;
            visited[node.x][node.y] = true ;

            for (int i = 0 ; i < 4 ; ++i) {
                int x = node.x + directions[i] ;
                int y = node.y + directions[i + 1] ;

                if (0 <= x and x < map.size() and 0 <= y and y < map[0].size() and not visited[x][y] and map[x][y] != 'X') {
                    if (map[x][y] == 't') return node.dist + 1 ;
                    q.push({x, y, node.dist + 1}) ; 
                }
            }
        }
        return -1 ;
    }
}

int main () {

    int n , m ;
    cin >> n >> m ;
    vector<vector<char>> map = read_map(n, m) ;
    int f , c ;
    cin >> f >> c ;
    int min_dist = BFS(map, --f, --c) ;

    if (min_dist != -1) cout << "distancia minima: " << min_dist ;
    else cout << "no es pot arribar a cap tresor" ;
    cout << endl ;
}