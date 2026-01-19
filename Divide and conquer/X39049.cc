#include <iostream>
#include <vector>
using namespace std;

vector<int> Permutation_Product(const vector<int>& v1, const vector<int>& v2) {

    vector<int> result(v1.size()) ;

    for (int i = 0 ; i < v1.size() ; ++i) {
        result[i] = v1[v2[i]] ;
    }
    return result ;
}

vector<int> Permutation_Power(const vector<int>& v, int k) {

    if (k == 0) {
        int n = v.size() ;
        vector<int> result(n) ;

        for (int i = 0 ; i < n ; ++i) result[i] = i ;
        return result ; 
    }
    else if (k == 1) return v ;
    else {
        vector<int> result = Permutation_Power(v, k/2) ;
        result = Permutation_Product(result, result) ;

        if (k%2) result = Permutation_Product(result, v) ;
        return result ;
    }
}

int main () {

    int n ;

    while (cin >> n) {
        vector<int> v(n) ;

        for (int i = 0 ; i < n ; ++i) cin >> v[i] ;
        int k ;
        cin >> k ;
        vector<int> result = Permutation_Power(v, k) ;

        for (int i = 0 ; i < n ; ++i) {
            cout << result[i] ;

            if (i != n - 1) cout << ' ' ;
        }
        cout << endl ;
    }
}