#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
	fin >> n >> m;
    vector<vector<int>> adjacency_matrix(n,  vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adjacency_matrix[u - 1][v - 1] = 1;
        adjacency_matrix[v - 1][u - 1] = 1;
    }
    for (const auto& row : adjacency_matrix) {
        for (const auto& element : row) {
            fout << element << ' ';
        }
		fout << endl;
    }
    return 0;
}