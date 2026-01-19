#include <vector>
using namespace std;

int first_occurrence_helper(double x, const vector<double>& v, int left, int right) {

    if (left > right) return -1 ;
    int mid = (left + right)/2 ;
    
    if (x < v[mid]) return first_occurrence_helper(x, v, left, mid - 1) ;
    else if (x > v[mid]) return first_occurrence_helper(x, v, mid + 1, right) ;
    else {
        if (v[mid-1] == x and mid - 1 >= left) return first_occurrence_helper(x, v, left, mid - 1) ;
        else return mid ;
    }
}

/*
   Returns the position of the first occurrence of x in the vector v. 
   If x does not belong to v, return a -1.
   Precondition: the vector v is sorted in nondecreasing order.
*/
int first_occurrence(double x, const vector<double>& v) {

    return first_occurrence_helper(x, v, 0, v.size() - 1) ;
}