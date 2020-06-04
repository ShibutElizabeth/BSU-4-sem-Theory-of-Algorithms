#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	long long num;
	fin >> num;
	vector<long long>t;
	if (true) {
		while (num) {
			t.push_back(num % 2);
			num = (long long)(num / 2);
		}
		for (int i = 0; i < t.size(); ++i) {
			if (t[i] == 1) {
				if (i != t.size()-1) {
					fout << i << endl;
				}
				else
					fout << i;
			}
		}
	}
	else {
		fout << -1;
	}
	
	return 0;
}