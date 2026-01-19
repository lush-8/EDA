#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
using namespace std;

typedef vector<int> VE ;
typedef vector<VE> VVE ;

struct Tuple {
    int val ;
    int row ;
    int col ;
};

struct Ordenacion {

    bool operator() (const Tuple& a, const Tuple& b) const 
    {
        return a.val > b.val ;
    }
};

// Retorna el k-èsim element global (començant en u) dels elements continguts en el vector de vectors V.
// Sigui n = V.size(). Cal tenir en compte que, per a tota 0 ≤ i < n, V[i] està ordenat de petit a gran. 
// A més, no hi ha cap element repetit en tot V.
// Sigui m = ∑0n−1 V[i].size(). Podeu suposar que k està entre 1 i m, que n està entre 2 i 500, i que algun 
// V[i] pot estar buit. Si us cal, podeu implementar procediments auxiliars. Tingueu en compte que, en els 
// jocs de proves “grossos”, k = Θ(n) i m = Θ(n^2). La solució esperada en aquest cas té cost Θ(n logn).
int k_esim(int k, const VVE& V) {

    map<int, int> m ;

    for (int i = 0 ; i < V.size() ; ++i) {
        if (not V[i].empty()) m[V[i][0]] = i ;
    }
    pair<int, int> result ;
    VE it(V.size(), 1) ;

    while (k > 0) {
        result = *m.begin() ;

        if (V[result.second].size() > it[result.second]) {
            m[V[result.second][it[result.second]]] = result.second ;
            ++it[result.second] ;
        }
        m.erase(m.begin()) ;
        --k ;
    }
    return result.first ;
}

int k_esim(int k, const VVE& V) {

    priority_queue<Tuple, vector<Tuple>, Ordenacion> pq ;
    int n = V.size() ;

    for (int i = 0 ; i < n ; ++i) {
        if (not V[i].empty()) pq.push({V[i][0], i, 0}) ;
    }
    for (int i = 0 ; i < k - 1 ; ++i) {
        Tuple top = pq.top() ;
        pq.pop() ;
        int row = top.row ;
        int col = top.col ;

        if (col + 1 < V[row].size()) pq.push({V[row][col + 1], row, col + 1}) ;
    }
    return pq.top().val ;
}

int k_esim(int k, const VVE& V) {

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq ;
    int n = V.size() ;

    for (int i = 0 ; i < n ; ++i) {
        if (not V[i].empty()) pq.push({V[i][0], i, 0}) ;
    }
    for (int i = 0 ; i < k - 1 ; ++i) {
        tuple<int, int, int> top = pq.top() ;
        pq.pop() ;
        int row = get<1>(top) ;
        int col = get<2>(top) ;

        if (col + 1 < V[row].size()) pq.push({V[row][col + 1], row, col + 1}) ;
    }
    return get<0>(pq.top()) ;
}

int main () {

    int n ;

    while (cin >> n) {
        vector<vector<int>> V(n) ;
        int total = 0 ;

        for (int i = 0 ; i < n ; ++i) {
            int m ;
            cin >> m ;
            total += m ;
            V[i] = vector<int>(m) ;

            for (int j = 0 ; j < m ; ++j) cin >> V[i][j] ;
        }
        int i1 , i2 , k ;

        while (cin >> i1 >> i2 >> k , i1 != -1) {
            if (i1 < 0 or i1 >= n or i2 < 0 or i2 >= n or k < 1 or k > total) {
                cerr << "pifia!!! " << i1 << ' ' << i2 << ' ' << k << ' ' << n << ' ' << total << endl ;
                return 0 ;
            }
            swap(V[i1], V[i2]) ;
            cout << k_esim(k, V) << endl ;
        }
    }
}