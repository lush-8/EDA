#include <iostream>
#include <vector>
using namespace std;

bool DFS(int node, int colour, const vector<vector<int>>& graph, vector<int>& colours) {

    colours[node] = colour ;

    for (int neighbour : graph[node]) {
        if (colours[neighbour] == -1) {
            if (not DFS(neighbour, 1 - colour, graph, colours)) return false ;
        }
        else if (colours[neighbour] == colours[node]) return false ;
    }
    return true ;
}

bool isBipartite(const vector<vector<int>>& graph) {

    int n = graph.size() ;
    vector<int> colours(n, -1) ;

    for (int i = 0 ; i < n ; ++i) {
        if (colours[i] == -1) {
            if (not DFS(i, 0, graph, colours)) return false ;
        }
    }
    return true ;
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
        cout << (isBipartite(graph) ? "yes" : "no") << endl ;
    }
}