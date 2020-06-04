#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    
    int n, m;
    fin >> n >> m;
    vector<vector<int>> edge(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        edge[u - 1].push_back(v);
        edge[v - 1].push_back(u);
    }
    for (const auto& list_of_connections : edge) {
        fout << list_of_connections.size();
        for (const auto& to : list_of_connections) {
            fout << ' ' << to;
        }
        fout << endl;
    }
    return 0;
}