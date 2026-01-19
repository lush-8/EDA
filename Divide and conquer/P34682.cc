#include <iostream>
#include <vector>
using namespace std;

/* 
   Let S = x_1, …, x_n be a sequence of integer numbers such that x_1 < … < x_n. 
   For every integer number a and every index 1 ≤ i ≤ n, define f_a(i) = x_i + a. 
   Write a program that, given S and a, tells whether there is some i such that f_a(i) = i.
*/
int find_fixed_point(const vector<int>& v, int a) {

    int left = 0 , right = v.size() - 1 ;
    int pos = -1 ; 

    while (left <= right) {
        int mid = left + (right - left)/2 ;

        if (v[mid] + a == mid + 1) {
            pos = mid + 1 ;
            right = mid - 1 ;
        }
        else if (v[mid] + a < mid + 1) left = mid + 1 ;
        else right = mid - 1 ;
    }
    return pos ;
}

void helper(const vector<int>& v, int a, int& pos, int left, int right) {

    if (left > right) return ;
    int mid = left + (right - left)/2 ;
    
    if (v[mid] + a == mid + 1) {
        pos = mid + 1 ;
        helper(v, a, pos, left, mid - 1) ;
    }
    else if (v[mid] + a < mid + 1) helper(v, a, pos, mid + 1, right) ;
    else helper(v, a, pos, left, mid - 1) ;
}

void find_fixed_point(const vector<int>& v, int a, int& pos) {

    return helper(v, a, pos, 0, v.size() - 1) ;
}

int main () {

    int n ;
    int n_cases = 1 ;

    while (cin >> n) {
        cout << "Sequence #" << n_cases << endl ;
        ++n_cases ;
        vector<int> v(n) ;

        for (int i = 0 ; i < n ; ++i) cin >> v[i] ;
        int m ;
        cin >> m ;

        for (int i = 0 ; i < m ; ++i) {
            int a ;
            cin >> a ;
            int pos = -1 ;
            find_fixed_point(v, a, pos) ;

            if (pos != -1) cout << "fixed point for " << a << ": " << pos << endl ;
            else cout << "no fixed point for " << a << endl ;
        }
        cout << endl ;
    }
}