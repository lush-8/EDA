#include <iostream>
#include <set>
using namespace std;

struct ordenacion {
    bool operator() (const string& a, const string& b) const 
    {
        if (a.size() == b.length()) return a < b ;
        else return a.length() < b.size() ;
    }
};

void escriu(int n_games, const set<string>& has, const set<string, ordenacion>& had) {

    if (n_games > 1) cout << endl ;
    cout << "GAME #" << n_games << endl ;
    cout << "HAS:" << endl ;

    for (auto it = has.begin() ; it != has.end() ; ++it) cout << *it << endl ;
    cout << endl ;
    cout << "HAD:" << endl ;

    for (auto it = had.begin() ; it != had.end() ; ++it) cout << *it << endl ;
}

int main () {

    int n_games = 1 ;
    string s ;

    while (s != "QUIT") {
        set<string> has ;
        set<string, ordenacion> had ;

        while (cin >> s and s != "END" and s != "QUIT") {
            if (has.find(s) == has.end()) {
                has.insert(s) ;
                had.erase(s) ;
            }
            else {
                has.erase(s) ;
                had.insert(s) ;
            }
        }
        escriu(n_games, has, had) ;
        ++n_games ;
    }
}