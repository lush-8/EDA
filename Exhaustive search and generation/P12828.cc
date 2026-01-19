#include <iostream>
#include <vector>
using namespace std;

void Write(const vector<int>& v) {

    for (int i = 0 ; i < v.size() ; ++i) {
        if (not i) cout << v[i] ;
        else cout << ' ' << v[i] ;
    }
    cout << endl ;
}

void BackTrack(int n, vector<int>& v) {

    if (v.size() == n) Write(v) ;  
    else {
        v.push_back(0) ;
        BackTrack(n, v) ;
        v.pop_back() ;
        v.push_back(1) ;
        BackTrack(n, v) ;
        v.pop_back() ;
    }
}

int main () {

    int n ;
    cin >> n ;
    vector<int> v ;
    BackTrack(n, v) ;
}