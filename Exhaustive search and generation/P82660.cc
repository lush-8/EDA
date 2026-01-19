#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Write(const vector<bool>& sol, const vector<int>& values) {

    cout << '{' ;
    bool first = true ;

    for (int i = 0 ; i < sol.size() ; ++i) {
        if (sol[i]) {
            if (first) first = false ;
            else cout << ',' ;
            cout << values[i] ;
        }
    }
    cout << '}' << endl ;
}

bool BackTrack(int i, int sum, int s, vector<bool>& sol, vector<int>& values) {

    if (i == values.size()) {
        if (sum == s) {
            Write(sol, values) ;
            return true ;
        }
    }
    else {
        sol.push_back(true) ;

        if (BackTrack(i + 1, sum + values[i], s, sol, values)) return true ;
        sol.back() = false ;

        if (BackTrack(i + 1, sum, s, sol, values)) return true ;
        sol.pop_back() ;
    }
    return false ;
}

int main () {

    int s , n ;
    cin >> s >> n ;
    vector<int> values(n) ;

    for (int i = 0 ; i < n ; ++i) cin >> values[i] ;
    sort(values.rbegin(), values.rend()) ;
    vector<bool> sol ;
    
    if (not BackTrack(0, 0, s, sol, values)) cout << "no solution" << endl ;
}