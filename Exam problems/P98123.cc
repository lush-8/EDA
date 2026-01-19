#include <iostream>
#include <set>
using namespace std;

int main () {

    int n ;
    cin >> n ;
    string op ;
    set<int> s ;
    set<int> old ;
    long long benefici = 0 ;

    while (cin >> op) {
        if (op == "deixar") {
            int value ;
            cin >> value ;

            if (s.size() < n) {
                s.insert(value) ;
                benefici += value ;
            }
            else if (*s.begin() < value) {
                old.insert(*s.begin()) ;
                benefici -= *s.begin() ;
                s.erase(s.begin()) ;
                s.insert(value) ;
                benefici += value ;
            }
            else old.insert(value) ;
            cout << benefici << endl ;
        }
        else if (op == "endur") {
            int value ;
            cin >> value ;

            if (s.empty() and old.empty()) cout << 0 << endl ;
            else {
                if (s.find(value) != s.end()) {
                    benefici -= value ;
                    s.erase(value) ;

                    if (not old.empty()) {
                        auto it = prev(old.end()) ;
                        s.insert(*it) ;
                        benefici += *it ;
                        old.erase(it) ;
                    }
                }
                else if (old.find(value) != old.end()) {
                    old.erase(value) ;
                }
                cout << benefici << endl ;
            }
        }
    }
}