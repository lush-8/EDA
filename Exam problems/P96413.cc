#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

const int UND = -1 ;

int main () {

    int n , t ;

    while (cin >> n >> t) {
        vector<unordered_set<int>> graph(n) ;

        while (--t >= 0) {
            int s ;
            cin >> s ;
            vector<int> pub(s) ;

            for (int i = 0 ; i < s ; ++i) cin >> pub[i] ;
            for (int i = 0 ; i < s ; ++i) {
                for (int j = i + 1 ; j < s ; ++j) {
                    int u = pub[i] ;
                    int v = pub[j] ;
                    graph[u].insert(v) ;
                    graph[v].insert(u) ;
                }
            }
        }
        vector<int> dist(n, UND) ;
        queue<int> q ;
        dist[0] = 0 ;
        q.push(0) ;

        while (not q.empty()) {
            int node = q.front() ;
            q.pop() ;

            for (int neighbour : graph[node]) {
                if (dist[neighbour] == UND) {
                    dist[neighbour] = dist[node] + 1 ;                        
                    q.push(neighbour) ;
                }
            }
        }
        for (int node = 0 ; node < n ; ++node) {
            cout << node << " : " ;

            if (dist[node] == UND) cout << "no" ;
            else cout << dist[node] ;
            cout << endl ;
        } 
        cout << string(10, '-') << endl ;
    }
}