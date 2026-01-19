#include <iostream>
#include <vector>
using namespace std;

void Write(const vector<vector<string>>& v) {

    for (int i = 0 ; i < v.size() ; ++i) {
        cout << "subconjunt " << i + 1 << ": {" ;

        for (int j = 0 ; j < v[i].size() ; ++j) {
            if (j != 0) cout << ',' ;
            cout << v[i][j] ;
        }
        cout << '}' << endl ;
    }
    cout << endl ;
}

void BackTrack(int idx, const vector<string>& words, vector<vector<string>>& v) {

    if (idx == words.size()) Write(v) ;
    else {
        for (int i = 0 ; i < v.size() ; ++i) {
            v[i].push_back(words[idx]) ;
            BackTrack(idx + 1, words, v) ;
            v[i].pop_back() ;
        }
    }
}

int main () {

    int n ;
    cin >> n ;
    vector<string> words(n) ;

    for (int i = 0 ; i < n ; ++i) cin >> words[i] ;
    int p ;
    cin >> p ;
    vector<vector<string>> v(p) ;
    BackTrack(0, words, v) ;
}