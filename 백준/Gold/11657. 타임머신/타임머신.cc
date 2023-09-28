#include<iostream>
#include<vector>
#define INF 2121212121
using namespace std;

int N, M;
vector<pair<int,int>> v[501];
long long dist[501];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		v[s].push_back({e, c});
	}

	//dist[1] = 0;
	for (int i = 2; i <= N; i++) dist[i] = INF;


	bool cycle = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				if (dist[j] == INF) continue; // 아직 방문 안한 곳이면 pass
				if (dist[v[j][k].first] > dist[j] + v[j][k].second) {
					dist[v[j][k].first] = dist[j] + v[j][k].second;
					if (i == N) cycle = true;
				}
			}
		}
	}

	if (cycle) cout << -1 << '\n';
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}

	return 0;
}