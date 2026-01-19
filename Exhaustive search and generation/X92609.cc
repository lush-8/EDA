#include <iostream>
#include <vector>
using namespace std;

int BackTrack(int i, int x, int sum, int n, vector<int>& v) {

    if (sum > x or i > n) return 0 ;
    if (i == n) return sum == x ;
    return BackTrack(i + 1, x, sum + v[i], n, v) + BackTrack(i + 1, x, sum, n, v) + BackTrack(i + 1, x, sum + 2*v[i], n, v) ;
}

int main () {

    int x , n ;

    while (cin >> x >> n) {
        vector<int> v(n) ;

        for (int i = 0 ; i < n ; ++i) cin >> v[i] ;
        cout << BackTrack(0, x, 0, n, v) << endl ;
    }
}