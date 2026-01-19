#include <iostream>
#include <vector>
using namespace std;

void read_board(vector<vector<int>>& board) {

    for (int i = 0 ; i < board.size() ; ++i) {
        for (int j = 0 ; j < board[0].size() ; ++j) {
            string s ;
            cin >> s ;
            
            if (s != "X") board[i][j] = stoi(s) ;
        }
    }
}

void DFS(int i, int j, vector<vector<int>>& board, int& sum, int& squares) {

    int n = board.size() , m = board[0].size() ;

    if (i < 0 or n <= i or j < 0 or m <= j or board[i][j] == -1) return ;
    sum += board[i][j] ;
    ++squares ;
    board[i][j] = -1 ;
    DFS(i + 1, j + 1, board, sum, squares) ;
    DFS(i + 1, j - 1, board, sum, squares) ;
    DFS(i - 1, j + 1, board, sum, squares) ;
    DFS(i - 1, j - 1, board, sum, squares) ;
}

int main() {

    int t ;
    cin >> t ;

    for (int i = 0 ; i < t ; ++i) {
        int n , m ;
        cin >> n >> m ;
        vector<vector<int>> board(n, vector<int>(m, -1)) ;
        read_board(board) ;
        int prev = -1 ;
        bool ok = true ;

        for (int i = 0 ; i < n and ok ; ++i) {
            for (int j = 0 ; j < m and ok ; ++j) {
                if (board[i][j] != -1) {
                    int sum = 0 , squares = 0 ;
                    DFS(i, j, board, sum, squares) ;

                    if (sum%squares) ok = false ;
                    else if (prev != -1) {
                        if (sum/squares != prev) ok = false ;
                    } 
                    else prev = sum/squares ;
                }
            }
        }
        cout << "Case " << i + 1 << ": " << (ok ? "yes" : "no") << endl ;
    }
}