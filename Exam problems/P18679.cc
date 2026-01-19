#include <iostream>
#include <vector>
using namespace std;

void BackTrack(int i, int pos, int m, int n, const vector<int>& l) {

    if (pos >= -m/2 and pos <= m/2) {
        if (i == n) cout << pos << endl ;
        else {
            BackTrack(i + 1, pos + l[i], m, n, l) ;
            BackTrack(i + 1, pos - l[i], m, n, l) ;
        }
    }
}

int main () {

    int m , n ;
    cin >> m >> n ;
    vector<int> l(n) ;

    for (int i = 0 ; i < n ; ++i) cin >> l[i] ;
    BackTrack(0, 0, m, n, l) ;
}