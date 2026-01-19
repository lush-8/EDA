#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Circle {
    double x ;
    double y ;
    double r ;
};

int main () {

    int n ;
    double d ;

    while (cin >> n >> d) {
        vector<Circle> v(n) ;
        vector<vector<int>> graph(n) ;

        for (int i = 0 ; i < n ; ++i) {
            cin >> v[i].x >> v[i].y >> v[i].r ;
        }
        for (int i = 0 ; i < n ; ++i) {
            for (int j = i + 1 ; j < n ; ++j) {
                double dist = sqrt(pow((v[i].x - v[j].x), 2) + pow((v[i].y - v[j].y), 2)) ;
                dist -= v[i].r + v[j].r ;

                if (dist <= d) {
                    graph[i].push_back(j) ;
                    graph[j].push_back(i) ;
                }
            }
        }
        vector<int> result(n, -1) ;
        queue<pair<int, int>> q ;
        result[0] = 0 ;
        q.push({0, 0}) ;

        while (not q.empty()) {
            pair<int, int> p = q.front() ;
            q.pop() ;
            int jumps = p.first ;
            int node = p.second ;

            if (result[node] == jumps) {
                for (const int& neighbour : graph[node]) {
                    if (result[neighbour] == -1) q.push({result[neighbour] = jumps + 1, neighbour}) ;
                }
            }
        }
        if (result[n - 1] != -1) cout << result[n - 1] << endl ;
        else cout << "Xof!" << endl ;
    }
}