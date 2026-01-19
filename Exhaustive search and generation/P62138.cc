#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> graph ;

void Write(const vector<int>& v) {

    for (int i = 0 ; i < v.size() ; ++i) {
        if (i != 0) cout << ' ' ;
        cout << v[i] ;
    }
    cout << endl ;
}

void BackTrack(vector<int>& v, set<int>& s, vector<int>& inDegree, vector<bool>& used) {

    if (v.size() == graph.size()) Write(v) ;
    else {
        set<int> tmp = s ;

        for (int node : tmp) {
            if (not used[node]) {
                used[node] = true ;
                v.push_back(node) ;
                s.erase(node) ;

                for (int neighbour : graph[node]) {
                    --inDegree[neighbour] ;

                    if (inDegree[neighbour] == 0) s.insert(neighbour) ;
                }
                BackTrack(v, s, inDegree, used) ;
                used[node] = false ;
                v.pop_back() ;       
                s.insert(node) ;         

                for (int neighbour : graph[node]) {
                    if (inDegree[neighbour] == 0) s.erase(neighbour) ;
                    ++inDegree[neighbour] ;
                }
            }
        }
    }
}

int main () {

    int n , m ;
    cin >> n >> m ;
    graph = vector<vector<int>>(n) ;
    vector<int> inDegree(n, 0) ;

    for (int i = 0 ; i < m ; ++i) {
        int x , y ;
        cin >> x >> y ;
        graph[x].push_back(y) ;
        ++inDegree[y] ;
    }
    set<int> s ;

    for (int i = 0 ; i < n ; ++i) {
        if (inDegree[i] == 0) s.insert(i) ;
    }
    vector<int> v ;
    vector<bool> used(n, false) ;
    BackTrack(v, s, inDegree, used) ;
}