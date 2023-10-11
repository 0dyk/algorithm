#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, M;

// 비용, a, b집
vector<pair<int, pair<int, int>>> v;

int cnt;

int parent[100001];

int find(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}

bool unions(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa == pb) return false;

	parent[pb] = pa;
	return true;
}

int main() {
	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		// a, b 연결, 비용 c
		v.push_back({ c,{a,b} });
	}

	cnt = N;
	for (int i = 1; i <= N; i++) parent[i] = i;

	sort(v.begin(), v.end());

	// 비용의 합
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {

		if (cnt > 2) {
			if (unions(v[i].second.first, v[i].second.second)) {
				sum += v[i].first;
				cnt--;
			};
		}
	}

	cout << sum << '\n';

	return 0;
}