#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void escriu_contingut(vector<queue<string>>& v) {

    int n = v.size() ;

    for (int i = 0 ; i < n ; ++i) {
        cout << "cua " << i + 1 << ":" ;

        while (not v[i].empty()) {
            cout << " " << v[i].front() ;
            v[i].pop() ;
        }
        cout << endl ;
    }
}

int main () {

    int n ;
    cin >> n ;
    vector<queue<string>> v(n) ;
    string s ;
    getline(cin, s) ;

    for (int i = 0 ; i < n ; ++i) {
        getline(cin, s) ;
        istringstream iss(s) ;
        string nom ;

        while (iss >> nom) {
            v[i].push(nom) ;
        }
    }
    string accio ;
    cout << "SORTIDES" << endl ;
    cout << string(8, '-') << endl ;

    while (cin >> accio) {
        if (accio == "ENTRA") {
            string nom ;
            int n_cua ;
            cin >> nom >> n_cua ;

            if (1 <= n_cua and n_cua <= n) {
                v[n_cua-1].push(nom) ;
            }
        }
        else if (accio == "SURT") {
            int n_cua ;
            cin >> n_cua ;

            if (1 <= n_cua and n_cua <= n) {
                if (not v[n_cua-1].empty()) {
                    cout << v[n_cua-1].front() << endl ;
                    v[n_cua-1].pop() ;
                }
            }
        }
    }
    cout << endl ;
    cout << "CONTINGUTS FINALS" << endl ;
    cout << string(17, '-') << endl ;
    escriu_contingut(v) ;
}