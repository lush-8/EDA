#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, const vector<vector<int>>& graph, vector<bool>& reach) {

    reach[node] = true ;

    for (const int& neighbour : graph[node]) {
        if (not reach[neighbour]) DFS(neighbour, graph, reach) ;
    }
}

int main () {

    int n , u , v , m ;

    while (cin >> n >> u >> v >> m) {
        vector<vector<int>> graph(n) ;
        vector<vector<int>> rev_graph(n) ;

        for (int i = 0 ; i < m ; ++i) {
            int x , y ;
            cin >> x >> y ;
            graph[x].push_back(y) ;
            rev_graph[y].push_back(x) ;
        }
        vector<bool> reachfrom(n, false) ;
        DFS(u, graph, reachfrom) ;

        if (not reachfrom[v]) cout << 0 << endl ;
        else {
            vector<bool> reachto(n, false) ;
            DFS(v, rev_graph, reachto) ;
            int count = 0 ;

            for (int i = 0 ; i < n ; ++i) {
                if (i != u and i != v) count += reachfrom[i] and reachto[i] ;
            }
            cout << count << endl ;
        }
    }
}