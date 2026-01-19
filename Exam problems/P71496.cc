#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main () {

    int n , m ;

    while (cin >> n >> m) {
        vector<vector<pair<int, int>>> graph(n) ;
        int total = 0 ;

        for (int i = 0 ; i < m ; ++i) {
            int x , y , c ;
            cin >> x >> y >> c ;
            graph[x].push_back({c, y}) ;
            graph[y].push_back({c, x}) ;
            total += c ;
        }
        vector<bool> visited(n, false) ;
        visited[0] = true ;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;

        for (const pair<int, int>& p : graph[0]) pq.push(p) ;
        int size = 1 ;
        int sum = 0 ;

        while (size < n) {
            int cost = pq.top().first ;
            int node = pq.top().second ;
            pq.pop() ;

            if (not visited[node]) {
                visited[node] = true ;

                for (const pair<int, int>& p : graph[node]) pq.push(p) ;
                sum += cost ;
                ++size ;
            }
        }
        cout << total - sum << endl ;
    }
}