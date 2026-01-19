#include <iostream>
#include <map>
using namespace std;

bool canBuy(map<string, int>& m, int totalGames, const string& game) {

    return m[game] + 1 <= totalGames - m[game] ;
}

int main () {

    int n ;

    while (cin >> n) {
        map<string, int> m ;
        int totalGames = 0 ;

        for (int i = 0 ; i < n ; ++i) {
            string game ;
            cin >> game ;
            ++m[game] ;
            ++totalGames ;
        }
        int j ;
        cin >> j ;

        for (int i = 0 ; i < j ; ++i) {
            string game ;
            cin >> game ;

            if (canBuy(m, totalGames, game)) {
                ++m[game] ;
                ++totalGames ;
            }
        }
        for (const pair<string, int>& p : m) {
            cout << p.first << ' ' << p.second << endl ;
        }
        cout << string(20, '-') << endl ;
    }
}