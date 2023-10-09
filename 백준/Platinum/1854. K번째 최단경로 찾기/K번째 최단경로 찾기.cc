#include<iostream>
#include<queue>

using namespace std;

struct pairCmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
};

int N, M, K;

vector<pair<int, int>> adj[1001];

priority_queue<int, vector<int>, less<int>> ct[1001];

void dijkstra() {

	priority_queue<pair<int,int>, vector<pair<int, int>>, pairCmp> pq;
	pq.push({1, 0});
	ct[1].push(0);

	while (!pq.empty()) {
		int x = pq.top().first;
		int c = pq.top().second;
		pq.pop();

		for (int i = 0; i < adj[x].size(); i++) {
			int nx = adj[x][i].first;
			int nc = adj[x][i].second;

			// 경로를 더 구해야함.
			if (ct[nx].size() < K) {
				ct[nx].push(c + nc);
				pq.push({ nx, c + nc });
			}
			else {
				// 최단 경로만 구해야 하므로
				// 갱신이 안되면 q에 안넣어도 됩.
				if (c + nc < ct[nx].top()) {
					ct[nx].pop();
					ct[nx].push(c + nc);
					pq.push({ nx, c + nc });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> K;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
	}

	dijkstra();

	for (int i = 1; i <= N; i++) {
		if (ct[i].size() != K) cout << -1 << '\n';
		else cout << ct[i].top() << '\n';
	}

	return 0;
}