#include <vector>
using namespace std;

int Search_Max(const vector<int>& v) {

    int left = 0 , right = v.size() - 1 ;

    while (left < right) {
        int mid = (left + right)/2 ;

        if (v[mid] < v[mid + 1]) left = mid + 1 ;
        else right = mid ;
    }
    return left ;
}

/*
   Un vector de n nombres enters v[0..n−1] és unimodal si n ≥ 1, 
   i existeix un índex j tal que 0 ≤ j ≤ n−1 i que satisfà:
   · v[0] < … < v[j−1] < v[j]
   · v[j] > v[j+1] > v[j+2] > … > v[n−1]

   Noteu que els vectors amb n ≤ 2 elements diferents són unimodals. 
   En general, noteu que tot vector estrictament creixent també és 
   unimodal (i en tots els casos j = n−1), i anàlogament, tot vector 
   estrictamentment decreixent també és unimodal (i llavors j = 0).

   Precondició
   El vector v és unimodal.
*/
bool search(int x, const vector<int>& v) {

    int max = Search_Max(v) ;

    if (v[max] < x) return false ;
    int left = 0 , right = max ;

    while (left <= right) {
        int mid = (left + right)/2 ;

        if (v[mid] == x) return true ;
        else if (v[mid] < x) left = mid + 1 ;
        else right = mid - 1 ;
    }
    left = max + 1 , right = v.size() - 1 ;

    while (left <= right) {
        int mid = (left + right)/2 ;

        if (v[mid] == x) return true ;
        else if (v[mid] > x) left = mid + 1 ;
        else right = mid - 1 ;
    }
    return false ;
}