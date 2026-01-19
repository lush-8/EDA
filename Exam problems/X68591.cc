#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int DFS(const vector<vector<int>>& graph, vector<bool>& visited, int u) {

    visited[u] = true ;
    int nodes = 1 ;

    for (const int& v : graph[u]) {
        if (not visited[v]) nodes += DFS(graph, visited, v) ;
    }
    return nodes ;
}

pair<int, int> calculate(const vector<vector<int>>& graph) {

    int n = graph.size() ;
    pair<int, int> result{INT_MAX, 0} ;
    vector<bool> visited(n, false) ;

    for (int u = 0 ; u < n ; ++u) {
        if (not visited[u]) {
            int size = DFS(graph, visited, u) ;
            result.first = min(result.first, size) ;
            result.second = max(result.second, size) ; 
        }
    }
    return result ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<int>> graph(n) ;

        for (int i = 0 ; i < m ; ++i) {
            int x , y ;
            cin >> x >> y ;
            graph[x].push_back(y) ;
            graph[y].push_back(x) ;
        }
        pair<int, int> result = calculate(graph) ;
        cout << result.first << ' ' << result.second << endl ;
    }
}