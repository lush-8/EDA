#include <iostream>
#include <map>
using namespace std;

void escriu(const map<string, int>& m) {

    map<string, int>::const_iterator it ;

    for (it = m.begin() ; it != m.end() ; ++it) {
        cout << it->first << " is winning " << it->second << endl ;
    }
}

int main () {

    map<string, int> name2money ;
    string name ;

    while (cin >> name) {
        string op ;
        cin >> op ;

        if (op == "enters") {
            if (name2money.find(name) == name2money.end()) name2money[name] = 0 ;
            else cout << name << " is already in the casino" << endl ;
        }
        else if (op == "leaves") {
            if (name2money.find(name) != name2money.end()) {
                cout << name << " has won " << name2money[name] << endl ;
                name2money.erase(name) ;
            }
            else cout << name << " is not in the casino" << endl ;
        }
        else if (op == "wins") {
            int money ;
            cin >> money ;

            if (name2money.find(name) != name2money.end()) name2money[name] += money ;
            else cout << name << " is not in the casino" << endl ;
        }
    }
    cout << string(10, '-') << endl ;
    escriu(name2money) ;
}