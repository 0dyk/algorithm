#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// N명, M번 비교
int N, M;

int depth[32001];

vector<int> v[32001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; ++i) {
		// A가 B보다 앞에 서야한다.
		cin >> a >> b;
		++depth[b];
		v[a].push_back(b);
	}

	queue<int> q;

	for (int i = 1; i <= N; ++i) {
		if (depth[i] == 0) q.push(i);
	}

	vector<int> res;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		res.push_back(x);

		for (int i = 0; i < v[x].size(); ++i) {
			int nx = v[x][i];

			if (depth[nx] == 0) continue;
			
			if (--depth[nx] == 0) {
				q.push(nx);
			}
		}
	}

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i];
		if (i != res.size() - 1) cout << ' ';
		else cout << '\n';
	}

	return 0;
}