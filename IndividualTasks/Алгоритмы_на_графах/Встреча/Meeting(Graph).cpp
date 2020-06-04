#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");

const int MAX = 1000000000;

int main() {
	int n, m;
	fin >> n >> m;
	
	vector<vector<int>> g(n, vector<int>(n,MAX));
	vector<int>distance(n, 0);
	
	for (int i = 0; i < m; i++) {
		int u, v, w;
		fin >> u >> v >> w;
		g[u - 1][v - 1] = w;
		g[v - 1][u - 1] = w;
		
		if (m == 1) {
			fout << u << " " << v << " " << w / 2;
			return 0;
		}	
	}
	for (int i = 0; i < n; i++) {
		g[i][i] = 0;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);	
			}
		}
	}
	
	int house = 0;
	int min = MAX;
	for (int i = 0; i < n; i++) {
		distance[i] = accumulate(g[i].begin(), g[i].end(), 0);
		if (distance[i] < min) {
			min = distance[i];
			house = i + 1;
		}
	}
	
	fout << house << " " << min;
	return 0;
}