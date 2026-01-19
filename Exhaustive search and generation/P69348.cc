#include <iostream>
#include <vector>
using namespace std;

void Write(const vector<int>& v) {

    cout << '(' ;

    for (int i = 0 ; i < v.size() ; ++i) {
        if (not i) cout << v[i] ;
        else cout << ',' << v[i] ;
    }
    cout << ')' << endl ;
}

void BackTrack(int n, vector<int>& v, vector<bool>& used) {

    if (v.size() == n) Write(v) ;
    else for (int i = 1 ; i <= n ; ++i) {
        if (not used[i - 1]) {
            v.push_back(i) ;
            used[i - 1] = true ;                
            BackTrack(n, v, used) ;
            used[i - 1] = false ;
            v.pop_back() ;
        }
    }
}

int main () {

    int n ;
    cin >> n ;
    vector<int> v ;
    vector<bool> used(n) ;
    BackTrack(n, v, used) ;
}