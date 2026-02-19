#include <iostream>
#include <vector>
using namespace std;

pair<int, int> vertices_edges(const vector<vector<int>>& G, int u, vector<bool>& vis) {

    pair<int, int> res = {0, 0} ;

    if (vis[u]) return res ;
    vis[u] = true ;
    ++res.first ;
    res.second += G[u].size() ;

    for (int v : G[u]) {
        pair<int, int> aux = vertices_edges(G, v, vis) ;
        res.first += aux.first ;
        res.second += aux.second ;
    }
    return res ;
}

bool allCliques(const vector<vector<int>>& G) {

    int n = G.size() ;
    vector<bool> vis(n, false) ;

    for (int u = 0 ; u < n ; ++u) {
        if (not vis[u]) {
            pair<int, int> res = vertices_edges(G, u, vis) ;
            int n_vertices = res.first ;
            int n_edges = res.second/2 ;
            
            if (n_edges != n_vertices*(n_vertices - 1)/2) return false ;
        }
    }
    return true ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<int>> G(n) ;

        for (int i = 0 ; i < m ; ++i) {
            int u , v ;
            cin >> u >> v ;
            G[u].push_back(v) ;
            G[v].push_back(u) ;
        }
        cout << (allCliques(G) ? "SI" : "NO") << endl ;
    }
}