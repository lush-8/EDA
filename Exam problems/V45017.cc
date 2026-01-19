#include <iostream>
#include <vector>
using namespace std;

int BackTrack(int idx, pair<int, int>& dist, const vector<int>& pesos, vector<bool>& used) {

    if (idx == pesos.size()) return 1 ;
    else {
        int ways = 0 ;

        for (int i = 0 ; i < pesos.size() ; ++i) {
            if (not used[i]) {
                used[i] = true ;
                dist.first += pesos[i] ;
                ways += BackTrack(idx + 1, dist, pesos, used) ;
                dist.first -= pesos[i] ;

                if (dist.second + pesos[i] <= dist.first) {
                    dist.second += pesos[i] ;
                    ways += BackTrack(idx + 1, dist, pesos, used) ;
                    dist.second -= pesos[i] ;
                }
                used[i] = false ;
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
        pair<int, int> dist{0, 0} ;
        cout << BackTrack(0, dist, pesos, used) << endl ;
    }
}