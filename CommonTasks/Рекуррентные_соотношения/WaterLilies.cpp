#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	int n;
	fin >> n;
	vector<int> vec(n+1, -1);
	vector<int> f(n + 1, -1);
	vec[0] = 0;
	for (int i = 1; i < n+1; i++) {
		fin >> vec[i];
	}
	f[1] = vec[1];
	f[3] = vec[1] + vec[3];
	for (int i = 3; i < n + 1; i++) {
		f[i] = max(f[i - 2], f[i - 3]) + vec[i];
	}

	fout << f[n];
	
	return 0;
}