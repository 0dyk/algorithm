#include <iostream>
#include <queue>
using namespace std;

// 수빈이 위치, 동생 위치
int N, K;

int dist[200001];

int main() {
	cin >> N >> K;

	queue<int> q;
	q.push(N);
	dist[N] = 1;

	int res = 0, cnt = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == K) {
			res = dist[x];
			++cnt;
			// q가 남아있고, 그 거리가 현재 dist와 같으면
			while (!q.empty() && dist[q.front()] == res) {
				if (q.front() == x) ++cnt;
				q.pop();
			}

			break;
		}

		// 존재하지 않거나 갱신값이 같으면
		if (x + 1 <= 200000 && (dist[x + 1] == 0 || dist[x + 1] == dist[x] + 1)) {
			dist[x + 1] = dist[x] + 1;
			q.push(x + 1);
		}
		if (x - 1 <= 200000 && (dist[x - 1] == 0 || dist[x - 1] == dist[x] + 1)) {
			dist[x - 1] = dist[x] + 1;
			q.push(x - 1);
		}
		if (x * 2 <= 200000 && (dist[x * 2] == 0 || dist[x*2] == dist[x] + 1)) {
			dist[x * 2] = dist[x] + 1;
			q.push(x*2);
		}
	}

	cout << res - 1 << '\n' << cnt << '\n';

	return 0;
}