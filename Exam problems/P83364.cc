#include <iostream>
#include <vector>
using namespace std;

void BackTrack(int curr, int n, const vector<int>& div) {

    if (n == 0) cout << curr << endl ;
    else for (int dig = 0 ; dig <= 9 ; ++dig) {
        int next = curr*10 + dig ;
        bool divisor = false ;

        for (int i = 0 ; not divisor and i < div.size() ; ++i) {
            divisor = (next%div[i] == 0) ;
        }
        if (not divisor) BackTrack(next, n - 1, div) ;
    }
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<int> div(m) ;

        for (int i = 0 ; i < m ; ++i) cin >> div[i] ;
        BackTrack(0, n, div) ;
        cout << string(10, '-') << endl ;
    }
}