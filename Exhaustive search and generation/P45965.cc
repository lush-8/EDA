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

void BackTrack(int n, int z, int u, vector<int>& v, int max_u) {

    if (z + u == n) Write(v) ;  
    else {
        if (z < n - max_u) {
            v.push_back(0) ;
            BackTrack(n, z + 1, u, v, max_u) ;
            v.pop_back() ;
        }
        if (u < max_u) {
            v.push_back(1) ;
            BackTrack(n, z, u + 1, v, max_u) ;
            v.pop_back() ;
        }
    }
}

int main () {

    int n , u ;
    cin >> n >> u ;
    vector<int> v ;
    BackTrack(n, 0, 0, v, u) ;
}