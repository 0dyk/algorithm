#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N;
vector<int> v[200001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	// 마감시간, 컵라면
	int d, s;
	for (int i = 0; i < N; i++) {
		cin >> d >> s;
		// 스코어가 큰 순 -> 마감 날짜가 큰 순으로 정렬 하자
		v[d].push_back(s);
	}

	int sum = 0;
	
	priority_queue<int, vector<int>, less<int>> pq;
	for (int t = N; t > 0; t--) {
		// 현 시간에 먹을 수 있는 컵라면 추가하기
		for (int i = 0; i < v[t].size(); i++) {
			pq.push(v[t][i]);
		}

		// 먹을 수 있는 라면이 있는 경우
		// 가장 맛난 라면 먹기
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum << '\n';

	return 0;
}