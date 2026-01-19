#include <iostream>
#include <vector>
using namespace std;

bool is_Cyclic(const vector<vector<int>>& graph, vector<int>& inDegree) {

    int n = graph.size() ;
    vector<int> v ;

    for (int i = 0 ; i < n ; ++i) {
        if (inDegree[i] == 0) v.push_back(i) ;
    }
    while (not v.empty()) {
        int node = v.back() ;
        v.pop_back() ;
        --n ;

        for (int neighbour : graph[node]) {
            --inDegree[neighbour] ;

            if (inDegree[neighbour] == 0) v.push_back(neighbour) ;
        }
    }
    return n ;
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
        cout << (is_Cyclic(graph, inDegree) ? "yes" : "no") << endl ;
    }
}