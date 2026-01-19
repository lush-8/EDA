#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Write(const vector<int>& v) {

    for (int i = 0 ; i < v.size() ; ++i) {
        if (not i) cout << v[i] ;
        else cout << ' ' << v[i] ;
    }
    cout << endl ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<int>> graph(n) ;
        vector<int> inDegree(n, 0) ;

        for (int i = 0 ; i < m ; ++i) {
            int x , y ;
            cin >> x >> y ;
            graph[x].push_back(y) ;
            ++inDegree[y] ;
        }
        priority_queue<int, vector<int>, greater<int>> pq ;

        for (int i = 0 ; i < n ; ++i) {
            if (inDegree[i] == 0) pq.push(i) ;
        }
        vector<int> v ;

        while (not pq.empty()) {
            int node = pq.top() ;
            pq.pop() ;
            v.push_back(node) ;

            for (int neighbour : graph[node]) {
                --inDegree[neighbour] ;

                if (inDegree[neighbour] == 0) pq.push(neighbour) ;
            }
        }
        Write(v) ;
    }
}