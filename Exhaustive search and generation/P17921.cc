#include <iostream>
#include <vector>
using namespace std;

void Write(const int& n, const vector<int>& queens) {

    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < n ; ++j) {
            if (queens[i] == j) cout << 'Q' ;
            else cout << '.' ;
        }
        cout << endl ;
    }
    cout << endl ;
}

void BackTrack(int i, int n, vector<int>& queens, vector<bool>& columns, vector<bool>& diag, vector<bool>& antidiag) {

    if (i == n) Write(n, queens) ;
    for (int j = 0 ; j < n ; ++j) {
        if (not columns[j] and not diag[i + j] and not antidiag[n - i + j]) {
            queens[i] = j ;
            columns[j] = diag[i + j] = antidiag[n - i + j] = true ;
            BackTrack(i + 1, n, queens, columns, diag, antidiag) ;
            columns[j] = diag[i + j] = antidiag[n - i + j] = false ;
        }
    }
}

void Queens(int n) {

    vector<int> queens(n, -1) ;
    vector<bool> columns(n, false) ;
    vector<bool> diag(2*n, false) ;
    vector<bool> antidiag(2*n, false) ;
    BackTrack(0, n, queens, columns, diag, antidiag) ;
}

int main () {

    int n ;
    cin >> n ;
    Queens(n) ;
}