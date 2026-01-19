#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int Dijkstra(const vector<vector<pair<int, int>>>& graph, int from, int to) {
    
    int n = graph.size() ;
    vector<int> dist(n, INT_MAX) ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
    dist[from] = 0 ;
    pq.push({0, from}) ;

    while (not pq.empty()) {
        int cost = pq.top().first ;
        int node = pq.top().second ;
        pq.pop() ;

        if (node == to) break ;
        if (cost > dist[node]) continue ;
        for (const pair<int, int>& p : graph[node]) {
            int neighbour = p.first ;
            int next_cost = cost + p.second ;

            if (next_cost < dist[neighbour]) {
                dist[neighbour] = next_cost ;
                pq.push({next_cost, neighbour}) ;
            }
        }
    }
    return dist[to] != INT_MAX ? dist[to] : -1 ;
}

int main () {

    int n , m ;
    
    while (cin >> n >> m) {
        vector<vector<pair<int, int>>> graph(n) ;

        for (int i = 0 ; i < m ; ++i) {
            int u , v , c ;
            cin >> u >> v >> c ;
            graph[u].push_back({v, c}) ; 
        }
        int x , y ;
        cin >> x >> y ;
        int min_cost = Dijkstra(graph, x, y) ;

        if (min_cost != -1) cout << min_cost ;
        else cout << "no path from " << x << " to " << y ;
        cout << endl ; 
    }
}