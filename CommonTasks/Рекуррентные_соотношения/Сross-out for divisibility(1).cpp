#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 8000;
int main() {
	long long n;
	cin >> n;

	vector<long long> vec(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		vec[i] = k;
	}

	vector<long long> d(MAXN);
	
	for (int i = 0; i < n; ++i) {
		d[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (vec[j] != 0) {
				if (vec[i] % vec[j] == 0) {
					d[i] = max(d[i], d[j] + 1);
				}
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, d[i]);
	}

	cout << (vec.size() - ans);

	return 0;
}