#include<iostream>
#include<vector>
using namespace std;

int R, C, M;
int map[101][101];
int pos, res;
struct Node {
	int row, col;
	int sp, dir, sz;
	int check;
};

Node sharks[10005];

void init() {
	pos = 0; res = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = 0;
		}
	}
}

void fishing() {
	for (int i = 0; i < R; i++) {
		if (map[i][pos] != 0) {	// 살아 있는 상어
			int idx = map[i][pos];
			map[i][pos] = 0;
			sharks[idx].check = 0;	// 상어 다이
			res += sharks[idx].sz;
			break;
		}
	}
	pos++;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = 0;
		}
	}
}

void movepos(int idx) {
	Node *shark = &sharks[idx];
	int speed = shark->sp;

	while (speed > 0) {
		if (shark->dir == 0) {
			if (shark->row - speed <= 0) {
				speed -= shark->row;
				shark->row = 0;
				shark->dir = 1;
			}
			else {
				shark->row -= speed;
				break;
			}
		}
		else if (shark->dir == 1) {
			if (shark->row + speed >= R - 1) {
				speed -= R - 1 - shark->row;
				shark->row = R - 1;
				shark->dir = 0;
			}
			else {
				shark->row += speed;
				break;
			}
		}
		else if (shark->dir == 2) {
			if (shark->col + speed >= C - 1) {
				speed -= C - 1 - shark->col;
				shark->col = C - 1;
				shark->dir = 3;
			}
			else {
				shark->col += speed;
				break;
			}
		}
		else if (shark->dir == 3) {
			if (shark->col - speed <= 0) {
				speed -= shark->col;
				shark->col = 0;
				shark->dir = 2;
			}
			else {
				shark->col -= speed;
				break;
			}
		}
	}

	if (map[shark->row][shark->col] != 0) {
		Node *shark2 = &sharks[map[shark->row][shark->col]];

		if (shark->sz > shark2->sz) {// 사이즈 비교하고
			shark2->check = 0;
			map[shark->row][shark->col] = idx;
		}
		else {
			shark->check = 0;
		}
	}
	else {
		map[shark->row][shark->col] = idx;
	}
}

void move() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 1; i <= M; i++) {
		if (sharks[i].check) {	// 살아 있는 상어면
			movepos(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> M;
	init();

	for (register int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2) s %= (2 * (R - 1));
		else s %= (2 * (C - 1));

		sharks[i] = {r - 1, c - 1, s, d - 1, z, 1};
		map[r - 1][c - 1] = i;
	}

	fishing();
	while (pos < C) {
		move();
		fishing();
	}

	cout << res;

	return 0;
}