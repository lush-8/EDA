#include <iostream>
using namespace std;

int modular_pow_it(int n, int k, int m) {

    int result = 1 ;
    n %= m ;

    while (k) {
        if (k%2) result = (result*n)%m ;
        k /= 2 ;
        n = (n*n)%m ; 
    }
    return result ;
}

int modular_pow_rec2(int n, int k, int m) {

    if (k == 0) return 1 ;
    else {
        int half = modular_pow_rec2(n, k/2, m) ;
        int result = (half*half)%m ;

        if (k%2) result = (result*n)%m ;
        return result ;
    }
}

int modular_pow_rec1(int n, int k, int m) {

    if (k == 0) return 1 ;
    else {
        if (k%2 == 0) return (modular_pow_it(n, k/2, m)*modular_pow_rec2(n, k/2, m))%m ;
        else return (n*modular_pow_rec1(n, k - 1, m))%m ;
    }
}

int main () {

    int n , k , m ;
    int i = 0 ;

    while (cin >> n >> k >> m) {
        if (i%3 == 0) cout << modular_pow_rec1(n, k, m) ;
        else if (i%3 == 1) cout << modular_pow_rec2(n, k, m) ;
        else cout << modular_pow_it(n, k, m) ;
        cout << endl ;
        ++i ;
    }
}