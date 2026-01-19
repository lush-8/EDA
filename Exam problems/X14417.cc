#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}} ;

pair<int, int> position(const vector<vector<string>>& mat, const string& s) {

    for (int i = 0 ; i < mat.size() ; ++i) {
        for (int j = 0 ; j < mat[0].size() ; ++j) {
            if (mat[i][j] == s) return {i, j} ;
        }
    }
    return {-1, -1} ;
}

bool valid_pos(const vector<vector<string>>& mat, const pair<int, int>& p) {

    return 0 <= p.first and p.first < mat.size() and 0 <= p.second and p.second < mat[0].size() and mat[p.first][p.second] != "*" ; 
}

int BFS(const vector<vector<string>>& mat, pair<int, int>& from, pair<int, int>& to) {

    int n = mat.size() ;
    int m = mat[0].size() ;
    vector<vector<int>> dist(n, vector<int>(m, -1)) ;
    queue<pair<int, int>> q ;
    q.push(from) ;
    dist[from.first][from.second] = 0 ;

    while (not q.empty()) {
        pair<int, int> p = q.front() ;
        q.pop() ;

        if (p == to) return dist[p.first][p.second] ;
        for (const pair<int, int>& d : dirs) {
            pair<int, int> next = p ;
            next.first += d.first ;
            next.second += d.second ;

            if (valid_pos(mat, next) and dist[next.first][next.second] == -1) {
                q.push(next) ;
                dist[next.first][next.second] = dist[p.first][p.second] + 1 ;
            }
        }
    }
    return -1 ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<string>> mat(n, vector<string>(m)) ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                cin >> mat[i][j] ;
            }
        }
        int p ;
        cin >> p ;
        vector<string> words(p) ;

        for (int i = 0 ; i < p ; ++i) cin >> words[i] ;
        vector<pair<int, int>> positions(p + 1) ;
        positions[0] = {0, 0} ;

        for (int i = 0 ; i < p ; ++i) {
            positions[i + 1] = position(mat, words[i]) ;
        }
        int total = 0 ;
        bool ok = true ;

        for (int i = 0 ; ok and i < positions.size() - 1 ; ++i) {
            int d = BFS(mat, positions[i], positions[i + 1]) ;

            if (d == -1) ok = false ;
            else total += d ;
        }
        if (ok) cout << total + p << endl ;
        else cout << "impossible" << endl ;
    }
}