#include<iostream>
#include<queue>
using namespace std;

int N, K;
int sz, ND, line;
int arr[101];

// { num, value }
pair<int,int> map[101][101];
int dxy[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

/* map : -1로 초기화 */
void mapset() {
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			map[i][j] = {0, -1};
}

/* a와 b의 차 구하기 */
int cha(int a, int b) {
	return a > b ? a - b : b - a;
}

/* 달팽이 확산 */
void spread1() {
	mapset();

	int x = 100, y = 0;
	queue<pair<int, int>> q;
	// ND부터 오른쪽으로 N - ND만큼
	for (int i = 0; i <= N - ND; i++) {
		map[x][y + i] = { ND + i, arr[ND + i] };
		q.push({ x, y + i });
	}

	int dir = 0, tnd = ND, tline = line;
	int tsize = sz - (line - 1) % 2;
	// ND부터 ↑→↓← 소용돌이 돌기
	while (tnd > 1) {
		for (int i = 0; i < tsize; i++) {
			int nx = x + dxy[dir][0];
			int ny = y + dxy[dir][1];

			tnd -= 1;
			map[nx][ny] = { tnd, arr[tnd] };
			q.push({ nx,ny });
			x = nx; y = ny;
		}
		dir = (dir + 1) % 4;
		tsize -= (tline--) % 2;
	}

	// 확산하기 -> 바로 arr에 더하고 빼주기
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dxy[i][0];
			int ny = y + dxy[i][1];

			if (map[nx][ny].second == -1) continue;
			if (nx < 0 || nx >= 101 || ny < 0 || ny >= 101) continue;

			int c = cha(map[x][y].second, map[nx][ny].second) / 5;
			if (c) {
				if (map[x][y].second > map[nx][ny].second) { // x, y가 큰 경우
					arr[map[x][y].first] -= c;
					arr[map[nx][ny].first] += c;
				}
				else {	// nx, ny가 큰 경우
					arr[map[x][y].first] += c;
					arr[map[nx][ny].first] -= c;
				}
			}
		}
		map[x][y].second = -1;
	}

	int k = 1;
	int tmp[101] = { 0, };

	for (int j = 0; j <= N - ND; j++) {
		for (int i = 100; i >= 100 - sz; i--) {
			if (map[i][j].first != 0) tmp[k++] = arr[map[i][j].first];
			else break;
		}
		if (k > N) break;
	}


	for (int i = 1; i <= N; i++) arr[i] = tmp[i];
}

/* 4층 쌓기 */
void spread2() {
	mapset();

	// 0 ~ N/4 : N/4 ~ N/4*2 : N/4*2 ~ N/4*3 : N/4*3 ~ N

	int t = 1;
	for (int i = N / 4 - 1; i >= 0; i--) { map[2][i] = {t, arr[t]}; t++; }
	for (int i = 0; i < N / 4; i++) { map[1][i] = { t, arr[t] }; t++; }
	for (int i = N / 4 - 1; i >= 0; i--) { map[0][i] = { t, arr[t] }; t++; }
	for (int i = 0; i < N / 4; i++) { map[3][i] = { t, arr[t] }; t++; }


	// 확산
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N / 4; j++) {
			
			// 각 점마다 4방향 탐색
			for (int k = 0; k < 4; k++) {
				int ni = i + dxy[k][0];
				int nj = j + dxy[k][1];

				if (ni < 0 || nj < 0 || map[ni][nj].second == -1) continue;

				int c = cha(map[i][j].second, map[ni][nj].second) / 5;
				if (c) {
					if (map[i][j].second > map[ni][nj].second) {
						arr[map[i][j].first] -= c;
						arr[map[ni][nj].first] += c;
					}
					else {
						arr[map[i][j].first] += c;
						arr[map[ni][nj].first] -= c;
					}
				}
			}
			map[i][j].second = -1;	// 4방향 탐색이 끝난 위치는 다시 탐색하면 안됩니다 ~
		}
	}

	int  k = 1;
	int tmp[101] = { 0, };

	// tmp에 덧씌우기
	for (int j = 0; j < N / 4; j++) {
		for (int i = 3; i >= 0; i--) {
			tmp[k++] = arr[map[i][j].first];
		}
	}

	for (int i = 1; i <= N; i++) arr[i] = tmp[i];
}

/* 최솟값들에 +1 해주는 함수 */
void minPlus() {
	int minv = 987654231;
	for (int i = 1; i <= N; i++) if (arr[i] < minv) minv = arr[i];
	for (int i = 1; i <= N; i++) if (arr[i] == minv) arr[i]++;
}

/* 최대값과 최솟값의 차를 구해주는 함수 */
int getCha() {
	int maxv = 0;
	int minv = 987654321;
	for (int i = 1; i <= N; i++) {
		if (maxv < arr[i]) maxv = arr[i];
		if (minv > arr[i]) minv = arr[i];
	}

	return maxv - minv;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	ND = 1; sz = 1; line = 0;

	// Left Down, size 구하기
	while (N >= ND + line + 1) {
		line++;
		ND += sz;
		sz += (line + 1) % 2;
	}

	int t = 0;
	while (getCha() > K) {
		minPlus();
		spread1();
		spread2();
		t++;
	}

	cout << t << '\n';

	return 0;
}