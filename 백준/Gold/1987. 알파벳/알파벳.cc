#include<iostream>
using namespace std;

int N, M, maxDist;
int check[26] = { 0, };
char arr[20][20];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y, int cnt) {
	if (cnt > maxDist) maxDist = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M || check[arr[nx][ny] - 'A']) continue;
		
		check[arr[nx][ny] - 'A'] = 1;
		dfs(nx, ny, cnt + 1);
		check[arr[nx][ny] - 'A'] = 0;
	}
}

int main() {
	cin >> N >> M;
	maxDist = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	check[arr[0][0] - 'A'] = 1;
	dfs(0, 0, 0);

	cout << maxDist + 1;

	return 0;
}