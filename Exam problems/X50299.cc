#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int Dijkstra(const vector<vector<pair<int, int>>>& graph, int x , int y) {

    int n = graph.size() ;
    vector<int> dist(n, INT_MAX) ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
    dist[x] = 0 ;
    pq.push({0, x}) ;

    while (not pq.empty()) {
        int d = pq.top().first ;
        int u = pq.top().second ;
        pq.pop() ;

        if (u == y) return dist[y] ;
        if (d == dist[u]) {
            for (const pair<int, int>& e : graph[u]) {
                int l = e.first ;
                int v = e.second ;
                int d2 = max(dist[u], l) ;

                if (d2 < dist[v]) {
                    dist[v] = d2 ;
                    pq.push({d2, v}) ;
                }
            }
        }
    }
    return INT_MAX ;
}

int main () {

    int n , m ;
    
    while (cin >> n >> m) {
        vector<vector<pair<int, int>>> graph(n) ;

        while (--m >= 0) {
            int x , y , l ;
            cin >> x >> y >> l ;
            graph[x].push_back({l, y}) ;
        }
        cout << Dijkstra(graph, 0, 1) << endl ;
    }
}