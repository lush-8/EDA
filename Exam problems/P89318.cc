#include <iostream>
#include <vector>
using namespace std;

void BackTrack(string& s, int n, vector<bool>& used) {

    if (s.size() == n) cout << s << endl ;
    else for (int i = 0 ; i < n ; ++i) {
        if (not used[i]) {
            if (s.empty()) {
                s.push_back(char(i + 'a')) ;
                used[i] = true ;
                BackTrack(s, n, used) ;
                used[i] = false ;
                s.pop_back() ;
            }
            else if (s.back() - 'a' + 1 != i) {
                s.push_back(char(i + 'a')) ;
                used[i] = true ;
                BackTrack(s, n, used) ;
                used[i] = false ;
                s.pop_back() ;
            }
        }
    }
}

int main () {

    int n ;
    cin >> n ;
    string s ;
    vector<bool> used(26) ;
    BackTrack(s, n, used) ;
}