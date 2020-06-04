#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int>> edge;
vector<bool> visited;
vector<int> mark;
queue<int> Queue;
int c = 0;


int main()
{
	int n;
	fin >> n;
	edge.resize(n);
	visited.resize(n);
	mark.resize(n, 0);

	for (int i = 0; i < n; ++i) {
		visited[i] = false;
		for (int j = 0; j < n; ++j) {
			int x;
			fin >> x;
			if (x) {
				edge[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			Queue.push(i);
			visited[i] = true;
			mark[i] = ++c;
			while (!Queue.empty()) {
				int v = Queue.front();
				for (auto to : edge[v]) {
					if (!visited[to]) {
						Queue.push(to);
						mark[to] = ++c;
						visited[to] = true;
					}
				}
				Queue.pop();
			}
		}
	}

	for (auto m : mark) {
		fout << m << ' ';
	}
	return 0;
}