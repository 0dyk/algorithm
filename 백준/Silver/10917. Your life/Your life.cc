#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
vector<int> adj[100001];
int dist[100001];

int main() {

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; ++i) {

		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 0; i <= N; ++i) {

		dist[i] = -1;
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < adj[cur].size(); ++i) {

			int next = adj[cur][i];
			if (dist[next] == -1) {

				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}

	cout << dist[N] << '\n';

	return 0;
}