#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Write_path(const vector<int>& parent, int xi, int xf) {

    if (xf == xi) cout << xi ;
    else {
        Write_path(parent, xi, parent[xf]) ;
        cout << ' ' << xf ;
    }
}

void BFS(const vector<vector<int>>& graph, int from, int to) {

    int n = graph.size() ;
    vector<int> parent(n, -1) ;
    vector<bool> visited(n, false) ;
    vector<int> current ;
    vector<int> pos ;
    current.push_back(from) ;
    visited[from] = true ;

    while (not current.empty()) {
        for (int x : current) {
            if (x == to) {
                Write_path(parent, from, to) ;
                cout << endl ;
                return ;
            }
            for (int y : graph[x]) {
                if (not visited[y]) {
                    pos.push_back(y) ;
                    visited[y] = true ;
                    parent[y] = x ;
                }
            }
        }
        swap(pos, current) ;
    }
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<int>> graph(n) ;

        for (int i = 0 ; i < m ; ++i) {
            int x , y ;
            cin >> x >> y ;
            graph[x].push_back(y) ;
        }
        for (int x = 0 ; x < n ; ++x) sort(graph[x].begin(), graph[x].end()) ;
        BFS(graph, 0, n - 1) ;
    }
}