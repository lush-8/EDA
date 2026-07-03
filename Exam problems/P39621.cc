#include <iostream>
#include <vector>
using namespace std;

const vector<pair<int, int>> dirs = {{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}} ;

bool ok(int i, int j, const vector<vector<int>>& M) {

    int n = M.size() ;
    int m = M[0].size() ;
    return 0 <= i and i < n and 0 <= j and j < m ;
}

int monedes(const vector<vector<int>>& M, vector<vector<bool>>& sol, int i, int j, int monedes_actuals) {

    if (i == M.size()) return monedes_actuals ;
    if (j == M[0].size()) return monedes(M, sol, i + 1, 0, monedes_actuals) ;
    bool possible = true ;

    for (const auto& d : dirs) {
        int ni = i + d.first ;
        int nj = j + d.second ;

        if (ok(ni, nj, M) and sol[ni][nj]) {
            possible = false ;
            break ;
        }
    }
    sol[i][j] = false ;
    int possib_1 = monedes(M, sol, i, j + 1, monedes_actuals) ;
    int possib_2 = 0 ;

    if (possible) {
        sol[i][j] = true ;
        possib_2 = monedes(M, sol, i, j + 1, monedes_actuals + M[i][j]) ;
    }
    return max(possib_1, possib_2) ;
}

int monedes(const vector<vector<int>>& M) {

    vector<vector<bool>> sol(M.size(), vector<bool>(M[0].size())) ;
    int i = 0 ;
    int j = 0 ;
    int monedes_actuals = 0 ;
    return monedes(M, sol, i, j, monedes_actuals) ;
}

int main () {

    int n , m ;
    
    while (cin >> n >> m) {
        vector<vector<int>> M(n, vector<int>(m)) ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                cin >> M[i][j] ;
            }
        }
        cout << monedes(M) << endl ;
    }
}