#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	int n; 
	fin >> n;
	vector<int>a;
	typedef istream_iterator<int> input;
	vector<int>vec((input(fin)), input());
	if (n % 2 == 0) {
		vec.push_back(INT_MAX);
	}
	for (int i = 0; i < (int)(n / 2); ++i) {
		if ((vec[i] > (vec[2 * i + 1])) || (vec[i] > vec[2 * i + 2])) {
			a.push_back(1);
		}
	}
	if (a.size() == 0)
		fout << "Yes";
	else
		fout << "No";
	return 0;
}