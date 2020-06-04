#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;
ifstream fin("expo.in");
ofstream fout("expo.out");

int main(){
	int n, m;
	fin >> n >> m;
	set<int>answer;
	vector<bool>used(n, false);
	for (int i = 0; i < m; i++) {
		int u, v;
		fin >> u >> v;
		if (!used[u-1] && !used[v-1]) {
			answer.insert(u);
			answer.insert(v);
			used[u-1] = true;
			used[v-1] = true;

		}
	}
	fout << answer.size() << endl;
	for (auto it = answer.begin(); it != answer.end(); it++) {
		auto i = it;
		i++;
		if (i ==answer.end()) {
			fout << *it;
		}
		else {
			fout << *it << " ";
		}
	}

	return 0;
}