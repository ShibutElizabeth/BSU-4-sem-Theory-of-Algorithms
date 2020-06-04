#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int n;
    fin >> n;
    vector<int> ancestor(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        fin >> u >> v;
        ancestor[v - 1] = u;
    }
    for (auto x : ancestor) {
        fout << x << ' ';
    }
    return 0;
}