#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	long long sum = 0;
	typedef istream_iterator<int> input;
	set<int> s((input(cin)), input());
	for (auto it = s.begin(); it != s.end(); ++it) {
		sum += *it;
	}
	cout << sum;
	return 0;
}