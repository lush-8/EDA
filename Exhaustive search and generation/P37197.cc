#include <iostream>
#include <vector>
using namespace std;

void BackTrack(string& s, vector<bool>& used, vector<vector<bool>>& graph, vector<char>& v) {

    if (s.size() == v.size()) cout << s << endl ;
    else for (int i = 0 ; i < v.size() ; ++i) {
        char c = v[i] ;

        if (not used[c] and (s.empty() or graph[s.back()][c])) {
            used[c] = true ;
            s.push_back(c) ;
            BackTrack(s, used, graph, v) ;
            s.pop_back() ;
            used[c] = false ;
        }
    }
}

int main () {

    int n ;
    cin >> n ;
    vector<char> v(n) ;

    for (int i = 0 ; i < n ; ++i) cin >> v[i] ;
    int m ;
    cin >> m ;
    vector<vector<bool>> graph(256, vector<bool>(256, true)) ;

    for (int i = 0 ; i < m ; ++i) {
        char u , v ;
        cin >> u >> v ;
        graph[u][v] = graph[v][u] = false ;
    }
    string s ;
    vector<bool> used(256, false) ;
    BackTrack(s, used, graph, v) ;
}