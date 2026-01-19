#include <iostream>
#include <map>
using namespace std;

int main () {

    cout.setf(ios::fixed) ;
    cout.precision(4) ;

    string op ;
    map<int, int> n2freq ;
    int min , max , count = 0 ;
    int sum = 0 ;

    while (cin >> op) {
        if (op == "number") {
            int n ;
            cin >> n ;
            ++count ;
            sum += n ;
            ++n2freq[n] ;
            min = n2freq.begin()->first ;
            map<int, int>::const_iterator it = n2freq.end() ;
            --it ;
            max = it->first ;
            cout << "minimum: " << min << ", " ;
            cout << "maximum: " << max << ", " ;
            cout << "average: " << double(sum)/count << endl ;
        }
        else if (op == "delete") {
            if (n2freq.empty()) cout << "no elements" << endl ;
            else {
                --count ;
                sum -= n2freq.begin()->first ;
                --n2freq.begin()->second ;

                if (n2freq.begin()->second == 0) n2freq.erase(n2freq.begin()->first) ;
                if (n2freq.empty()) cout << "no elements" << endl ;
                else {
                    min = n2freq.begin()->first ;
                    map<int, int>::const_iterator it = n2freq.end() ;
                    --it ;
                    max = it->first ;
                    cout << "minimum: " << min << ", " ;
                    cout << "maximum: " << max << ", " ;
                    cout << "average: " << double(sum)/count << endl ;
                }
            }
        }
    }
}