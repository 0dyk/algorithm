#include<iostream>
#include<vector>

int n, m, mincnt;
char map[10][10];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
//bool visited[10][10][10][10] = { false, };

int rx, ry, bx, by;
std::pair<int, int> hole;

void input() {
	mincnt = 11;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			if (map[i][j] == 'B') {
				bx = i;
				by = j;
			}
			if (map[i][j] == 'O') {
				hole.first = i;
				hole.second = j;
			}
		}
	}
	//visited[rx][ry][bx][by] = true;
}

bool canmove(int x, int y, int t) {	// 구멍에 빠졌거나, 벽을 만나면 이동 불기
	//if (x < 0 || y < 0 || x >= n || y >= m) return false;
	if (map[x + dx[t]][y + dy[t]] == '#' || map[x][y] == 'O') return false;

	return true;
}

void DFS(int rbx, int rby, int bbx, int bby, int cnt, int tilt) {

	if (cnt >= mincnt) return;	// 11회 이상 or 최소 cnt 초과시

	if (rbx == hole.first && rby == hole.second) {
		if (cnt < mincnt) mincnt = cnt;
		return;
	}
	if (bbx == hole.first && bby == hole.second) return;

	for (int i = 0; i < 4; i++) {
		if (tilt == i) continue;

		int nrbx = rbx;
		int nrby = rby;
		int nbbx = bbx;
		int nbby = bby;
		int ncnt = cnt + 1;

		int rc = 0, bc = 0;
		while (canmove(nrbx, nrby, i)) {	// 빨간공 이동
			nrbx += dx[i];
			nrby += dy[i];
			rc++;
		}
		while (canmove(nbbx, nbby, i)) {	// 파란공 이동
			nbbx += dx[i];
			nbby += dy[i];
			bc++;
		}

		if (rc == 0 && bc == 0) continue;	// 못 움직인 경우

		if (nrbx == nbbx && nrby == nbby) {	// 곂쳤을 때 -> 많이 움직인 놈이 한칸 뒤로
			if (nrbx == hole.first && nrby == hole.second) continue;	// 동시에 빠진 경우

			if (rc > bc) {
				nrbx -= dx[i];
				nrby -= dy[i];
			}
			else {
				nbbx -= dx[i];
				nbby -= dy[i];
			}
		}

		// 방문처리가 없어도 무한루프 X

		//visited[nrbx][nrby][nbbx][nbby] = true;
		DFS(nrbx, nrby, nbbx, nbby, ncnt, i);
		//visited[nrbx][nrby][nbbx][nbby] = false;
	}
}

int main() {

	input();
	DFS(rx, ry, bx, by, 0, 5);
	if (mincnt == 11) mincnt = -1;
	std::cout << mincnt;

	return 0;
}