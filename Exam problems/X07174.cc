#include <iostream>
#include <vector>
using namespace std;

bool ok(int y, const vector<int>& div) {

    for (int i = 0 ; i < div.size() ; ++i) {
        if (y%div[i] == 0) return false ;
    }
    return true ;
}

void BackTrack(int i, int x, const vector<int>& div, int n) {

    if (i == n) cout << x << endl ;
    else {
        for (int v = 0 ; v <= 9 ; ++v) {
            int y = 10*x + v ;

            if (ok(y, div)) BackTrack(i + 1, y, div, n) ;
        }
    }
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<int> div(m) ;

        for (int i = 0 ; i < m ; ++i) {
            cin >> div[i] ;
        }
        BackTrack(0, 0, div, n) ;
        cout << string(10, '-') << endl ;
    }
}