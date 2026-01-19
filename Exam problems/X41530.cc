#include <iostream>
#include <vector>
using namespace std;

int Union_Find(vector<int>& parents, int node) {

    if (parents[node] != node) parents[node] = Union_Find(parents, parents[node]) ;
    return parents[node] ;
}

int main () {

    for (int n , m ; cin >> n >> m ; ) {
        vector<int> parents(n) ;

        for (int i = 0 ; i < n ; ++i) parents[i] = i ;
        bool forest = true ;
        int connected_components = n ;

        while (m) {
            int x , y ;
            cin >> x >> y ;

            if (forest) {
                int parent_X = Union_Find(parents, x) ;
                int parent_Y = Union_Find(parents, y) ;

                if (parent_X == parent_Y) forest = false ;
                else {
                    parents[parent_X] = parents[x] = parent_Y ;
                    --connected_components ;
                } 
            }
            --m ;
        }
        if (forest) cout << connected_components << endl ;
        else cout << "no" << endl ;
    }
}

/*
bool DFS(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
    
    visited[node] = true ;

    for (int neighbour : graph[node]) {
        if (not visited[neighbour]) {
            if (not DFS(neighbour, node, graph, visited)) return false ; 
        } 
        else if (neighbour != parent) return false ; 
    }
    return true ;
}

int main () {

    for (int n , m ; cin >> n >> m ; ) {
        vector<vector<int>> graph(n) ; 
        vector<bool> visited(n, false) ;
        bool forest = true ;
        int connected_components = 0 ;

        while (m) {
            int x , y ;
            cin >> x >> y ;
            graph[x].push_back(y) ;
            graph[y].push_back(x) ;
            --m ;
        }
        for (int i = 0 ; i < n and forest ; ++i) {
            if (not visited[i]) {
                ++connected_components ;

                if (not DFS(i, -1, graph, visited)) {
                    forest = false ;
                }
            }
        }
        if (forest) cout << connected_components << endl ;
        else cout << "no" << endl ;
    }
}
*/