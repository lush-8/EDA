#include <iostream>//
#include <vector>
using namespace std;

int BackTrack(const vector<int>& pesos, int left_pes, int right_pes, int colocats, vector<bool>& used) {

    if (colocats == pesos.size() and left_pes >= right_pes) return 1 ;
    else {
        int ways = 0 ;

        for (int i = 0 ; i < pesos.size() ; ++i) {
            if (not used[i]) {
                if (left_pes >= right_pes + pesos[i]) {
                    used[i] = true ;
                    ways += BackTrack(pesos, left_pes, right_pes + pesos[i], colocats + 1, used) ;
                    ways += BackTrack(pesos, left_pes + pesos[i], right_pes, colocats + 1, used) ;
                    used[i] = false ;
                }
                else if (left_pes < right_pes + pesos[i]) {
                    used[i] = true ;
                    ways += BackTrack(pesos, left_pes + pesos[i], right_pes, colocats + 1, used) ;
                    used[i] = false ;
                }
            }
        }
        return ways ;
    }
}

int main () {

    int n ;

    while (cin >> n) {
        vector<int> pesos(n) ;
        
        for (int i = 0 ; i < n ; ++i) cin >> pesos[i] ;
        vector<bool> used(n, false) ;
        cout << BackTrack(pesos, 0, 0, 0, used) << endl ;
    }
}