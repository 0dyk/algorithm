#include<iostream>
#include<vector>
#include<queue>
#define INF 1987654321

// 컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터 번호
int N, D, C;

std::vector<std::pair<int, int>> v[10001];

int dist[10001];
bool visited[10001];

int main() {
	
	int T; std::cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		std::cin >> N >> D >> C;

		// 초기화
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			dist[i] = INF;
			visited[i] = false;
			v[i].clear();
		}


		int a, b, s;
		for (int i = 0; i < D; i++) {
			// a가 b를 의존, b가 감염되면 s초 후 a도 감염
			std::cin >> a >> b >> s;

			// b -> a; 단방향
			v[b].push_back({ a, s });
		}

		// 다익스트라
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

		pq.push({0, C});
		dist[C] = 0;

		while (!pq.empty()) {
			int x = pq.top().second;
			pq.pop();

			// 처음 방문하는 경우만
			if (visited[x]) continue;
			visited[x] = true;
			++cnt;

			for (int i = 0; i < v[x].size(); i++) {
				int nx = v[x][i].first;
				int ncost = dist[x] + v[x][i].second;

				// 초기화가 안되면
				if (dist[nx] <= ncost) continue;

				dist[nx] = ncost;
				pq.push({ncost, nx});
			}
		}

		int time = 0;
		// 최대값
		for (int i = 1; i <= N; i++) {
			if (dist[i] != INF && dist[i] > time) time = dist[i];
		}

		std::cout << cnt << ' ' << time << '\n';
	}

	return 0;
}










