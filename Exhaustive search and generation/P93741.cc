#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool Satisfied(const vector<string>& clause, const unordered_map<char, bool>& assignment) {

    for (const string& literal : clause) {
        bool negated = (literal[0] == '-') ;
        char variable = negated ? literal[1] : literal[0] ;

        if (assignment.at(variable) != negated) return true ;
    }
    return false ;
}

void BackTrack(int idx, vector<char>& variables, const vector<vector<string>>& clauses, unordered_map<char, bool>& assignment, vector<unordered_map<char, bool>>& solutions) {

    if (idx == variables.size()) {
        bool satisfied = true ;

        for (const vector<string>& clause : clauses) {
            if (not Satisfied(clause, assignment)) {
                satisfied = false ;
                break ;
            }
        }
        if (satisfied) solutions.push_back(assignment) ;
        return ;
    }
    assignment[variables[idx]] = true ;
    BackTrack(idx + 1, variables, clauses, assignment, solutions) ;
    assignment[variables[idx]] = false ;
    BackTrack(idx + 1, variables, clauses, assignment, solutions) ;
}

int main() {

    int n , m ;
    cin >> n >> m ;
    vector<char> variables(n) ;

    for (int i = 0 ; i < n ; ++i) {
        variables[i] = 'a' + i ;
    }
    vector<vector<string>> clauses(m) ;

    for (int i = 0 ; i < m ; ++i) {
        clauses[i].resize(3) ;

        for (int j = 0 ; j < 3 ; ++j) {
            cin >> clauses[i][j] ;
        }
    } 
    unordered_map<char, bool> assignment ;
    vector<unordered_map<char, bool>> solutions ;
    BackTrack(0, variables, clauses, assignment, solutions) ;

    if (solutions.empty()) cout << '-' << endl ;
    else for (const auto& sol : solutions) {
        for (int i = 0 ; i < variables.size() ; ++i) {
            if (i > 0) cout << ' ' ;
            if (sol.at(variables[i])) cout << variables[i] ;
            else cout << '-' << variables[i] ;
        }
        cout << endl ;
    }
}