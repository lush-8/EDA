#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const int INF = numeric_limits<int>::max() ;

void nJumps(const vector<vector<int>>& G, int s, int t) {

    int n = G.size() ;
    vector<vector<int>> dist(2, vector<int>(n, INF)) ;
    queue<pair<int, int>> Q ;
    dist[0][s] = 0 ;
    Q.push({0, s}) ;

    while (not Q.empty()) {
        pair<int, int> p = Q.front() ;
        Q.pop() ;
        int par = p.first ;
        int x = p.second ;
        int par2 = not par ;

        for (int y : G[x]) {
            if (dist[par2][y] == INF) {
                dist[par2][y] = dist[par][x] + 1 ;
                Q.push({par2, y}) ;

                if (y == t and not par2) {
                    cout << dist[0][y]/2 << endl ;
                    return ;
                }
            }
        }
    }
    cout << "NO" << endl ;
}

int main () {

    int m , n , s , t ;

    while (cin >> n >> m >> s >> t) {
        vector<vector<int>> G = vector<vector<int>>(n) ;
        
        while (m) {
            int x , y ;
            cin >> x >> y ;
            G[x].push_back(y) ;
            G[y].push_back(x) ;
            --m ;
        }
        nJumps(G, s, t) ;
    }
}