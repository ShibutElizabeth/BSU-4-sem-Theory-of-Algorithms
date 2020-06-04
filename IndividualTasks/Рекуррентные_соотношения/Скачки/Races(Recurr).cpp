#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
 
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
 
struct Vertex {
	int y;
	int x;
	int v = 0; 
	int k = 0;
	int step = 0;
};
 
int m, n;
int  maxV = 0, maxK = 0;
int xStart = 0;
int yStart = 0;
vector<vector<int>> trace;
queue<Vertex> q;
vector<vector<vector<vector<int>>>> dp;
Vertex s;
 
bool isMatrix(int y, int x) {
	return (x < n && y < m && x >= 0 && y >= 0);
}
 
void ways(int y, int x, int v1, int k,  int step) {
 
		int y1, x1;
		//right up
		for (int i = 0; i <= v1; i++) {
			y1 = y - v1 + i;
			x1 = x + i;
			if (isMatrix(y1, x1)) {
				if (trace[y1][x1] == 0 || trace[y1][x1] == 3|| trace[y1][x1]==4) {
					if (dp[y1][x1][v1][k] != 0) {
						Vertex vertex = { y1, x1 , v1, k, step + 1 };
						dp[y1][x1][v1][k] = 0;
						q.push(vertex);
					}
				}
			}
 
		}
		//right down
		for (int i = 0; i <= v1; i++) {
			x1 = x + v1 - i;
			y1 = y + i;
			if (isMatrix(y1, x1)) {
				if (trace[y1][x1] == 0 || trace[y1][x1] == 3 || trace[y1][x1] == 4) {
					if (dp[y1][x1][v1][k] != 0) {
						Vertex vertex = { y1, x1 , v1, k, step + 1 };
						dp[y1][x1][v1][k] = 0;
						q.push(vertex);
					}
				}
			}
 
		}
		//left down
		for (int i = 0; i <= v1; i++) {
			y1 = y + v1 - i;
			x1 = x - i;
			if (isMatrix(y1, x1)) {
				if (trace[y1][x1] == 0 || trace[y1][x1] == 3 || trace[y1][x1] == 4) {
					if (dp[y1][x1][v1][k] != 0) {
						Vertex vertex = { y1, x1 , v1, k, step + 1 };
						dp[y1][x1][v1][k] = 0;
						q.push(vertex);
					}
				}
			}
 
		}
		//left up
		for (int i = 0; i <= v1; i++) {
			x1 = x - v1 + i;
			y1 = y - i;
			if (isMatrix(y1, x1)) {
				if (trace[y1][x1] == 0 || trace[y1][x1] == 3 || trace[y1][x1] == 4) {
					if (dp[y1][x1][v1][k] != 0) {
						Vertex vertex = { y1, x1 , v1, k, step + 1 };
						dp[y1][x1][v1][k] = 0;
						q.push(vertex);
					}
				}
			}
		}
 
}
 
int main() {
 
	fin >> m >> n;
	trace.resize(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			fin >> a;
			trace[i][j] = a;
			if (a == 4) {
				xStart = j;
				yStart = i;
			}
		}
	}
	fin >> maxV >> maxK;
 
	vector<int> vec;
	dp.resize(m+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(maxV+1, vector<int>(maxK+1, 500))));
 
	s.y = yStart;
	s.x = xStart;
	q.push(s);
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int v = q.front().v;
		int k = q.front().k;
		int step = q.front().step;
		q.pop();
 
			if (trace[y][x] == 3) {
				vec.push_back(step);
				continue;
			}
			/*if (v == 0) {
				v1 = v + 1;
				ways(y, x, v1, k, step);
			}*/
			if (v < maxV) {
				if (v != 0) {
					ways(y, x, v - 1, 0, step);
				}
				ways(y, x, v, 0, step);
				if (v + 1 == maxV) {
					ways(y, x, v + 1, 1, step);
				} else {
					ways(y, x, v + 1, 0, step);
				}
				continue;
 
			}
			if (v == maxV) {
				if (k < maxK) {
					ways(y, x, v, k + 1, step);
					ways(y, x, v - 1, 0, step);
				}
				if (k == maxK) {
					ways(y, x, v - 1, 0, step);
				}
			}	
	}
	if (vec.size() == 0) {
		fout << -1;
	}
	else {
		int minElementIndex = std::min_element(vec.begin(), vec.end()) - vec.begin();
		int minElement = *std::min_element(vec.begin(), vec.end());
		fout << minElement;
 
	}
	return 0;
}