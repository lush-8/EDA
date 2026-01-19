#include <iostream>
#include <map>
using namespace std;

int main () {

    map<string, int> word2freq ;
    string op ;

    while (cin >> op) {
        if (op == "store") {
            string s ;
            cin >> s ;
            ++word2freq[s] ;
        }
        else if (op == "delete") {
            string s ;
            cin >> s ;

            if (word2freq.find(s) != word2freq.end()) {
                --word2freq[s] ;
                
                if (word2freq[s] == 0) word2freq.erase(s) ;
            }
        }
        else if (op == "minimum?") {
            if (word2freq.empty()) cout << "indefinite minimum" << endl ;
            else {
                map<string, int>::const_iterator it = word2freq.begin() ;
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl ;
            }
        }
        else if (op == "maximum?") {
            if (word2freq.empty()) cout << "indefinite maximum" << endl ;
            else {
                map<string, int>::const_iterator it = word2freq.end() ;
                --it ;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl ;
            }
        }
    }
}