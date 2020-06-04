#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
 
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
 
const int MAX = 100;
vector<vector<int>> g(MAX, vector<int>(MAX, 0));
vector<vector<bool>> used;
set<pair<int, int>> answer;
int c;
int n = 0;
 
void find(int v) {
  if (!used[c][v]) {
    if (g[c][v] > 50) {
      used[c][v] = true;
      answer.insert(make_pair(c + 1, v + 1));
      return;
    }
    int sum = g[c][v];
    for (int to = 0; to < n; to++) {
      if (used[c][to]) {
        sum += g[to][v];
      }
    }
    if (sum > 50) {
      used[c][v] = true;
      answer.insert(make_pair(c + 1, v + 1));
    }
  }
}
 
int main() {
 
  while (fin.is_open()) {
    int u, v, w;
    while (fin >> u >> v >> w) {
      g[u - 1][v - 1] = w;
      if (u < v && n < v) {
        n = v;
      }
      else if (v < u && n < u) {
        n = u;
      }
    }
    fin.close();
  }
 
  g.resize(n, vector<int>(n));
  used.resize(n, vector<bool>(n, false));
 
  while (true) {
    int cur_size = answer.size();
    for (c = 0; c < n; c++) {
      for (int v = 0; v < n; v++) {
        if (c != v) {
          find(v);
        }
      }
    }
    if (cur_size == answer.size()) {
      break;
    }
  }
 
  int i = 0;
  for (auto& x : answer) {
    if (i != answer.size() - 1) {
      fout << x.first << " " << x.second << endl;
    }
    else {
      fout << x.first << " " << x.second;
    }
    i++;
  }
  return 0;
}