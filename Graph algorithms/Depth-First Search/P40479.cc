#include <iostream>
#include <vector>
using namespace std;

struct Tuple {
    int i ;
    int j ;
    char c ;
};

vector<vector<char>> read_map(int n, int m, vector<Tuple>& v) {

    vector<vector<char>> result(n, vector<char>(m)) ;

    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            char c ;
            cin >> c ;

            if (c != '#' and c != '.') {
                v.push_back({i, j, c}) ;
                result[i][j] = '.' ;
            }
            else result[i][j] = c ;
        }
    }
    return result ;
}

void DFS(vector<vector<char>>& map, int i, int j, char c) {
    
    if (i < 1 or map.size() - 1 <= i or j < 1 or map[0].size() - 1 <= j) return ;
    if (map[i][j] == '#' or map[i][j] == c) return ;
    else {
        map[i][j] = c ;
        DFS(map, i + 1, j, c) ;
        DFS(map, i - 1, j, c) ;
        DFS(map, i, j + 1, c) ;
        DFS(map, i, j - 1, c) ;   
    }
}

void fill_map(vector<vector<char>>& map, const vector<Tuple>& v) {

    for (const Tuple& t : v) {
        DFS(map, t.i, t.j, t.c) ;
    }
}

void write(const vector<vector<char>>& map) {

    for (int i = 0 ; i < map.size() ; ++i) {
        for (int j = 0 ; j < map[0].size() ; ++j) cout << map[i][j] ;
        cout << endl ;
    }
    cout << endl ;
}

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<Tuple> v ;
        vector<vector<char>> map = read_map(n, m, v) ;
        fill_map(map, v) ;
        write(map) ;
    }
}