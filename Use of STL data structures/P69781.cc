#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int Pseudo_Collatz(int x, int y, int n) {

    map<int, int> m ;
    bool repetition = false ;
    int cycle = 0 ;
    m[n] = cycle ;

    while (not repetition and n <= 1e8) {
        ++cycle ;
        
        if (n%2 == 0) {
            n = n/2 + x ;
        }
        else {
            n = 3*n + y ;
        }
        if (m.find(n) == m.end()) m[n] = cycle ;
        else repetition = true ;
    }
    if (repetition) return m.size() - m.find(n)->second ;
    else return n ;
}

int main () {

    int x , y , n ;
    
    while (cin >> x >> y >> n) {
        cout << Pseudo_Collatz(x, y, n) << endl ;
    }
}