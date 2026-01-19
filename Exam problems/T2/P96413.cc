#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

const int INDEF = -1 ;

void Read(vector<vector<int>>& autors, vector<unordered_set<int>>& treballs) {

    for (int i = 0 ; i < treballs.size() ; ++i) { 
        int n_coautors ;
        cin >> n_coautors ; 

        for (int j = 0 ; j < n_coautors ; ++j) {
            int coautor ;
            cin >> coautor ;
            autors[coautor].push_back(i) ; 
            treballs[i].insert(coautor) ; 
        }
    }
}

void Write(const vector<int>& dist) {

    for (int i = 0 ; i < dist.size() ; ++i) {
        cout << i << " : " ;
        
        if (dist[i] != INDEF) cout << dist[i] ;
        else cout << "no" ;
        cout << endl ;
    }
    cout << string(10, '-') << endl ;
}

int main () {

    int n , t ;

    while (cin >> n >> t) {
        vector<vector<int>> autors(n) ; 
        vector<unordered_set<int>> treballs(t) ; 
        Read(autors, treballs) ;
        vector<int> dist(n, INDEF) ;
        queue<int> q ; 
        dist[0] = 0 ; 
        q.push(0) ; 

        while (not q.empty()) {
            int autor = q.front() ;
            q.pop() ;

            for (int i = 0 ; i < autors[autor].size() ; ++i) {
                int treball = autors[autor][i] ;
                
                for (const int& coautor : treballs[treball]) {
                    if (dist[coautor] == INDEF and coautor != autor) {
                        dist[coautor] = dist[autor] + 1 ;
                        q.push(coautor) ;
                    }
                }
            }
        }
        Write(dist) ;
    }
}