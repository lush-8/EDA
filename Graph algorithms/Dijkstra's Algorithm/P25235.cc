#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void Dijkstra(const vector<vector<pair<int, int>>>& graph, int from, int to) {

    int n = graph.size() ;
    vector<int> dist(n, INT_MAX) ;
    vector<int> steps(n, -1) ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
    dist[from] = steps[from] = 0 ;
    pq.push({0, from}) ;

    while (not pq.empty()) {
        int cost = pq.top().first ;
        int node = pq.top().second ;
        pq.pop() ;
        
        if (node == to) break ;
        if (cost > dist[node]) continue ;
        for (const pair<int, int>& p : graph[node]) {
            int neighbour = p.first ;
            int next_cost = p.second ;

            if (cost + next_cost < dist[neighbour]) {
                dist[neighbour] = cost + next_cost ;
                steps[neighbour] = steps[node] + 1 ;                    
                pq.push({dist[neighbour], neighbour}) ;
            }
            else if (cost + next_cost == dist[neighbour] and steps[node] + 1 < steps[neighbour]) {
                steps[neighbour] = steps[node] + 1 ;
            }
        }
    }
    if (dist[to] != INT_MAX) {
        cout << "cost " << dist[to] << ", " << steps[to] << " step(s)" << endl ;
    }
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