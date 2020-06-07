#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int MAX = 1000000000;
int n, m;
int A, B, C;

struct Edge {
	int from;
	int where;
	int capacity;
	int flow;
	int inverseIndex;
	Edge(int _from, int _where, int _capacity, int _flow, int _inverseIndex) :
		from(_from), where(_where), capacity(_capacity), flow(_flow), inverseIndex(_inverseIndex) {};
};

vector<vector<Edge>> edge;
vector<int> level;
vector<int> isVisited;

void addEdge(int u, int v, int capacity = 1) {
	/*Edge e1 = { u,v,capacity,0, edge[v].size() };
	Edge e2 = { v,u,0,0, edge[v].size() - 1 };*/
	edge[u].emplace_back(u, v, capacity, 0, edge[v].size());
	edge[v].emplace_back(v, u, 0, 0, edge[u].size() - 1);
}

int bfs(int s, int t) {
	for (int i = 0; i < level.size(); ++i) {
		level[i] = MAX;
	}

	level[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (auto& to : edge[v]) {
			if (level[to.where] == MAX && to.flow < to.capacity) {
				level[to.where] = 1 + level[v];
				q.push(to.where);
			}
		}
	}
	return level[t] != MAX;
}

int dfs(int v, int t, int currFlow) {
	if (v == t) {
		return currFlow;
	}
	if (currFlow == 0) {
		return currFlow;
	}

	for (; isVisited[v] < edge[v].size(); ++isVisited[v]) {
		auto& currEdge = edge[v][isVisited[v]];
		int to = currEdge.where;
		if (level[to] == 1 + level[v] && currEdge.flow < currEdge.capacity) {
			int mainFlow = min(currFlow, currEdge.capacity - currEdge.flow);
			int returnedFlow = dfs(to, t, mainFlow);
			if (returnedFlow) {
				currEdge.flow += returnedFlow;
				edge[to][currEdge.inverseIndex].flow -= returnedFlow;
				return returnedFlow;
			}
		}
	}
	return 0;
}


int main(){
	
	fin >> n >> m;

	edge.resize(2 * n + 2);
	level.resize(2 * n + 2);
	isVisited.resize(2 * n + 2);
	
	for (int i = 0; i < m; ++i) {
		int u, v;
		fin >> u >> v;

		addEdge(2 * u + 1, 2 * v);
		addEdge(2 * v + 1, 2 * u);
	}
	
	for (int i = 1; i <= n; ++i) {
		addEdge(2 * i, 2 * i + 1);
	}

	fin >> A >> B >> C;
	
	int source = 0;
	int trash = 1;

	addEdge(source, 2 * A);
	addEdge(source, 2 * B);
	addEdge(2 * C, trash, 2);

	int flow = 0;
	while (bfs(source, trash)) {
		for (int i = 0; i < isVisited.size(); ++i) {
			isVisited[i] = 0;
		}

		while (true) {
			int newFlow = dfs(source, trash, MAX);
			flow += newFlow;
			if (!newFlow) {
				break;
			}
		}
	}
	if (flow == 2) {
		fout << "Yes";
	}
	else {
		fout << "No";
	}

	return 0;
}
