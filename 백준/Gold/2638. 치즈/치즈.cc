#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int N, M;

int cheese;
vector<pair<int, int>> c;

int arr[101][101];

bool visited[101][101];

void solve() {
	// 바깥 체크
	queue<pair<int, int>> q;
	for (int i = 0; i < N; ++i) {
		if (arr[i][0] == 0) q.push({ i, 0 });
		if (arr[i][M - 1] == 0) q.push({ i, M - 1 });
	}
	for (int i = 0; i < M; ++i) {
		if (arr[0][i] == 0) q.push({ 0, i });
		if (arr[N - 1][i] == 0) q.push({ N - 1, i });
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		arr[x][y] = -1;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != 0) continue;

			arr[nx][ny] = -1;
			q.push({ nx, ny });
		}
	}

	int time = 0;
	while (cheese) {
		++time;
		// 치즈 체크
		for (int i = 0; i < c.size(); ++i) {
			if (c[i].first == -1) continue;

			int cnt = 0;
			for (int j = 0; j < 4; ++j) {
				int nx = c[i].first + dx[j];
				int ny = c[i].second + dy[j];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != -1) continue;
				++cnt;
			}

			if (cnt >= 2) {
				q.push(c[i]);
				c[i].first = -1;
				--cheese;
			}
		}

		// 감염시키기
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			arr[x][y] = -1;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != 0) continue;

				arr[nx][ny] = -1;
				q.push({ nx, ny });
			}
		}
	}

	// 출력
	cout << time << '\n';
}

int main() {
	cin >> N >> M;

	cheese = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				c.push_back({ i,j });
				++cheese;
			}
		}
	}

	solve();

	return 0;
}