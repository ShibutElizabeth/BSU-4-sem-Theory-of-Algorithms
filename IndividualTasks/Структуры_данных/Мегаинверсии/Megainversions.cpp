#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int upperSize(int n) {
	int upper = 1;
	while (upper < n)
		upper <<= 1;
	return upper;
}
struct Struct {
	vector<int> vec;
	Struct(int n) : vec(upperSize(n)+1, 0) {}
	int sum(int r) {
		int res = 0;
		while (r >= 0) {
			res += vec[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
	}
	void incElement(int i) {
		while (i < vec.size()) {
			vec[i]++;
			i = (i | (i + 1));
		}
	}
};

int main() {
	int n;
	fin >> n;
	long long  res = 0;
	Struct a(n);
	Struct bigger(n);
	Struct inversions(n);
	Struct smaller(n);
	for (int i = 1; i <= n; ++i) {
		fin >> a.vec[i];
	}
	for (int i = 1; i <= n; i++) {
		inversions.incElement(a.vec[i]);
		bigger.vec[i] = i -inversions.sum(a.vec[i]);
	}
	for (int i = n; i >= 1; i--) {
		smaller.incElement(a.vec[i]);
		res += 1LL * bigger.vec[i] * smaller.sum(a.vec[i] - 1);
	}
	fout << res;
	return 0;
}