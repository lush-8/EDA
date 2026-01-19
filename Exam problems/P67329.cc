#include <iostream>
using namespace std;

void BackTrack(string& s, int n) {

    if (s.size() == n) cout << s << endl ;
    else {
        s.push_back('A') ;
        BackTrack(s, n) ;
        s.back() = 'C' ;
        BackTrack(s, n) ;
        s.back() = 'G' ;
        BackTrack(s, n) ;
        s.back() = 'T' ;
        BackTrack(s, n) ;
        s.pop_back() ;
    }
}

int main () {

    int n ;
    cin >> n ;
    string s ;
    BackTrack(s, n) ;
}