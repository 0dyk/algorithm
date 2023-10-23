#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 건물의 개수, 규칙의 개수
int N, K;

// 
int lastConstruct;

// 건설시간
int time[1001];

// 건설이 완료되는 시간
int dist[1001];

// 우선 처리해야하는 건물의 개수
int depth[1001];

// 간선 adj[x] = y -> x를 짓고 난 이후에 y를 지을 수 있다.
vector<int> adj[1001];

void solve() {
	
	// 나보다 먼저 처리가 해야할 놈들이 없는 것들 먼저
	// 해당 작업의 완료 시간, 작업 번호
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 1; i <= N; ++i) {
		if (depth[i] == 0) {
			dist[i] = time[i];
			pq.push({ dist[i], i});
		}
	}

	// 탐색 시작
	int curX;
	while (!pq.empty()) {
		int curTime = pq.top().first;
		curX = pq.top().second;
		pq.pop();


		for (int i = 0; i < adj[curX].size(); ++i) {
			int nextX = adj[curX][i];
			int nextTime = dist[curX] + time[nextX];

			// 가장 큰 값으로 갱신
			if (nextTime > dist[nextX]) dist[nextX] = nextTime;

			// 우선적으로 처리해야하는 작업이 없으면
			if (--depth[nextX] == 0) {
				pq.push({dist[nextX], nextX});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;

		// adj, depth, dist 초기화
		for (int i = 1; i <= N; ++i) {
			adj[i].clear();
			depth[i] = 0;
			dist[i] = 0;
		}

		// 건물 당 걸리는 시간(time 덮어쓰기 됨)
		for (int i = 1; i <= N; ++i) cin >> time[i];

		// 건설 순서 x를 건설한 후에 y 건설 가능
		int x, y;
		for (int i = 1; i <= K; ++i) {
			cin >> x >> y;
			++depth[y];
			adj[x].push_back(y);
		}

		// 승리하기 위해 건설해야 하는 건물 번호
		cin >> lastConstruct;

		//solve
		solve();

		// 결과 출력
		cout << dist[lastConstruct] << '\n';
	}

	return 0;
}