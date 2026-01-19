#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void Write(const vector<string>& v) {

    cout << '(' ;

    for (int i = 0 ; i < v.size() ; ++i) {
        if (i != 0) cout << ',' ;
        cout << v[i] ;
    }
    cout << ')' << endl ;
}

bool used(const string& s, const unordered_set<string>& set) {

    return set.find(s) != set.end() ;
}

void BackTrack(const vector<string>& words, unordered_set<string>& s, vector<string>& v) {

    if (v.size() == words.size()) Write(v) ;
    else {
        for (int i = 0 ; i < words.size() ; ++i) {
            if (not used(words[i], s)) {
                v.push_back(words[i]) ;
                s.insert(words[i]) ;
                BackTrack(words, s, v) ;
                s.erase(words[i]) ;
                v.pop_back() ;
            }
        }
    }
}

int main () {

    int n ;
    cin >> n ;
    vector<string> words(n) ;

    for (int i = 0 ; i < n ; ++i) cin >> words[i] ;
    unordered_set<string> s ;
    vector<string> v ;
    BackTrack(words, s, v) ;
}