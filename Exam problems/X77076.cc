#include <vector>
using namespace std;

int first_occurrence(double x, const vector<double>& v, int l, int r) {

    if (l > r) return -1 ;
    else {
        int m = (l + r)/2 ;

        if (v[m] == x) {
            int p_left = first_occurrence(x, v, l, m - 1) ;

            if (p_left == -1) return m ;
            return p_left ;
        }
        else if (x < v[m]) {
            int p_left = first_occurrence(x, v, l, m - 1) ;

            if (p_left == -1) {
                if (m + 1 <= r and v[m + 1] == x) return m + 1 ;
                return -1 ;
            }
            return p_left ;
        }
        else {
            if (m - 1 >= l and v[m - 1] == x) return m - 1 ;
            return first_occurrence(x, v, m + 1, r) ;
        }
    }
}

/*
Precondició
El vector v està “quasi ordenat” en ordre no decreixent, en el sentit que hi pot haver com a molt un parell d’índexos i i j tals que 0 ≤ i < j < n i V[i] > V[j].
*/
int first_occurrence(double x, const vector<double>& v) {

    return first_occurrence(x, v, 0, v.size() - 1) ;
}