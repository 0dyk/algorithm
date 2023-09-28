#include<iostream>
using namespace std;

int R, C, T;
int arr[51][51];
int air;
int dxy[4][2] = { {0,1}, {0,-1}, {1, 0}, {-1, 0} };

/*
 * 미세먼지 확산.
 * N * N 탐색 미세 먼지 발견 시 확산하여
 * tmp에 저장
 * arr에 템프 덮어씌우기
*/
void pm() {
	int tmp[51][51] = {0, };
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (arr[r][c] == 0 || arr[r][c] == -1) continue;	// 빈 곳 or 공기청정기

			int spread = arr[r][c] / 5;
			for (int i = 0; i < 4; i++) {
				int nr = r + dxy[i][0];
				int nc = c + dxy[i][1];
				
				if (nr < 0 || nr >= R || nc < 0 || nc >= C || (nc == 0 && (nr == air || nr == air - 1))) continue;
				tmp[nr][nc] += spread;
				arr[r][c] -= spread;
			}

			tmp[r][c] += arr[r][c];
		}
	}
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			arr[r][c] = tmp[r][c];
		}
	}
}

/*
 * 공기청정기를 따라 공기 순환
*/
void airCleaner() {
	for (int r = air + 1; r < R - 1; r++) arr[r][0] = arr[r + 1][0];
	for (int r = air - 2; r > 0; r--) arr[r][0] = arr[r - 1][0];
	
	for (int c = 0; c < C - 1; c++) {
		arr[0][c] = arr[0][c + 1];
		arr[R - 1][c] = arr[R - 1][c + 1];
	}

	for (int r = R - 1; r > air; r--) arr[r][C - 1] = arr[r - 1][C - 1];
	for (int r = 0; r < air - 1; r++) arr[r][C - 1] = arr[r + 1][C - 1];

	for (int c = C-1; c > 1; c--) {
		arr[air - 1][c] = arr[air - 1][c - 1];
		arr[air][c] = arr[air][c - 1];
	}

	arr[air - 1][1] = arr[air][1] = 0;
	arr[air - 1][0] = arr[air][0] = -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> T;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> arr[r][c];
			if (arr[r][c] == -1) air = r;
		}
	}

	for(int i = 0; i < T; i++) {
		pm();
		airCleaner();
	}

	int sum = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			sum += arr[r][c];
		}
	}
	cout << sum + 2;

	return 0;
}