#include <iostream>
#include <vector>
using namespace std;

void Write(const vector<int>& v) {

    cout << '(' ;

    for (int i = 0 ; i < v.size() ; ++i) {
        if (i != 0) cout << ',' ;
        cout << v[i] ;
    }
    cout << ')' << endl ;
}

void BackTrack(vector<int>& v, int n, int d, vector<bool>& used) {

    if (v.size() == n) Write(v) ;
    else {
        for (int i = 1 ; i <= n ; ++i) {
            if (not used[i] and (v.empty() or abs(v.back() - i) <= d)) {
                v.push_back(i) ;
                used[i] = true ;
                BackTrack(v, n, d, used) ;
                used[i] = false ;
                v.pop_back() ;
            }
        }
    }
}

int main () {

    int n , d ;
    cin >> n >> d ;
    vector<int> v ;
    vector<bool> used(n, false) ;
    BackTrack(v, n, d, used) ;
}