// 고객 정보 구조체를 만들고
// map을 통해 고객 넘버 idx에서 바로 접근 가능하도록 하고
// map의 주소값으로 priority queue를 만들고...
// 업데이트는 map에서 업데이트하고...

#include<iostream>
#include<queue>
using namespace std;

int N, M, oil;
int arr[21][21];

// sx, sy, ex, ey
int info[402][5];

int sx, sy;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

// 최단경로 탐색 -> bfs 사용
// 0,1에서 출발해서 2,3까지의 거리
int bfs(int stx, int sty, int enx, int eny) {
	bool visited[21][21] = { false, };

	// 거리, x, y
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, { stx, sty } });
	visited[stx][sty] = true;

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int dist = q.front().first;

		q.pop();

		// 도착,, 시작 = 출발인 경우 0 리턴
		if (x == enx && y == eny) {
			return dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > N || ny <= 0 || ny > N || arr[nx][ny] == 1) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ dist + 1,{nx,ny} });
		}
	}

	// 음 오류발생!
	return -1;
}

// 가장 가까운 info 찾기
// return : 고객번호, 거리
pair<int, int> nearInfoMove() {

	// 우선순위가 높은 승객
	// x, y, dist, index
	int fx = 0, fy = 0, fd = 404, idx = 401;

	for (int i = 0; i < M; i++) {
		// 이미 태운 고객이면 패스
		if (info[i][4] == 1) continue;

		// 택시와 승객의 거리 계산
		int dist = bfs(sx, sy, info[i][0], info[i][1]);

		// 거리를 찾을 수 없는 경우 -> 분리된 지역..
		if (dist == -1) {
			return { -1,-1 };
		}

		// pq를 쓰는게 좋으려나,,?

		// 우선순위 체크
		if (dist < fd) {
			fx = info[i][0];
			fy = info[i][1];
			fd = dist;
			idx = i;
		}
		else if (dist == fd) {
			if (info[i][0] < fx) {
				fx = info[i][0];
				fy = info[i][1];
				idx = i;
			}
			else if (info[i][0] == fx) {
				if (info[i][1] < fy) {
					fy = info[i][1];
					idx = i;
				}
			}
		}
	}

	// 태웠습니다~
	info[idx][4] = 1;

	return { idx, fd };
}

void solve() {

	// 승객 수 만큼 반복
	for (int i = 0; i < M; i++) {
		// 제일 가까운 고객 정보
		pair<int, int> near = nearInfoMove();

		// 고객 번호, 택시에서 승객까지의 거리
		int idx = near.first;
		int dist1 = near.second;

		// 승객이 이동하는 거리
		int dist2 = bfs(info[idx][0], info[idx][1], info[idx][2], info[idx][3]);

		// 거리를 찾을 수 없는 고객이 존재하는 경우
		// or bfs 탐색을 했는데 도착하지 못했다!
		if (dist1 == -1 || dist2 == -1) {
			cout << -1 << '\n';
			return;
		}

		// 기름이 남는 경우, 딱 맞는 경우
		if (dist1 + dist2 <= oil) {
			// 기름 업뎃
			oil -= dist1;
			oil += dist2;

			// 택시 위치 업데이트
			sx = info[idx][2];
			sy = info[idx][3];
			continue;
		}
		else {
			// 이동하다가 퍼진 경우
			cout << -1 << '\n';
			return;
		}
	}

	// 모든 승객을 태워준 경우
	cout << oil << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> oil;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> sx >> sy;

	for (int i = 0; i < M; i++) {
		cin >> info[i][0] >> info[i][1] >> info[i][2] >> info[i][3];
		info[i][4] = 0;
	}

	solve();

	return 0;
}