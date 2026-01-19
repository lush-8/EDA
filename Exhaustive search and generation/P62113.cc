#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void write_solution(const int& x, const vector<int>& v, const vector<bool>& used) {

    cout << x << " = " ;
    bool first = true ;

    for (int i = 0 ; i < used.size() ; ++i) {
        if (used[i]) {
            if (first) first = false ;
            else cout << " + " ;
            cout << v[i] ;

            if (i%2) cout << 'p' ; 
        }
    }
    cout << endl ;
}

void BackTrack(int i, int x, int sum, int n, vector<int>& v, vector<bool>& used) {

    if (sum > x or i > 2*n) return ;
    if (sum == x) write_solution(x, v, used) ;
    else {
        used[i] = true ;
        BackTrack(i + 1, x, sum + v[i], n, v, used) ;
        used[i] = false ;
        BackTrack(i + 1, x, sum, n, v, used) ;
    }
}

int main () {

    int x , n ;

    while (cin >> x >> n) {
        vector<int> v ;

        for (int i = 0 ; i < n ; ++i) {
            int val ;
            cin >> val ;
            v.push_back(val) ;
            v.push_back(val) ;
        }
        sort(v.begin(), v.end()) ;
        vector<bool> used(2*n, false) ;
        BackTrack(0, x, 0, n, v, used) ;
        cout << string(10, '-') << endl ;
    }
}