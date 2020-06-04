#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	double f, s;
	vector<int> vec(n);
	stack<int> stack;
	for (int i = 0; i < n; ++i) {
		fin >> f >> s >> vec[i];
	}
	for (int i = 0; i < n; ++i) {
		if (!stack.empty() && stack.top() == vec[i]) {
			stack.pop();
		}
		else
			stack.push(vec[i]);
	}
	if (stack.empty() || stack.size()==1) {
		fout << "Yes";
	}
	else
		fout << "No";

	return 0;
}