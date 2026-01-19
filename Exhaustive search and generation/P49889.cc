#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool is_Vowel(const char& c) {

    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y' ;
}

bool used(const char& c, const unordered_set<char>& s) {

    return s.find(c) != s.end() ;
}

void BackTrack(string& word, vector<char>& consonants, vector<char>& vowels, const int& n, unordered_set<char>& s) {

    if (word.size() == 2*n) {
        cout << word << endl ;
        return ;
    }
    if (word.empty() or is_Vowel(word.back())) {
        for (int i = 0 ; i < n ; ++i) {
            if (not used(consonants[i], s)) {
                word.push_back(consonants[i]) ;
                s.insert(consonants[i]) ;
                BackTrack(word, consonants, vowels, n, s) ;
                s.erase(consonants[i]) ;
                word.pop_back() ;
            }
        }
    }
    else for (int i = 0 ; i < n ; ++i) {
        if (not used(vowels[i], s)) {
            word.push_back(vowels[i]) ;
            s.insert(vowels[i]) ;
            BackTrack(word, consonants, vowels, n, s) ;
            s.erase(vowels[i]) ;
            word.pop_back() ;
        }
    }
}

int main () {

    int n ;
    cin >> n ;
    vector<char> consonants(n) ;
    vector<char> vowels(n) ;

    for (int i = 0 ; i < n ; ++i) cin >> consonants[i] ;
    for (int i = 0 ; i < n ; ++i) cin >> vowels[i] ;
    unordered_set<char> s ;
    string word ;
    BackTrack(word, consonants, vowels, n, s) ;
}