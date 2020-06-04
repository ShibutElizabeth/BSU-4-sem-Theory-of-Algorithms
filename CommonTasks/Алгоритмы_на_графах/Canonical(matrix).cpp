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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            fin >> x;
            if (x) {
                ancestor[j] = i + 1;
            }
        }
    }
    for (auto x : ancestor) {
        fout << x << ' ';
    }
    return 0;
}