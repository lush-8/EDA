#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct Ordenacion {

    string word ;

    Ordenacion(string s) 
    {
        word = s ;
    }

    bool operator() (const string& a, const string& b) const 
    {
        if (a.size() == b.size()) {
            string w = word.substr(0, a.size()) ;

            if (a < w and b >= w) return true ;
            if (b < w and a >= w) return false ;
            return a > b ;
        }
        return a.size() > b.size() ;
    }
};

int main () {

    string word ;

    while (cin >> word) {
        char event ;
        int n_tickets = 0 ;
        int no_tickets = 0 ;
        set<string, Ordenacion> s(word) ;
        map<string, int> code2freq ;

        while (cin >> event and event != 'E') {
            if (event == 'T') ++n_tickets ;
            else if (event == 'S') {
                string code ;
                cin >> code ;
                s.insert(code) ;
                ++code2freq[code] ;
                ++no_tickets ;
            }
            while (n_tickets and not s.empty()) {
                string code = *prev(s.end()) ;
                cout << code << endl ;
                --code2freq[code] ;
                --n_tickets ;
                --no_tickets ;

                if (code2freq[code] == 0) {
                    code2freq.erase(code) ;
                    s.erase(code) ;
                } 
            }
        }
        cout << n_tickets << " ticket(s) left" << endl ;
        cout << no_tickets << " supporter(s) with no ticket" << endl ;
        cout << endl ;
    }
}

int main () {

    for (string word ; cin >> word ; ) {
        int n_tickets = 0 ;
        priority_queue<string, vector<string>, Ordenacion> pq(word) ;
        
        for (char event ; cin >> event and event != 'E' ; ) {
            if (event == 'T') ++n_tickets ;
            else if (event == 'S') {
                string code ;
                cin >> code ;
                pq.push(code) ;
            }
            for ( ; n_tickets and not pq.empty() ; pq.pop() , --n_tickets) {
                cout << pq.top() << endl ;
            }
        }
        cout << n_tickets << " ticket(s) left" << endl ;
        cout << pq.size() << " supporter(s) with no ticket" << endl ;
        cout << endl ;
    }
}