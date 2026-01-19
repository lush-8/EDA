#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int merge(vector<int>& v, int left, int mid, int right) {

    vector<int> w(right - left + 1) ;
    int k = 0 ;
    int i = left ;
    int j = mid + 1 ;
    int inv = 0 ;

    while (i <= mid and j <= right) {
        if (v[i] <= v[j]) {
            w[k] = v[i] ;
            ++i ;
        }
        else {
            w[k] = v[j] ;
            ++j ;
            inv += mid - i + 1 ;
        }
        ++k ;
    }
    while (i <= mid) {
        w[k] = v[i] ;
        ++i ;
        ++k ;
    }
    while (j <= right) {
        w[k] = v[j] ;
        ++j ;
        ++k ;
    }
    for (int p = 0 ; p < w.size() ; ++p) v[left + p] = w[p] ;
    return inv ;
}

int inversion(vector<int>& v, int left, int right) {

    if (left >= right) return 0 ;
    int mid = (left + right)/2 ;
    return inversion(v, left, mid) + inversion(v, mid + 1, right) + merge(v, left, mid, right) ; 
}

int main () {

    int n ;

    while (cin >> n) {
        vector<int> v(n) ;

        for (int i = 0 ; i < n ; ++i) cin >> v[i] ;
        cout << inversion(v, 0, n - 1) << endl ;
    }
}