#include <iostream>
#include <map>
using namespace std;

int main () {

    int n ;

    while (cin >> n) {
        map<string, string> author2proposal ;

        for (int i = 0 ; i < n ; ++i) {
            string person , proposal ;
            cin >> person >> proposal ;
            author2proposal[proposal] = person ;
        }
        int m ;
        cin >> m ;
        map<pair<string, string>, bool> all_votes ;

        for (int i = 0 ; i < m ; ++i) {
            string name , vote , proposal ;
            cin >> name >> vote >> proposal ;
            all_votes[{name, proposal}] = vote == "SI" ;
        }
        map<string, pair<int, int>> votes_for_proposal ;

        for (const auto& elem : all_votes) {
            if (elem.second) ++votes_for_proposal[elem.first.second].first ;
            else ++votes_for_proposal[elem.first.second].second ;
        }
        for (const auto& p : votes_for_proposal) {
            if (p.second.first > p.second.second) {
                cout << p.first << ", de " << author2proposal[p.first] << ", que ha guanyat " << p.second.first << "-" << p.second.second << endl ;
            }
        }
        cout << string(10, '-') << endl ;
    }
}