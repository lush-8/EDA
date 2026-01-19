#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int infinite = INT_MAX ;
vector<pair<int, int>> dirs = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}} ;

bool valid_pos(int n, int m, const pair<int, int>& p) {

    return 0 <= p.first and p.first < n and 0 <= p.second and p.second < m ;
}

int BFS(int n, int m, const pair<int, int>& from, const pair<int, int>& to) {

    vector<vector<int>> dist(n, vector<int>(m, infinite)) ;
    queue<pair<int, int>> q ;
    q.push(from) ;
    dist[from.first][from.second] = 0 ;

    while (not q.empty()) {
        pair<int, int> p = q.front() ;
        q.pop() ;

        if (p == to) return dist[p.first][p.second] ;
        for (const pair<int, int>& d : dirs) {
            pair<int, int> next = p ;
            next.first += d.first ;
            next.second += d.second ;

            if (valid_pos(n, m, next) and dist[next.first][next.second] == infinite) {
                dist[next.first][next.second] = dist[p.first][p.second] + 1 ;
                q.push(next) ;
            }
        }
    }
    return -1 ;
}

int main () {

    int n , m , W , L , p ;

    while (cin >> n >> m >> W >> L >> p) {
        vector<pair<int, int>> objectives(p + 1) ;
        objectives[0] = {0, 0} ;

        for (int i = 1 ; i <= p ; ++i) {
            int f , c ;
            cin >> f >> c ;
            objectives[i] = {f, c} ;
        }
        int points = 0 ;
        int best = 0 ;
        bool stop = false ;

        for (int i = 0 ; not stop and i < objectives.size() - 1 ; ++i) {
            int dist = BFS(n, m, objectives[i], objectives[i + 1]) ;

            if (dist == -1) stop = true ;
            else {
                points += W ;
                points -= L*dist ;

                if (points > best) best = points ;
            }
        }
        cout << best << endl ;
    }
}