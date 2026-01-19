#include <iostream>
#include <vector>
using namespace std;

void Write(const vector<int>& v) {

    cout << '(' ;

    for (int i = 0 ; i < v.size() ; ++i) {
        if (i) cout << ',' ;
        cout << v[i] ;
    }
    cout << ')' << endl ;
}

bool compatible(int left, int mid, int right, int n) {

    return left + right <= 2*mid ;
}

void BackTrack(int n, vector<int>& sol, vector<bool>& used) {
    
    if (sol.size() == n) {
        Write(sol) ;
    }
    else for (int i = 1 ; i <= n ; ++i) {
        if (not used[i]) {
            if (sol.size() <= 1 or compatible(sol[sol.size() - 2], sol.back(), i, n)) {
                sol.push_back(i) ;
                used[i] = true ;
                BackTrack(n, sol, used) ;
                used[i] = false ;
                sol.pop_back() ;
            }
        }
    }
}

void BackTrack(int n) {

    vector<bool> used(n + 1, false) ;
    vector<int> sol ;
    BackTrack(n, sol, used) ;
}

int main () {
    
    int n ;
    cin >> n ;
    BackTrack(n) ;
}