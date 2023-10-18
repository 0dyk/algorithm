#include <iostream>
#include <vector>
#include <queue>
#define INF 1987654321
using namespace std;

// 도시, 버스
int N, M;

// 출발, 도착
int st, en;

// 간선
vector<pair<int, int>> v[1001];


long long dist[1001];
int preCity[1001];

struct node {
	int x;
	long long cost;
	int pre;
};

struct COMP {
	bool operator()(node a, node b) {
		return a.cost > b.cost;
	}
};

void solve() {
	
	for (int i = 1; i <= N; ++i) {
		dist[i] = INF;
	}

	// 위치, 비용, 이전 위치
	priority_queue<node, vector<node>, COMP> pq;
	pq.push({st, 0, 0});
	dist[st] = 0;

	while (!pq.empty()) {
		node cur = pq.top();
		int x = cur.x;
		pq.pop();

		if (x == en && dist[x] != 0) break;

		for (int i = 0; i < v[x].size(); ++i) {
			int nx = v[x][i].first;
			long long nc = dist[x] + v[x][i].second;

			if (dist[nx] <= nc) continue; 

			// 이전 방문 위치
			preCity[nx] = x;

			dist[nx] = nc;
			pq.push({ nx, nc, x });
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		// a에서 b로 가는 비용 c
		v[a].push_back({ b,c });
	}

	cin >> st >> en;

	solve();

	cout << dist[en] << '\n';
	
	vector<int> res;

	int k = en;
	while(k != 0) {
		res.push_back(k);
		k = preCity[k];
	}

	cout << res.size() << '\n';

	for (int i = res.size() - 1; i >= 0; --i) {
		cout << res[i];

		if (i != 0) cout << ' ';
		else cout << '\n';
	}

	return 0;
}