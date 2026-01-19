#include <iostream>
#include <vector>
using namespace std;

void BackTrack(string& s, int n, int a, int b) {

    if (s.size() == n and abs(a - b) <= 2) cout << s << endl ;
    else {
        if (abs(a - b) <= 2) {
            s.push_back('a') ;
            BackTrack(s, n, a + 1, b) ;
            s.pop_back() ;
            s.push_back('b') ;
            BackTrack(s, n, a, b + 1) ;
            s.pop_back() ;
        }
    }
}

int main () {

    int n ;
    cin >> n ;
    string s ;
    BackTrack(s, n, 0, 0) ;
}