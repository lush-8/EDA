#include <vector>
using namespace std;

bool resistant_search_helper(double x, const vector<double>& v, int left, int right) {

    if (left > right) return false ;
    if (left + 1 >= right) return v[left] == x or v[right] == x ;
    else {
        int mid = (left + right)/2 ;

        if (x < v[mid]) return v[mid + 1] == x or resistant_search_helper(x, v, left, mid - 1) ;
        else if (v[mid] < x) return v[mid - 1] == x or resistant_search_helper(x, v, mid + 1, right) ;
        else return true ;
    }
}

/* 
   Precondition
   The vector v is “almost sorted” in nondecreasing order, in the sense that there 
   may be at most a pair of indices i and j such that 0 ≤ i < j < n and V[i] > V[j].
*/
bool resistant_search(double x, const vector<double>& v) {

    return resistant_search_helper(x, v, 0, v.size() - 1) ;
}