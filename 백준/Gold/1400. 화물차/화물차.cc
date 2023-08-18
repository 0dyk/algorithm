#include<iostream>
#include<queue>
#define INF 987654321
using namespace std;

int N, M, minTime;
char arr[20][20];
int sx, sy, ex, ey;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

// 신호등 정보
struct trafficLight {
	int idx;
	char dir;
	int garo, sero;
};
trafficLight sinhodng[10];

// 다익스트라?
int dist[20][20];

// idx 신호등이 dir 방향으로 현재 t초일 때 언제 이동이 가능한지.
int waitTime(int idx, int t, int dir) {
	// 매 초 체크하는 건 에바요

	t %= (sinhodng[idx].garo + sinhodng[idx].sero);
	int garo = sinhodng[idx].garo;
	int sero = sinhodng[idx].sero;

	if (sinhodng[idx].dir == '-') {
		if (dir == 0 || dir == 1) { // 가로 이동을 원하는 경우
			if (t < garo) { // 가로 이동 가능
				return 1;
			} 
			else { // 가로 이동이 불가능 -> garo + sero 값만큼 되어야 이동 가능
				return garo + sero - t + 1;
			}
		}
		else { // 세로 이동을 원하는 경우
			if (t < garo) { // 가로 이동 가능
				return garo - t + 1;
			}
			else { // 세로 이동 가능
				return 1;
			}
		}
	}
	else { // 시작 '|'
		if (dir == 0 || dir == 1) {	// 가로 이동을 원하는 경우
			if (t < sero) { // 세로 이동 가능
				return sero - t + 1;
			}
			else {	// 가로 이동 가능
				return 1;
			}
		}
		else { // 세로 이동을 원하는 경우
			if (t < sero) { // 세로 이동 가능
				return 1;
			}
			else { // 가로 이동 가능
				return garo + sero - t + 1;
			}
		}
	}

	/*
	신호등 시간 계산법...
	dir = '-'인 경우

	// garo + sero로 나눈 나머지

	가로이동
	(0 ~ garo]

	세로 이동
	(garo ~ garo + sero]

	가로 이동
	(0 ~ garo]



	*/
}

// dijkstra
void bfs() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++){
			dist[r][c] = INF;
		}
	}

	// {time, {x, y}} : 걸린 시간, 현재 좌표 -> 시간이 짧은 순으로 정렬
	priority_queue < pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>> pq;
	pq.push({0, {sx, sy}});
	dist[sx][sy] = 0;
	
	while (!pq.empty()) {
		int t = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();

		// 도착
		if (x == ex && y == ey) {
			minTime = t;
			return;
		}

		for (int i = 0; i < 4; i++)	{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 범위를 벗어났거나 갈 수 없는 곳
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == '.') continue;
			
			// 이동하는 곳이 신호등인 경우
			if (arr[nx][ny] <= '9' && arr[nx][ny] >= '0') {
				// 몇 초 뒤에 이동가능한지 체크해서 그 시간으로 푸쉬하자
				int nt = waitTime(arr[nx][ny] - '0', t, i);

				if (dist[nx][ny] > dist[x][y] + nt) {
					dist[nx][ny] = dist[x][y] + nt;
					pq.push({ dist[nx][ny], {nx,ny} });
				}
			}
			else {	// 다음 위치가 #이거나 B인 경우
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					pq.push({ dist[nx][ny], { nx, ny } });
				}
			}
		}
	}
}

// dijkstra 1번으로 끝인가?
void solve() {
	bfs();

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(true){
		cin >> N >> M;

		// 종료 조건
		if (N == 0 && M == 0) break;

		int traffic = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++){
				cin >> arr[r][c];

				// 출발점 도착점 좌표
				if (arr[r][c] == 'A') { sx = r; sy = c; }
				if (arr[r][c] == 'B') { ex = r; ey = c; }

				// 신호등 수 count
				if (arr[r][c] >= '0' && arr[r][c] <= '9') traffic++;
			}
		}
		
		// 신호등 입력받기
		for (int i = 0; i < traffic; i++) {
			cin >> sinhodng[i].idx;
			cin >> sinhodng[i].dir;
			cin >> sinhodng[i].garo;
			cin >> sinhodng[i].sero;
		}

		minTime = INF;
		solve();
		if (minTime == INF) cout << "impossible" << '\n';
		else cout << minTime << '\n';
	}

	return 0;
}