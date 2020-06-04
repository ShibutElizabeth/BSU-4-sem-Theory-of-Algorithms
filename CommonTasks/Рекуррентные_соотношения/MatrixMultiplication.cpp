#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");


int multiply(vector<int> vec){
	int n = vec.size() - 1;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}
	int j;
	for (int l = 1; l < n; l++) {
		for (int i = 0; i < n -l; i++) {
			j = i + l;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j],
					dp[i][k] + dp[k + 1][j] + (vec[i] * vec[k + 1] * vec[j+1]));
			}
		}
	}
	return dp[0][n - 1];
}

int main() {
	int s;
	int ku = 0;
	fin >> s;
	vector<int> v(s+1);
	for (int i = 0; i < s + 1; i++) {
		fin >> v[i] >> ku;
	}
	v[s] = ku;
	fout << multiply(v);
	return 0;
}