#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(const vector<vector<int>>& graph) {

    int n = graph.size() ;
    int farthest = 0 ;
    vector<int> dist(n, -1) ;
    queue<int> q ;
    dist[0] = 0 ;
    q.push(0) ;

    while (not q.empty()) {
        int u = q.front() ;
        q.pop() ;

        for (const int& v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1 ;
                q.push(v) ;

                if (dist[farthest] < dist[v]) {
                    farthest = v ;
                }
                else if (dist[farthest] == dist[v] and v < farthest) {
                    farthest = v ;
                }
            }
        }
    }
    return farthest ;
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
        cout << BFS(graph) << endl ;
    }
}