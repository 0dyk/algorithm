#include<iostream>
#include<queue>


using namespace std;

int r, c, t, air, ap = 0;
int map[51][51];
int tmap[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void input() {
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				air = i;
			}
			else if (map[i][j] != 0) {
				ap += map[i][j];
			}
		}
	}
}

void cv() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmap[i][j] = map[i][j];
		}
	}
}

void airpolution() {
	cv();
	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			if (tmap[x][y] == 0 || tmap[x][y] == -1 || tmap[x][y] < 5) continue;

			int spread = tmap[x][y] / 5;

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (ny == 0 && (nx == air || nx == air - 1)) continue;

				map[x][y] -= spread;
				map[nx][ny] += spread;
			}
		}
	}
}

void airclean() {
	int x = air - 2;
	int y = 0;
	ap -= map[x][y];
	while (x > 0) {
		map[x][y] = map[x - 1][y];
		x--;
	}
	while (y < c - 1) {
		map[x][y] = map[x][y + 1];
		y++;
	}
	while (x < air - 1) {
		map[x][y] = map[x + 1][y];
		x++;
	}
	while (y > 0) {
		map[x][y] = map[x][y - 1];
		if (map[x][y] == -1) map[x][y] = 0;
		y--;
	}

	x = air + 1;
	y = 0;
	ap -= map[x][y];
	while (x < r - 1) {
		map[x][y] = map[x + 1][y];
		x++;
	}
	while (y < c - 1) {
		map[x][y] = map[x][y + 1];
		y++;
	}
	while (x > air) {
		map[x][y] = map[x - 1][y];
		x--;
	}
	while (y > 0) {
		map[x][y] = map[x][y - 1];
		if (map[x][y] == -1) map[x][y] = 0;
		y--;
	}
}

void solve() {
	
	for (int time = 0; time < t; time++) {
		airpolution();
		airclean();
	}

	cout << ap;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();

	return 0;
}