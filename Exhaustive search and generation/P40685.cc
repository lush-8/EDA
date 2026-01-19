#include <iostream>
#include <vector>
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

void BackTrack(int i, int sum, int s, vector<bool>& sol, vector<int>& values) {

    if (i == values.size()) {
        if (sum == s) Write(sol, values) ;
    }
    else {
        sol.push_back(true) ;
        BackTrack(i + 1, sum + values[i], s, sol, values) ;
        sol.back() = false ;
        BackTrack(i + 1, sum, s, sol, values) ;
        sol.pop_back() ;
    }
}

int main () {

    int s , n ;
    cin >> s >> n ;
    vector<int> values(n) ;

    for (int i = 0 ; i < n ; ++i) cin >> values[i] ;
    vector<bool> sol ;
    BackTrack(0, 0, s, sol, values) ;
}