#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

vector <long long> v;

void finds(long long x) {
	int last = x % 10;

	for (int i = 0; i < last; ++i) {
		long long next = x * 10 + i;
		v.push_back(next);
		finds(next);
	}
}

int main() {

	cin >> N;

	for (int i = 0; i <= 9; ++i) {
		v.push_back(i);
		finds(i);
	}

	sort(v.begin(), v.end());

	if (N >= v.size()) cout << -1 << '\n';
	else cout << v[N] << '\n';

	return 0;
}