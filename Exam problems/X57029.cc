#include <iostream>
using namespace std;

void BackTrack(string& s, int n, int y) {

    if (s.size() == n) cout << s << endl ;
    else {
        if (y != 0) {
            s.push_back('d') ;
            BackTrack(s, n, y - 1) ;
            s.pop_back() ;
        }
        s.push_back('h') ;
        BackTrack(s, n, y) ;
        s.pop_back() ;
        s.push_back('u') ;
        BackTrack(s, n, y + 1) ;
        s.pop_back() ;
    }
}

int main () {

    int n ;
    cin >> n ;
    string s ;
    BackTrack(s, n, 0) ;
}