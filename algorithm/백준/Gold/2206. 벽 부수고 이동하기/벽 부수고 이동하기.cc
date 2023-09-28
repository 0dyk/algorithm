#include<iostream>
#include<vector>
#include<queue>
#define INF 987654231

using namespace std;

int n, m;
int map[1001][1001];
bool visited[1001][1001][2] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	char a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			map[i][j] = a - '0';
		}
	}

	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0}, {1, 0} });
	visited[0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second.first;
		int w = q.front().second.second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << d;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (map[nx][ny] == 1 && w == 0) {
				visited[nx][ny][1] = true;
				q.push({ {nx, ny},{d + 1, 1} });
			}
			else if (map[nx][ny] == 0 && visited[nx][ny][w] == false) {
				visited[nx][ny][w] = true;
				q.push({ {nx, ny},{d + 1, w} });
			}
		}
	}

	cout << -1;

	return 0;
}