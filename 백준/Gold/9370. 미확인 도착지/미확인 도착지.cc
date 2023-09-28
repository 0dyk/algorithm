#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 200000000
using namespace std;

int n, m, t;

int s, g, h;

vector<pair<int, int>> adjList[2001];
vector<int> res;
int dist[2001][3];

void dijkstra(int st, int pp) {
	// 비용, 현재 위치, 이전 위치
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, st });
	dist[st][pp] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < adjList[now].size(); i++) {
			int next = adjList[now][i].first;
			int nc = cost + adjList[now][i].second;

			if (dist[next][pp] > nc) {
				dist[next][pp] = nc;
				pq.push({ nc, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;

	for (int test_case = 1; test_case <= tc; test_case++) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		// 간선 리스트, 경로 추적 벡터, dist 배열 초기화
		for (int i = 1; i <= n; i++) {
			adjList[i].clear();
			dist[i][0] = INF;
			dist[i][1] = INF;
			dist[i][2] = INF;
		}

		// 결과값 배열 초기화
		res.clear();

		// 간선 입력 받기
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adjList[a].push_back({ b,c });
			adjList[b].push_back({ a,c });
		}

		// 다익스트라 실행
		dijkstra(s, 0);
		dijkstra(g, 1);
		dijkstra(h, 2);


		for (int i = 0; i < t; i++) {
			int ex; cin >> ex;
			if ((dist[ex][0] == dist[g][0] + dist[h][1] + dist[ex][2]) || (dist[ex][0] == dist[h][0] + dist[g][2] + dist[ex][1])) {
				res.push_back(ex);
			}
		}

		sort(res.begin(), res.end());

		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i != res.size() - 1) cout << ' ';
			else cout << '\n';
		}
	}

	return 0;
}