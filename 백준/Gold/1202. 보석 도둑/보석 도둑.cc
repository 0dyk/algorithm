#include<iostream>
#include<queue>
#include<set>
using namespace std;

int N, K;

struct comp {
	// 가치가 가장 큰 놈 부터
	bool operator()(pair<int, int> a, pair<int, int> b) {
		// 가치가 같으면 무게가 작은 순 부터
		if (a.second == b.second) return a.first > b.first;
		else return a.second < b.second;
	}
};

// 보석 : 무게, 가치
priority_queue<pair<int, int>, vector<pair<int, int>>, comp> juwel;

// 가방 입력
multiset<int> bag;

// 최대 값
long long res;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;

	int m, v;
	for (int i = 0; i < N; i++) {
		cin >> m >> v;
		juwel.push({m, v});
	}
	int b;
	for (int i = 0; i < K; i++) {
		cin >> b;
		bag.insert(b);
	}

	res = 0;

	while (!juwel.empty()) {
		if (bag.empty()) break;

		int weight = juwel.top().first;
		int value = juwel.top().second;
		juwel.pop();

		// 보석을 넣을 수 있는가?

		multiset<int>::iterator iter = bag.lower_bound(weight);

		// 넣을 수 있으면
		if (iter != bag.end() && *iter >= weight) {
			bag.erase(iter);
			res += value;
		}
	}

	cout << res << '\n';

	return 0;
}