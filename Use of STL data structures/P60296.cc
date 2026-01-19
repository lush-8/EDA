#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Player {
    int elo ;
    bool is_online ;
};

bool ordenacion(const pair<string, Player>& a, const pair<string, Player>& b) {

    if (a.second.elo == b.second.elo) return a.first < b.first ;
    return a.second.elo > b.second.elo ;
}

void escriu(const map<string, Player>& m) {

    vector<pair<string, Player>> v(m.begin(), m.end()) ;
    sort(v.begin(), v.end(), ordenacion) ;
    cout << "RANKING" << endl ;

    for (int i = 0 ; i < v.size() ; ++i) {
        cout << v[i].first << ' ' << v[i].second.elo << endl ;
    }
}

int main () {

    map<string, Player> name2info ;
    const int min_elo = 1200 ;
    string op ;

    while (cin >> op) {
        if (op == "LOGIN") {
            string name ;
            cin >> name ;
            
            if (name2info.find(name) != name2info.end()) {
                if (not name2info[name].is_online) {
                    name2info[name].is_online = true ;
                }
            }
            else {
                name2info[name].elo = min_elo ;
                name2info[name].is_online = true ;
            }
        }
        else if (op == "LOGOUT") {
            string name ;
            cin >> name ;

            if (name2info.find(name) != name2info.end()) {
                if (name2info[name].is_online) {
                    name2info[name].is_online = false ;
                }
            }
        }
        else if (op == "PLAY") {
            string n1 , n2 ;
            cin >> n1 >> n2 ;

            if (name2info.find(n1) != name2info.end() and name2info.find(n2) != name2info.end()) {
                if (name2info[n1].is_online and name2info[n2].is_online) {
                    name2info[n1].elo += 10 ;
                    name2info[n2].elo -= 10 ;
                    
                    if (name2info[n2].elo < min_elo) name2info[n2].elo = min_elo ;
                }
                else cout << "jugador(s) no connectat(s)" << endl ;
            }
            else cout << "jugador(s) no connectat(s)" << endl ;
        }
        else if (op == "GET_ELO") {
            string name ;
            cin >> name ;
            cout << name << ' ' << name2info[name].elo << endl ;
        }
    }
    cout << endl ;
    escriu(name2info) ;
}