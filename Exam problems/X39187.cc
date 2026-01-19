#include <iostream>
using namespace std;

void BackTrack(string& sol, int n, int c, int a) {

    if (sol.size() == n) cout << sol << endl ;
    else {
        if (c) {
            sol.push_back('b') ;
            BackTrack(sol, n, c - 1, a + 1) ; 
            sol.pop_back() ;
        }
        if (a) {
            sol.push_back('s') ;
            BackTrack(sol, n, c + 1, a - 1) ;
            sol.pop_back() ;
        }
    }
}

int main () {

    int n , c ;
    cin >> n >> c ;
    string sol ;
    BackTrack(sol, n, c, 0) ;
}