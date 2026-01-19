#include <iostream>
#include <vector>
using namespace std;

int s , n ;
vector<int> values ;

void Write(const vector<bool>& sol) {

    cout << '{' ;
    bool first = true ;

    for (int i = 0 ; i < sol.size() ; ++i) {
        if (sol[i]) {
            if (first) first = false ;
            else cout << ',' ;
            cout << values[i] ;
        }
    }
    cout << '}' << endl ;
}

void BackTrack(int i, vector<bool>& sol, int sum, int rest_sum) {

    if (sum > s or sum + rest_sum < s) return ;
    if (i == n) {
        if (sum == s) Write(sol) ;
    }
    else {
        sol.push_back(true) ;
        BackTrack(i + 1, sol, sum + values[i], rest_sum - values[i]) ;
        sol.back() = false ;
        BackTrack(i + 1, sol, sum, rest_sum - values[i]) ;
        sol.pop_back() ;
    }
}

int main () {

    cin >> s >> n ;
    values = vector<int>(n) ;
    int sum = 0 ;

    for (int i = 0 ; i < n ; ++i) {
        cin >> values[i] ;
        sum += values[i] ;
    }
    vector<bool> sol ;
    BackTrack(0, sol, 0, sum) ;
}