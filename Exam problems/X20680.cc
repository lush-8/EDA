#include <iostream>
using namespace std;

const string letters = "xyz" ;

void BackTrack(int consec, int n, int c, string& s) {

    if (s.size() == n) cout << s << endl ;
    else for (int i = 0 ; i < letters.size() ; ++i) {
        bool repeated = (s.size() and s.back() == letters[i]) ;
        int new_consec = (repeated ? consec + 1 : 1) ;

        if (new_consec <= c) {
            s.push_back(letters[i]) ;
            BackTrack(new_consec, n, c, s) ;
            s.pop_back() ;
        }
    }
}

int main () {

    int n , c ;

    while (cin >> n >> c) {
        string s ;
        BackTrack(0, n, c, s) ;
        cout << string(20, '-') << endl ;
    }
}