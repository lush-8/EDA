#include <iostream>
#include <vector>
using namespace std;

int BackTrack(int i, int j, int curr, vector<vector<char>>& sol) {

    int n = sol.size() ;
    int m = sol[0].size() ;

    if (i == n) return curr ;
    int next_i , next_j ;

    if (j == m - 1) {
        next_i = i + 1 ;
        next_j = 0 ;
    } 
    else {
        next_i = i ;
        next_j = j + 1 ;
    }
    sol[i][j] = 'L' ;
    int new_lols = 0 ;

    if (i >= 2 and sol[i - 1][j] == 'O' and sol[i - 2][j] == 'L') ++new_lols ;
    if (j >= 2 and sol[i][j - 1] == 'O' and sol[i][j - 2] == 'L') ++new_lols ;
    if (i >= 2 and j >= 2 and sol[i - 1][j - 1] == 'O' and sol[i - 2][j - 2] == 'L') ++new_lols ;
    if (i >= 2 and j + 2 < m and sol[i - 1][j + 1] == 'O' and sol[i - 2][j + 2] == 'L') ++new_lols ;
    int nl = BackTrack(next_i, next_j, curr + new_lols, sol) ;
    sol[i][j] = 'O' ;
    int no = BackTrack(next_i, next_j, curr, sol) ;
    return max(nl, no) ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<char>> sol(n, vector<char>(m)) ;
        cout << BackTrack(0, 0, 0, sol) << endl ;
    }
}