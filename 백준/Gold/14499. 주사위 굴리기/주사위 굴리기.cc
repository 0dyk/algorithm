#include <iostream>
#include <vector>

using namespace std;

int N, M, x, y, K;

int board[21][21];

vector<int> v;

// 주사위
// 위, 아래, 좌, 우, 앞, 뒤
int dice[6] = { 0, 0, 0, 0, 0, 0 };

// 동 : 1, 서 : 2, 북 : 3, 남 : 4
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

void input() {
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
		}		
	}

	int tmp;
	for (int i = 0; i < K; ++i) {
		cin >> tmp;
		v.push_back(tmp);
	}
}

void rotate(int dir) {
	int tmp;
	// 위, 아래, 좌, 우, 앞, 뒤

	// 동
	if (dir == 1) {
		tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = tmp;
	}
	// 서
	else if (dir == 2) {
		tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = tmp;
	}
	// 북
	else if (dir == 3) {
		tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
	}
	// 남
	else {
		tmp = dice[0];
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = tmp;
	}
}

void solve() {
	for (int i = 0; i < K; ++i) {
		int dir = v[i];

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		x = nx; y = ny;
		rotate(dir);

		if (board[x][y] == 0) {
			board[x][y] = dice[1];
		}
		else {
			dice[1] = board[x][y];
			board[x][y] = 0;
		}

		cout << dice[0] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}