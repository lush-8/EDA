#include <iostream>
#include <vector>
using namespace std;

void Write(const vector<int>& v) {

    for (const int& n : v) cout << n ;
    cout << endl ;
}

void BackTrack(int i, bool consec, vector<int>& sol, vector<int>& v) {

    if (i == sol.size () and consec) Write(sol) ;
    else for (int r = 1 ; r <= 3 ; ++r) {
        if (v[r] and (not consec or i == 0 or sol[i - 1] != r)) {
            sol[i] = r ;
            --v[r] ;
            BackTrack(i + 1, consec or (i > 0 and sol[i - 1] == r), sol, v) ;
            ++v[r] ;
        }
    }
}

int main () {
    
    int n ;

    while (cin >> n) {
        vector<int> sol(3*n) ;
        vector<int> v(4,n) ;
        BackTrack(0, false, sol, v) ;
        cout << string(10, '*') << endl ;
    }
}