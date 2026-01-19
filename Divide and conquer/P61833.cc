#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> llegir_mat(int a) {

    vector<vector<int>> result(2, vector<int>(2)) ;
    result[0][0] = a ;

    for (int i = 0 ; i < 2 ; ++i) {
        if (i == 0) for (int j = 1 ; j < 2 ; ++j) cin >> result[i][j] ;
        else for (int j = 0 ; j < 2 ; ++j) cin >> result[i][j] ;
    }
    return result ;
}

vector<vector<int>> multiply(const vector<vector<int>>& a, const vector<vector<int>>& b, int m) {

    vector<vector<int>> result(a.size(), vector<int>(b[0].size())) ;

    for (int i = 0 ; i < a.size() ; ++i) {
        for (int j = 0 ; j < b[0].size() ; ++j) {
            int sum = 0 ;

            for (int k = 0 ; k < a[0].size() ; ++k) sum += a[i][k]*b[k][j] ;
            result[i][j] = sum%m ;
        }
    }
    return result ;
}

vector<vector<int>> multiply2x2(const vector<vector<int>>& a, const vector<vector<int>>& b, int m) {

    vector<vector<int>> result(2, vector<int>(2)) ;
    result[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0])%m ;
    result[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1])%m ;
    result[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0])%m ;
    result[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1])%m ;
    return result ;
}

vector<vector<int>> mat_pow(vector<vector<int>>& mat, int n, int m) {

    if (n == 0) {
        vector<vector<int>> identity(2, vector<int>(2)) ;
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
        vector<vector<int>> result = mat_pow(mat, n/2, m) ;
        result = multiply2x2(result, result, m) ;

        if (n%2 == 1) result = multiply(result, mat, m) ;
        return result ;
    }
}

void escriu_mat(const vector<vector<int>>& mat) {

    for (int i = 0 ; i < 2 ; ++i) {
        for (int j = 0 ; j < 2 ; ++j) {
            if (j == 0) cout << mat[i][j] ;
            else cout << ' ' << mat[i][j] ;
        }
        cout << endl ;
    }
}

int main () {

    int a ;

    while (cin >> a) {
        vector<vector<int>> mat = llegir_mat(a) ;
        int n , m ;
        cin >> n >> m ;
        mat = mat_pow(mat, n, m) ;
        escriu_mat(mat) ;
        cout << string(10, '-') << endl ;
    }
}