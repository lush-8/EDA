#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_Vowel(const char& c) {

    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' ;
}

void BackTrack(string& s, const vector<char>& letters, int n) {

    if (s.size() == n) cout << s << endl ;
    else for (const char& c : letters) {
        if (not is_Vowel(c) or s.empty() or not is_Vowel(s.back())) {
            s.push_back(c) ;
            BackTrack(s, letters, n) ;
            s.pop_back() ;
        }
    }
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<char> letters(m) ;

        for (int i = 0 ; i < m ; ++i) cin >> letters[i] ;
        sort(letters.begin(), letters.end()) ;
        string s ;
        BackTrack(s, letters, n) ;
        cout << string(10, '-') << endl ;
    }
}