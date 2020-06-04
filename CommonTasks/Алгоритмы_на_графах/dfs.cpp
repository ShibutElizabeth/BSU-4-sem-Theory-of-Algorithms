#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int>> edge;
vector<bool> used;
vector<int> mark;
vector<int> vec;
int c = 0;

void dfs(int v) {
	c++;
	mark[v] = c;
	used[v] = true;
	for (auto to : edge[v]) {
		if (!used[to]) {
			dfs(to);
			
		}
	}
}

int main()
{
	int n;
	fin >> n;
	edge.resize(n);
	used.resize(n);
	mark.resize(n, 0);
	vec.resize(n);
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			fin >> x;
			if (x) {
				edge[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (mark[i] == 0) {
			dfs(i);
		}
		fout << mark[i] << ' ';
	}

	return 0;
}