#include<iostream>
#include<vector>
#include<queue>
#define MAXN 32100
using namespace std;

// 문제 수 <= 32,000
int N, M;

// 진입차수
int degree[MAXN];

// 간선
vector<int> edge[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		// a는 b보다 먼저 푸는게 좋다. -> a 풀고 난 후에 b를 고려하자
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		degree[b]++;
	}

	//
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			pq.push(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (pq.size() == 0) break;

		int now = pq.top(); pq.pop();

		cout << now;
		if (i == N) cout << '\n';
		else cout << ' ';

		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i];

			degree[next] -= 1;

			// 나는 고려할거 다 고려했는데 하는 친구들
			if (degree[next] == 0) {
				pq.push(next);
			}
		}
	}

}