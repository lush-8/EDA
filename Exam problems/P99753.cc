#include <vector>
using namespace std;

bool binary_search(int x, int left, int right, const vector<int>& v) {

    if (left > right) return false ;
    int mid = (left + right)/2 ;

    if (x < v[mid]) return binary_search(x, left, mid - 1, v) ;
    else if (x > v[mid]) return binary_search(x, mid + 1, right, v) ;
    else return true ;
}

bool search(int x, int left, int right, const vector<int>& v) {

    if (left + 1 == right) return v[left] == x or v[right] == x ;
    int mid = (left + right)/2 ;

    if (v[left] <= v[mid]) {
        if (v[left] <= x and x <= v[mid]) {
            return binary_search(x, left, mid + 1, v) ;
        }
        else return search(x, mid, right, v) ;
    }
    else {
        if (v[mid] <= x and x <= v[right]) {
            return binary_search(x, mid, right + 1, v) ;
        }
        else return search(x, left, mid, v) ;
    }
}

bool search(int x, const vector<int>& v) {

    return search(x, 0, v.size() - 1, v) ;
}