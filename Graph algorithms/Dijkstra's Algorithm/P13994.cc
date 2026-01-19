#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void Dijkstra(const vector<vector<pair<int, int>>>& graph, int from, int to) {

    int n = graph.size() ;
    vector<int> dist(n, INT_MAX) ;
    vector<int> prev(n, -1) ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq ;
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
                prev[neighbour] = node ;
                pq.push({next_cost, neighbour}) ;
            }
        }
    }
    if (dist[to] == INT_MAX) cout << "no path from " << from << " to " << to << endl ;
    else {
        vector<int> path ;

        for (int node = to ; node != -1 ; node = prev[node]) path.push_back(node) ;
        while (not path.empty()) {
            cout << path.back() ;
            path.pop_back() ;

            if (not path.empty()) cout << ' ' ;
        }
        cout << endl ;
    }
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