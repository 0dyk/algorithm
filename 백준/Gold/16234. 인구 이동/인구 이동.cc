#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

// N : 인구수, L ~ R명 사이
int N, L, R;

// map
int arr[51][51];

bool visited[51][51];

void solve() {
	queue<pair<int, int>> q;
	queue<pair<int, int>> qq;

	int time = 0;
	// 시간 초마다 반복
	while(true) {
		// 시간초마다 초기화
		bool isFinish = true;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				visited[i][j] = false;

		// 탐색 -> 모두 방문한 경우 끝나게 된다.
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				// 이미 체크한 곳이면 패스
				if (visited[i][j]) continue;

				int sum = 0;

				// bfs 탐색
				q.push({ i, j });
				visited[i][j] = true;
				sum += arr[i][j];

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; ++k) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						// 경계, 방문
						if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;

						int tmp = abs(arr[x][y] - arr[nx][ny]);
						if (tmp >= L && tmp <= R) {
							visited[nx][ny] = true;
							sum += arr[nx][ny];
							q.push({ nx,ny });
							qq.push({ nx, ny });
						}
					}
				}

				// 분배하기
				int cur = 0;

				if (!qq.empty()) {
					isFinish = false;
					qq.push({ i, j });
					cur = sum / qq.size();
				}

				while (!qq.empty()) {
					int x = qq.front().first;
					int y = qq.front().second;
					qq.pop();
					
					arr[x][y] = cur;
				}
			}
		}

		if (isFinish) break;

		++time;
	}

	cout << time << '\n';
}


int main() {
	cin >> N >> L >> R;


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	solve();

	return 0;
}