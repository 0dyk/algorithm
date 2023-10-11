#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001];
vector<int> v;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int minV = 2100000000;
	int a, b;

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {

		int k = lower_bound(v.begin(), v.end(), -v[i]) - v.begin();

		for (int j = k - 1; j <= k + 1; j++) {
			if (j < 0 || j >= N || i == j) continue;
			
			if (minV > abs(v[i] + v[j])) {
				minV = abs(v[i] + v[j]);
				a = v[i];
				b = v[j];
			}
		}
	}

	if (a > b) swap(a, b);
	cout << a << ' ' << b << '\n';

	return 0;
}