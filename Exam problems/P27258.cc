#include <iostream>
#include <vector>
using namespace std;

bool valid(int i, int j, const vector<vector<char>>& map) {

    return 0 <= i and i < map.size() and 0 <= j and j < map[0].size() ;
}

bool DFS(int i, int j, int end_i, int end_j, const vector<vector<char>>& map, vector<vector<bool>>& visited) {

    visited[i][j] = true ;

    if (i == end_i and j == end_j) return true ;
    if (valid(i - 1, j, map) and not visited[i - 1][j] and map[i - 1][j] != 'X' and DFS(i - 1, j, end_i, end_j, map, visited)) return true ;
    if (valid(i + 1, j, map) and not visited[i + 1][j] and map[i + 1][j] != 'X' and DFS(i + 1, j, end_i, end_j, map, visited)) return true ;
    if (valid(i, j - 1, map) and not visited[i][j - 1] and map[i][j - 1] != 'X' and DFS(i, j - 1, end_i, end_j, map, visited)) return true ;
    if (valid(i, j + 1, map) and not visited[i][j + 1] and map[i][j + 1] != 'X' and DFS(i, j + 1, end_i, end_j, map, visited)) return true ;
    return false ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<char>> map(n, vector<char>(m)) ;
        int start_i , start_j , end_i , end_j ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) cin >> map[i][j] ;
        }
        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                if (map[i][j] == 'I') {
                    start_i = i ;
                    start_j = j ;
                }
                else if (map[i][j] == 'F') {
                    end_i = i ;
                    end_j = j ;
                }
                else if (map[i][j] == 'M') {
                    map[i][j] = 'X' ;

                    if (0 <= i - 1 and map[i - 1][j] != 'M') map[i - 1][j] = 'X' ;
                    if (i + 1 < n and map[i + 1][j] != 'M') map[i + 1][j] = 'X' ;
                    if (0 <= j - 1 and map[i][j - 1] != 'M') map[i][j - 1] = 'X' ;
                    if (j + 1 < m and map[i][j + 1] != 'M') map[i][j + 1] = 'X' ;
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
        cout << (DFS(start_i, start_j, end_i, end_j, map, visited) ? "SI" : "NO") << endl ;
    }
}