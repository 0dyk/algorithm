#include<iostream>
#include<queue>
using namespace std;

int n, m;
int map[1001][1001];
int dist[1001][1001];
int dxy[4][2] = { {0, 1}, {0, -1} , {1, 0} , {-1, 0} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) q.emplace(i, j);
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dxy[i][0];
			int ny = y + dxy[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny]) continue;
			if (map[nx][ny] == 1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.emplace(nx, ny);
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && dist[i][j] == 0) cout << -1;
			else cout << dist[i][j];

			if (j != m - 1) cout << ' ';
			else cout << '\n';
		}
	}

	return 0;
}