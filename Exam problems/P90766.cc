#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> read_map(int f, int c) {

    vector<vector<char>> result(f, vector<char>(c)) ;

    for (int i = 0 ; i < f ; ++i) {
        for (int j = 0 ; j < c ; ++j) {
            cin >> result[i][j] ;
        }
    }
    return result ;
}

int DFS(vector<vector<char>>& map, int x, int y) {

    if (x < 0 or map.size() <= x or y < 0 or map[0].size() <= y) return 0 ;
    if (map[x][y] == 't') {
        map[x][y] = '.' ;
        return 1 + DFS(map, x + 1, y) + DFS(map, x - 1, y) + DFS(map, x, y + 1) + DFS(map, x, y - 1) ;
    }
    else if (map[x][y] == 'X') return 0 ;
    else {
        map[x][y] = 'X' ;
        return DFS(map, x + 1, y) + DFS(map, x - 1, y) + DFS(map, x, y + 1) + DFS(map, x, y - 1) ;
    }
}

int main () {

    int f , c ;
    cin >> f >> c ;
    vector<vector<char>> map = read_map(f, c) ;
    int x , y ;
    cin >> x >> y ;
    cout << DFS(map, --x, --y) << endl ;
}