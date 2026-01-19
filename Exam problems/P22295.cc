#include <iostream>
#include <vector>
using namespace std;

int start_i , start_j ;
int end_i , end_j ;
const vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}} ;

void Read(vector<vector<char>>& board) {

    for (int i = 0 ; i < board.size() ; ++i) {
        for (int j = 0 ; j < board[0].size() ; ++j) {
            cin >> board[i][j] ;
        }
    }
}

bool valid_pos(int i, int j, const vector<vector<char>>& board) {

    return 0 <= i and i < board.size() and 0 <= j and j < board[0].size() ;
}

void BackTrack(int i, int j, string& path, const vector<vector<char>>& board, vector<vector<bool>>& visited) {
    
    if (i == end_i and j == end_j) cout << path << endl ;
    else {
        for (const pair<int, int>& d : directions) {
            int next_i = i + d.first ;
            int next_j = j + d.second ;

            if (valid_pos(next_i, next_j, board) and not visited[next_i][next_j]) {
                path.push_back(board[next_i][next_j]) ;
                visited[next_i][next_j] = true ;
                BackTrack(next_i, next_j, path, board, visited) ;
                visited[next_i][next_j] = false ;
                path.pop_back() ;
            }
        }
    }
}

int main () {

    int n , m ;
    cin >> n >> m ;
    vector<vector<char>> board(n, vector<char>(m)) ;
    vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
    Read(board) ;
    cin >> start_i >> start_j ;
    cin >> end_i >> end_j ;
    string s ;
    visited[start_i][start_j] = true ;
    s.push_back(board[start_i][start_j]) ;
    BackTrack(start_i, start_j, s, board, visited) ;
}