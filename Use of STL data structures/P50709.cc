#include <iostream>
#include <map>
using namespace std;

int main () {

    char op ;
    map<int, int> n2freq ;

    while (cin >> op) {
        if (op == 'S') {
            int n ;
            cin >> n ;
            ++n2freq[n] ;
        }
        else if (op == 'A') {
            if (n2freq.empty()) cout << "error!" ;
            else {
                map<int, int>::const_iterator it = n2freq.end() ;
                --it ;
                cout << it->first ;
            }
            cout << endl ;
        }
        else if (op == 'R') {
            if (n2freq.empty()) cout << "error!" << endl ;
            else {
                map<int, int>::const_iterator it = n2freq.end() ;
                --it ;
                --n2freq[it->first] ;

                if (n2freq[it->first] == 0) n2freq.erase(it->first) ;
            }
        }
        else if (op == 'I') {
            int n ;
            cin >> n ;

            if (n2freq.empty()) cout << "error!" << endl ;
            else {
                map<int, int>::const_iterator it = n2freq.end() ;
                --it ;
                int max = it->first ;
                --n2freq[max] ;

                if (n2freq[max] == 0) n2freq.erase(max) ;
                max += n ;
                ++n2freq[max] ;
            }
        }
        else if (op == 'D') {
            int n ;
            cin >> n ;

            if (n2freq.empty()) cout << "error!" << endl ;
            else {
                map<int, int>::const_iterator it = n2freq.end() ;
                --it ;
                int max = it->first ;
                --n2freq[max] ;

                if (n2freq[max] == 0) n2freq.erase(max) ;
                max -= n ;
                ++n2freq[max] ;
            }
        }
    }
}