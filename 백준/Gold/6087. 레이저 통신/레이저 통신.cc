#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

int W, H;
char arr[101][101];
pair<int, int> c1, c2;
const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};
int dist[101][101][4];

void dijkstra(int sx, int sy) {
	memset(dist, 111111, sizeof(dist));

	for (int i = 0; i < 4; i++) dist[sx][sy][i] = 0;

	priority_queue<pair<pair<int,int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
	pq.push({ {-1, -1}, {sx, sy} });

	while (!pq.empty()) {
		int cnt = pq.top().first.first;
		int dir = pq.top().first.second;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			if (i + dir == 3) continue;

			int nc = dir != i ? cnt + 1 : cnt;
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W || arr[nx][ny] == '*') continue;
			if (nc < dist[nx][ny][i]) {
				dist[nx][ny][i] = nc;
				pq.push({ {nc, i}, {nx, ny} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> W >> H;

	c1 = {-1, -1};
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') {
				if (c1.first == -1) c1 = { i, j };
				else c2 = {i, j};
			}
		}
	}
	
	dijkstra(c1.first, c1.second);

	int ans = 987654321;

	for (int i = 0; i < 4; i++) {
		ans = min(ans, dist[c2.first][c2.second][i]);
	}

	cout << ans << '\n';

	return 0;
}