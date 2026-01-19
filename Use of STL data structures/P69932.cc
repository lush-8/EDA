#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main () {

    string str ;

    while (getline(cin, str)) {
        istringstream iss(str) ;
        int n = 0 , length = 0 ;
        set<int> s ;

        while (iss >> n) s.insert(n) ;
        int prev ;
        set<int>::iterator it = s.begin() ;

        if (not s.empty()) {
            prev = *it ;
            ++it ;
            ++length ;
        }
        while (it != s.end()) {
            if (prev < *it and ((prev%2 == 0 and *it%2 != 0) or (prev%2 != 0 and *it%2 == 0))) {
                ++length ;
            }
            prev = *it ;
            ++it ;
        }
        cout << length << endl ;
    }
}