#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const vector<pair<int, int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}} ;

bool valid(int i, int j, const vector<vector<char>>& map) {

    return 0 <= i and i < map.size() and 0 <= j and j < map[0].size() and map[i][j] != '#' ;
}

pair<int, int> BFS(const vector<vector<char>>& map) {

    int n = map.size() ;
    int m = map[0].size() ;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX)) ;
    vector<vector<int>> persons(n, vector<int>(m, -1)) ;
    queue<pair<int, int>> q ;
    q.push({0, 0}) ;
    dist[0][0] = 0 ;
    persons[0][0] = (map[0][0] == 'P') ;

    while (not q.empty()) {
        int i = q.front().first ;
        int j = q.front().second ;
        q.pop() ;

        if (map[i][j] == 'T') return {dist[i][j], persons[i][j]} ;
        for (const pair<int, int>& d : directions) {
            int next_i = i + d.first ;
            int next_j = j + d.second ;
            int next_d = dist[i][j] + 1 ;

            if (valid(next_i, next_j, map)) {
                int next_p = persons[i][j] + int(map[next_i][next_j] == 'P') ;

                if (dist[next_i][next_j] == INT_MAX) {
                    q.push({next_i, next_j}) ;
                    dist[next_i][next_j] = next_d ;
                    persons[next_i][next_j] = next_p ;
                } 
                else if (dist[next_i][next_j] == next_d and persons[next_i][next_j] < next_p) {
                    persons[next_i][next_j] = next_p ;
                }
            }
        }
    }
    return {-1, 0} ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<char>> map(n, vector<char>(m)) ;
        bool found = false ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                cin >> map[i][j] ;

                if (map[i][j] == 'T') found = true ;
            }
        }
        if (not found) cout << "El telecos ha fugit." << endl ;
        else {
            pair<int, int> result = BFS(map) ;

            if (result.first == -1) cout << "El telecos esta amagat." << endl ;
            else cout << result.first << ' ' << result.second << endl ;
        }
    }
}