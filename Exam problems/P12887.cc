#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int MST(const vector<vector<pair<int, int>>>& graph) {

    int n = graph.size() ;
    vector<int> dist(n, INT_MAX) ;
    vector<bool> used(n, false) ;
    int weight = 0 ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq ;
    dist[0] = 0 ;
    pq.push({0, 0}) ;

    while (not pq.empty()) {
        int cost = pq.top().first ;
        int node = pq.top().second ;
        pq.pop() ;

        if (used[node]) continue ; 
        used[node] = true ;
        weight += cost ;

        for (const pair<int, int>& p : graph[node]) {
            int next_cost = p.first ;
            int neighbour = p.second ;

            if (not used[neighbour] and next_cost < dist[neighbour]) {
                dist[neighbour] = next_cost ;
                pq.push({next_cost, neighbour}) ;
            }
        }
    }
    return weight ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<pair<int, int>>> graph(n) ;

        for (int i = 0 ; i < m ; ++i) {
            int u , v , w ;
            cin >> u >> v >> w ;
            graph[u - 1].push_back({w, v - 1}) ;
            graph[v - 1].push_back({w, u - 1}) ;
        }
        cout << MST(graph) << endl ;
    }
}