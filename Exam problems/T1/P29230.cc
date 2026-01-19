#include <iostream>
#include <vector>
using namespace std;

const vector<int> coins{50, 20, 10, 5, 2, 1} ;

void Write(const vector<int>& v) {

    for (int i = 0 ; i < v.size() ; ++i) {
        if (i != 0) cout << ' ' ;
        cout << v[i] ;
    }
    cout << endl ;
}

void BackTrack(int first, int sum, vector<int>& sol, int n) {

    if (sum == n) Write(sol) ;
    else for (int i = first ; i < coins.size() ; ++i) {
        if (sum + coins[i] > n) continue ;
        sol.push_back(coins[i]) ;
        BackTrack(i, sum + coins[i], sol, n) ;
        sol.pop_back() ;
    }
}

int main () {

    int n ;

    while (cin >> n) {
        vector<int> sol ;
        BackTrack(0, 0, sol, n) ;
        cout << endl ;
    }
}