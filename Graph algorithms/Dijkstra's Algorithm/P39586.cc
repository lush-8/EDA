#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void Dijkstra(const vector<vector<pair<int, int>>>& graph, int from, int to) {

    int n = graph.size() ;
    vector<int> dist(n, INT_MAX) ;
    vector<int> ways(n, 0) ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
    dist[from] = 0 ;
    ways[from] = 1 ;
    pq.push({0, from}) ;

    while (not pq.empty()) {
        int cost = pq.top().first ;
        int node = pq.top().second ;
        pq.pop() ;

        if (cost > dist[node]) continue ;
        for (const pair<int, int>& p : graph[node]) {
            int neighbour = p.first ;
            int next_cost = p.second ;

            if (cost + next_cost < dist[neighbour]) {
                dist[neighbour] = cost + next_cost ;
                ways[neighbour] = ways[node] ;
                pq.push({dist[neighbour], neighbour}) ;
            }
            else if (cost + next_cost == dist[neighbour]) {
                ways[neighbour] += ways[node] ;
            }
        }     
    }
    if (dist[to] != INT_MAX) cout << "cost " << dist[to] << ", " << ways[to] << " way(s)" << endl ;
    else cout << "no path from " << from << " to " << to << endl ;
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
        Dijkstra(graph, x, y) ; 
    }
}