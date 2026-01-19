#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiply2x2(const vector<vector<int>>& a, const vector<vector<int>>& b, int m) {

    vector<vector<int>> result(2, vector<int>(2)) ;
    result[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0])%m ;
    result[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1])%m ;
    result[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0])%m ;
    result[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1])%m ;
    return result ;
}

vector<vector<int>> compute(vector<vector<int>>& mat, int n, int m) {

    if (n == 0) {
        vector<vector<int>> identity(2, vector<int>(2, 0)) ;
        identity[0][0] = identity[1][1] = 1 ;
        return identity ;
    }
    else if (n == 1) {
        for (int i = 0 ; i < 2 ; ++i) {
            for (int j = 0 ; j < 2 ; ++j) mat[i][j] %= m ;
        }
        return mat ;
    }
    else {
        vector<vector<int>> result = compute(mat, n/2, m) ;
        result = multiply2x2(result, result, m) ;

        if (n%2 == 1) result = multiply2x2(result, mat, m) ;
        return result ;
    }
}

int Nth_Fibonacci(int n, int m) {

    vector<vector<int>> fib(2, vector<int>(2, 0)) ;
    fib[0][0] = fib[0][1] = fib[1][0] = 1 ;
    fib = compute(fib, n, m) ;
    return fib[0][1] ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        cout << Nth_Fibonacci(n, m) << endl ;
    }
}