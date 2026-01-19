#include <iostream>
#include <vector>
using namespace std;

void Write(int f, int c, const vector<int>& columns) {

    for (int i = 0 ; i < f ; ++i) {
        for (int j = 0 ; j < c ; ++j) {
            if (columns[i] == j) cout << 'R' ;
            else cout << '.' ;
        }
        cout << endl ;
    }
    cout << endl ;
}

void BackTrack(int i, int f, int c, vector<int>& columns, vector<bool>& marked) {

    if (i == f) Write(f, c, columns) ;
    else for (int j = 0 ; j < c ; ++j) {
        if (not marked[j]) {
            columns[i] = j ;
            marked[j] = true ;
            BackTrack(i + 1, f, c, columns, marked) ;
            marked[j] = false ;
        }
    }
}

void Rook(int f, int c) {

    vector<int> columns(f) ;
    vector<bool> marked(c, false) ;
    BackTrack(0, f, c, columns, marked) ;
}

int main () {

    int f , c ;
    cin >> f >> c ;
    Rook(f, c) ;
}