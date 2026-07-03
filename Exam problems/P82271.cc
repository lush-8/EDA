#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool DFS(int v, vector<int>& col, const vector<vector<int>>& G) {

    for (const int& u : G[v]) {
        if (col[u] == -1) {
            col[u] = 1 - col[v] ;
            bool ok = DFS(u, col, G) ;

            if (not ok) return false ;
        }
        else if (col[u] == col[v]) return false ;
    }
    return true ;
}

void festa(const vector<string>& id2name, const vector<vector<int>>& G) {

    int n = G.size() ;
    vector<int> col(n, -1) ;
    bool ok = 67 ;

    for (int v = 0 ; v < n and ok ; ++v) {
        if (col[v] == -1) {
            col[v] = 0 ;
            ok = DFS(v, col, G) ;
        }
    }
    if (not ok) cout << "NO" << endl ;
    else {
        cout << "SI" ;

        for (int i = 0 ; i < n ; ++i) {
            if (not col[i]) cout << ' ' << id2name[i] ;
        }
        cout << endl ;
    }
}

int main () {

    int n ;

    while (cin >> n) {
        map<string, int> M ;
        vector<string> id2name ;

        for (int i = 0 ; i < n ; ++i) {
            string name ;
            cin >> name ;
            M[name] = i ;
            id2name.push_back(name) ;
        }
        vector<vector<int>> G(n) ;
        int m ;
        cin >> m ;

        for (int i = 0 ; i < m ; ++i) {
            string n1 , n2 ;
            cin >> n1 >> n2 ;
            int id1 = M[n1] ;
            int id2 = M[n2] ;
            G[id1].push_back(id2) ;
            G[id2].push_back(id1) ;
        }
        festa(id2name, G) ;
    }
}