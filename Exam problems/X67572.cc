#include <iostream>
#include <vector>
using namespace std;

void write(const vector<string>& v) {

    for (const string& s : v) cout << s ;
    cout << endl ;
}

void BackTrack(vector<string>& result, int n, vector<string>& v, vector<bool>& used) {

    if (result.size() == n) write(result) ;
    else for (int i = 0 ; i < v.size() ; ++i) {
        if (not used[i] and (result.empty() or result.back().back() != v[i].front())) {
            result.push_back(v[i]) ;
            used[i] = true ;
            BackTrack(result, n, v, used) ;
            used[i] = false ;
            result.pop_back() ;
        }
    }
}

int main () {

    int n ;
    cin >> n ;
    vector<string> v(n) ;
    vector<string> result ;
    vector<bool> used(n) ;

    for (int i = 0 ; i < n ; ++i) cin >> v[i] ;
    BackTrack(result, n, v, used) ;
}