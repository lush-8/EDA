#include <iostream>
#include <map>
using namespace std;

int main() {
    
    map<string, int> M ;
    char c ;

    while (cin >> c) {
        if (c == 'N') {
            cout << "number: " << M.size() << endl ;
        }
        else if (c == 'D') {
            string nif;
            int money;
            cin >> nif >> money;
            M[nif] += money ;
        }
        else if (c == 'Q') {
            string nif;
            cin >> nif;
            auto it = M.find(nif) ;
            cout << (it == M.end() ? -1 : it->second) << endl ;
        }
        else if (c == 'P') {
            bool first = true ;

            for (const auto& x : M) {
                if ((x.first[7] - '0')%2 == 0) {
                    if (first) first = false ;
                    else cout << ' ' ;
                    cout << x.first ;
                }
            }
            cout << endl ;
        }
        else { // c == 'L'
            if (M.empty()) cout << "NO LAST NIF" << endl ;
            else cout << prev(M.end())->first << ' ' << prev(M.end())->second << endl ;
        }
    }
}