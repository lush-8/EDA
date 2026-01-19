#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Gate {
    string type ;
    string output ;
    vector<string> input ;
};

void read(vector<string>& v) {

    string s ;

    while (cin >> s and s != "END") v.push_back(s) ;
}

vector<string> Topological_Sort(const vector<string>& inputs, const vector<Gate>& logic_gates, unordered_map<string, vector<string>>& graph, unordered_map<string, int>& inDegree) {

    queue<string> q ;
    vector<string> result ;

    for (auto it = inDegree.begin() ; it != inDegree.end() ; ++it) {
        if (it->second == 0) q.push(it->first) ;
    }
    while (not q.empty()) {
        string node = q.front() ;
        q.pop() ;
        result.push_back(node) ;

        for (const string& neighbour : graph[node]) {
            --inDegree[neighbour] ;

            if (inDegree[neighbour] == 0) {
                inDegree.erase(neighbour) ;
                q.push(neighbour) ;
            }
        }
    }
    return result ;
}

void evaluate_circuit(const vector<string>& outputs, const vector<Gate>& logic_gates, const vector<string>& order, unordered_map<string, bool>& values) {

    for (const string& node : order) {
        for (const Gate& gate : logic_gates) {
            if (gate.output == node) {
                if (gate.type == "AND") values[gate.output] = values[gate.input[0]] and values[gate.input[1]] ;
                else if (gate.type == "OR") values[gate.output] = values[gate.input[0]] or values[gate.input[1]] ;
                else values[gate.output] = not values[gate.input[0]] ;
            }
        }
    }
    for (int i = 0 ; i < outputs.size() ; ++i) {
        if (i != 0) cout << ' ' ;
        cout << (values[outputs[i]] ? 'T' : 'F') ;
    }
    cout << endl ;
}

int main () {

    string s ;
    cin >> s ;
    vector<string> outputs ;
    read(outputs) ;
    cin >> s ;
    vector<string> inputs ;
    read(inputs) ;
    unordered_map<string, vector<string>> graph ;
    unordered_map<string, int> inDegree ;

    for (const string& input : inputs) inDegree[input] = 0 ;
    vector<Gate> logic_gates ;
    cin >> s ;

    while (s != "END") {
        Gate gate ;
        gate.type = s ;
        cin >> gate.output ;
        inDegree[gate.output] = 0 ;

        if (s == "AND" or s == "OR") {
            for (int i = 0 ; i < 2 ; ++i) {
                string in ;
                cin >> in ;
                gate.input.push_back(in) ; 
                graph[in].push_back(gate.output) ;
                ++inDegree[gate.output] ;
            }
        }
        else {
            string in ;
            cin >> in ;
            gate.input.push_back(in) ;
            graph[in].push_back(gate.output) ;
            ++inDegree[gate.output] ;
        }
        logic_gates.push_back(gate) ;
        cin >> s ;
    }
    vector<string> order = Topological_Sort(inputs, logic_gates, graph, inDegree) ;
    char c ;

    while (cin >> c) {
        vector<bool> input_values ;
        unordered_map<string, bool> values ;
        input_values.push_back(c == 'T') ;
        values[inputs[0]] = c == 'T' ;

        for (int i = 1 ; i < inputs.size() ; ++i) {
            cin >> c ;
            input_values.push_back(c == 'T') ;
            values[inputs[i]] = c == 'T' ;
        }
        evaluate_circuit(outputs, logic_gates, order, values) ;
    }
}