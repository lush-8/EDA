#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int oo = INT_MAX ;

int Dijkstra(const vector<vector<pair<int, int>>>& graph, const vector<int>& costs, int a, int b) {

    int n = graph.size() ;
    vector<int> dist(n, +oo) ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
    dist[a] = 0 ;
    pq.push({0, a}) ;

    while (not pq.empty()) {
        pair<int, int> p = pq.top() ;
        pq.pop() ;
        int d = p.first ;
        int u = p.second ;

        if (d == dist[u]) {
            if (u == b) return dist[b] ;
            for (const pair<int, int>& e : graph[u]) {
                int v = e.first ;
                int w = e.second ;
                int dv = dist[u] + w + (v == b ? 0 : costs[v]) ;

                if (dv < dist[v]) {
                    dist[v] = dv ;
                    pq.push({dv, v}) ;
                }
            }
        }
    }
    return +oo ;
}

int main () {

    int n , m ;
    cin >> n >> m ;
    vector<int> costs(n) ;

    for (int i = 0 ; i < n ; ++i) cin >> costs[i] ;
    vector<vector<pair<int, int>>> graph(n) ;

    while (--m >= 0) {
        int u , v , w ;
        cin >> u >> v >> w ;
        graph[u].push_back({v, w}) ;
        graph[v].push_back({u, w}) ;
    }
    int a , b ;

    while (cin >> a >> b) {
        int c = Dijkstra(graph, costs, a, b) ;
        cout << "c(" << a << ',' << b << ") = " ;

        if (c == +oo) cout << "+oo" ;
        else cout << c ;
        cout << endl ;
    }
}