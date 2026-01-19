#include <iostream>
#include <vector>
using namespace std;

int BackTrack(int i, int n, vector<bool>& columns, vector<bool>& diag, vector<bool>& antidiag) {

    if (i == n) return 1 ;
    int ways = 0 ;
    
    for (int j = 0 ; j < n ; ++j) {
        if (not columns[j] and not diag[i + j] and not antidiag[n - i + j]) {
            columns[j] = diag[i + j] = antidiag[n - i + j] = true ;
            ways += BackTrack(i + 1, n, columns, diag, antidiag) ;
            columns[j] = diag[i + j] = antidiag[n - i + j] = false ;
        }
    }
    return ways ;
}

int Queens(int n) {

    vector<bool> columns(n, 0) ;
    vector<bool> diag(2*n, 0) ;
    vector<bool> antidiag(2*n, 0) ;
    return BackTrack(0, n, columns, diag, antidiag) ;
}

int main () {

    int n ;
    cin >> n ;
    cout << Queens(n) << endl ;
}