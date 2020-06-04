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
	vector<long long> prev(MAXN);
	vector<long long> seq;

	for (int i = 0; i < n; ++i) {
		d[i] = 1;
		prev[i] = -1;
		for (int j = 0; j < i; ++j) {
			if (vec[j] != 0) {
				if (vec[i] % vec[j] == 0) {
					if (d[i] < d[j] + 1) {
						d[i] = d[j] + 1;
						prev[i] = j;
					}
				}
			}
		}
	}

	long long index = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (ans < d[i]) {
			ans = d[i];
			index = i;
		}
	}
	cout << ans << endl;

	while (index != -1) {
		seq.push_back(index);
		index = prev[index];
	}

	reverse(seq.begin(), seq.end());
	for (int i =0 ; i < seq.size(); ++i) {
		cout << seq[i]+1 << ' ';
	}

	return 0;
}