#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void Topological_Sort(unordered_map<string, vector<string>>& graph, unordered_map<string, int>& inDegree, priority_queue<string, vector<string>, greater<string>>& pq, vector<string>& v) {

    while (not pq.empty()) {
        string s = pq.top() ;
        pq.pop() ;
        v.push_back(s) ;

        for (const string& neighbour : graph[s]) {
            --inDegree[neighbour] ;

            if (inDegree[neighbour] == 0) {
                inDegree.erase(neighbour) ;
                pq.push(neighbour) ;
            }
        }
    }
}

int main () {

    int n ;

    while (cin >> n) {
        unordered_map<string, vector<string>> graph ;
        unordered_map<string, int> inDegree ;

        for (int i = 0 ; i < n ; ++i) {
            string s ;
            cin >> s ;
            graph[s] = vector<string>() ;
            inDegree[s] = 0 ;
        }
        int m ;
        cin >> m ;
        
        for (int i = 0 ; i < m ; ++i) {
            string x , y ;
            cin >> x >> y ;
            graph[x].push_back(y) ;
            ++inDegree[y] ;
        }
        priority_queue<string, vector<string>, greater<string>> pq ;

        for (auto it : inDegree) {
            if (it.second == 0) pq.push(it.first) ;
        }
        vector<string> v ;
        Topological_Sort(graph, inDegree, pq, v) ;

        if (v.size() == n) {
            for (int i = 0 ; i < n ; ++i) cout << v[i] ;
            cout << endl ;
        }
        else cout << "NO VALID ORDERING" << endl ;
    }
}