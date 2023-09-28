#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int R, C, K, M;
int map[21][21];
bool walls[21][21][21][21];

// 조사할 칸 : 좌표
vector<pair<int, int>> josa;

// 온풍기 정보 : 좌표, 방향
vector<pair<pair<int, int>, int>> air;

// 왼쪽 오른쪽 위쪽 아래쪽 탐색
int dix[4][3] = { {-1,0,1}, {-1,0,1}, {-1,-1,-1}, {1,1,1} };
int diy[4][3] = { {1,1,1}, {-1,-1,-1}, {-1,0,1}, {-1,0,1} };

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void input() {
	cin >> R >> C >> K;
	for (int row = 1; row <= R; row++) {
		for (int col = 1; col <= C; col++) {
			int tmp; cin >> tmp;
			if (tmp >= 1 && tmp <= 4) air.push_back({ {row,col}, tmp - 1 });
			if (tmp == 5) josa.push_back({ row,col });
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 0) {
			walls[a][b][a - 1][b] = true;
			walls[a - 1][b][a][b] = true;
		}
		else {
			walls[a][b][a][b + 1] = true;
			walls[a][b + 1][a][b] = true;
		}
	}
}

void aircon() {
	for (int idx = 0; idx < air.size(); idx++) {
		bool visited[21][21] = { false, };

		int dir = air[idx].second;

		int fx = air[idx].first.first + dix[dir][1];
		int fy = air[idx].first.second + diy[dir][1];

		queue<pair<pair<int, int>, int>> q;
		map[fx][fy] += 5;
		q.push({ {fx,fy}, 4 });

		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int cost = q.front().second;
			q.pop();

			for (int k = 0; k < 3; k++) {
				int nx = x + dix[dir][k];
				int ny = y + diy[dir][k];

				if (nx < 1 || nx > R || ny < 1 || ny > C || visited[nx][ny]) continue;

				// 왼쪽 오른쪽 위쪽 아래쪽 탐색
				// int dix[4][3] = { {-1,0,1}, {-1,0,1}, {-1,-1,-1}, {1,1,1} };
				// int diy[4][3] = { {1,1,1}, {-1,-1,-1}, {-1,0,1}, {-1,0,1} };
				if (k == 1) {
					if (walls[x][y][nx][ny]) continue;
				}
				else {
					int tx = x;
					int ty = y;
					if (dir == 0 || dir == 1) tx += dix[dir][k];
					else ty += diy[dir][k];

					if (walls[x][y][tx][ty] || walls[tx][ty][nx][ny]) continue;
				}

				map[nx][ny] += cost;
				visited[nx][ny] = true;
				if (cost != 1) q.push({ {nx, ny}, cost - 1 });
			}
		}
	}
}

void jojol() {
	int tmp[21][21] = { 0, };

	for (int row = 1; row <= R; row++) {
		for (int col = 1; col <= C; col++) {
			for (int dir = 0; dir < 4; dir += 3) {
				int nrow = row + dx[dir];
				int ncol = col + dy[dir];

				if (nrow < 1 || nrow > R || ncol < 1 || ncol > C) continue;
				if (walls[row][col][nrow][ncol]) continue;
				int dif = (map[row][col] - map[nrow][ncol]) / 4;

				tmp[row][col] -= dif;
				tmp[nrow][ncol] += dif;
			}
		}
	}

	for (int row = 1; row <= R; row++) {
		for (int col = 1; col <= C; col++) {
			map[row][col] += tmp[row][col];
		}
	}
}

void gajang() {
	for (int row = 1; row <= R; row++) {
		if (map[row][1] >= 1) map[row][1]--;
		if (map[row][C] >= 1) map[row][C]--;
	}
	for (int col = 2; col < C; col++) {
		if (map[1][col] >= 1) map[1][col]--;
		if (map[R][col] >= 1) map[R][col]--;
	}
}

bool josahaja() {
	for (int i = 0; i < josa.size(); i++) {
		if (map[josa[i].first][josa[i].second] < K) return false;
	}
	return true;
}

int main() {

	input();

	int choco = 0;
	while (choco <= 100) {
		aircon();
		jojol();
		gajang();
		choco++;
		if (josahaja()) break;
	}

	cout << choco << '\n';

	return 0;
}