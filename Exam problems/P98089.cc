#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int best_cost ;
vector<int> best_sol ;

void BackTrack(int idx, int cost, vector<int>& sol, vector<bool>& used, const vector<vector<int>>& mat) {

    if (cost >= best_cost) return ;
    int n = sol.size() ;

    if (idx == n) {
        if (cost < best_cost) {
            best_cost = cost ;
            best_sol = sol ;
        }
    }
    else for (int i = 1 ; i < n ; ++i) {
        if (not used[i]) {
            sol[idx] = i ;
            used[i] = true ;
            BackTrack(idx + 1, cost + mat[sol[idx - 1]][i], sol, used, mat) ;
            used[i] = false ;
        }
    }
}

int main () {

    int n ;

    while (cin >> n) {
        vector<string> people(n) ;

        for (int i = 0 ; i < n ; ++i) cin >> people[i] ;
        vector<vector<int>> mat(n, vector<int>(n)) ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < n ; ++j) cin >> mat[i][j] ;
        }
        vector<int> sol(n) ;
        vector<bool> used(n, false) ;
        best_cost = INT_MAX ;
        sol[0] = 0 ;
        used[0] = true ;
        BackTrack(1, 0, sol, used, mat) ;
        cout << best_cost << endl ;
        
        for (int i = 0 ; i < n ; ++i) cout << (i ? " " : "") << people[best_sol[i]] ;
        cout << endl ;
    }
}