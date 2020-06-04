#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

vector <int> num;

vector <int> keys;
vector<int>::iterator i;

void Input(vector < int >& vec) {
	int currentValue;
	while (cin >> currentValue) {
		vec.push_back(currentValue);
		while (true) {
			if (isspace(cin.peek())) {
				if (cin.get() == '\n') {
					return;
				}
			}
			else {
				break;
			}
		}
	}
}

bool binarySearch( int key)
{
	int right = num.size();
	int left = 0;
	while (left < right){
		int k = (left + right) / 2;
		if (key == num[k]) {
			return true;
		}
		else if (key < num[k]) {
			right = k;
		}
		else {
			left = k + 1;
		}
	}
	return false;
}

int lowerBound(int key) {
	int left = 0;
	int right = num.size();
	while (left < right) {
		int k = (left + right) / 2;
		if (key <= num[k])
			right = k;
		else
			left = k + 1;
	}
	return left;
}

int upperBound(int key) {
	int left = 0;
	int right = num.size();
	while (left < right) {
		int k = (left + right) / 2;
		if (key < num[k])
			right = k;
		else
			left = k + 1;
	}
	return left;
}

int main() {

	int len, k;
	cin >> len;
	num.reserve(len);
	Input(num);

	cin >> k;
	keys.reserve(k);
	Input(keys);

	for (i = keys.begin(); i != keys.end(); ++i) {
		cout << binarySearch(*i) << " " << lowerBound(*i) << " " << upperBound(*i);
		cout << endl;
	}
	
	return 0;
}