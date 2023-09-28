#include<iostream>
#include<queue>
using namespace std;

int N, M, K;
int cell;

// 크기, 남은 시간
pair<int, int> arr[700][700];
int st = 320;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

// 4방향 동시 번식
// X 시간 비활성 강태, X시간 활성 상태 이후 죽음
// 죽은 상태로 존재함
// 번식되면 비활성 상태

queue<pair<int, int>> inactive[2];

queue<pair<int, int>> active[2];

void solve() {
	for (int t = 0; t < K; t++) {
		// current hour
		int idx = t % 2;

		// next hour
		int nidx = (t + 1) % 2;

		// 비활성 상태 모두 체크하기
		while (!inactive[idx].empty()) {
			int x = inactive[idx].front().first;
			int y = inactive[idx].front().second;
			inactive[idx].pop();

			// 활성 상태로 변경
			if (--arr[x][y].second == 0) {
				active[nidx].push({ x,y });
			}
			else {
				inactive[nidx].push({ x,y });
			}
		}

		// 활성 상태 체크하기
		while (!active[idx].empty()) {
			int x = active[idx].front().first;
			int y = active[idx].front().second;
			active[idx].pop();

			// 첫 시간인 경우 배양하기 -> 여기서 모두 값이 감소 된다.
			if (arr[x][y].second-- == 0) {
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					
					// 감염 전 이거나... 이번 턴에 감염 + 내가 더 큰 경우 덮어쓰기
					if (arr[nx][ny].first == 0) {
						// 감염된 경우 좌표 저장
						arr[nx][ny] = { arr[x][y].first, arr[x][y].first };
						inactive[nidx].push({ nx,ny });
						cell++;
					}
					// 새로 갱신된 경우 값만 갱신
					else if (arr[nx][ny].first == arr[nx][ny].second && arr[nx][ny].first < arr[x][y].first) {
						arr[nx][ny] = { arr[x][y].first, arr[x][y].first };
					}
				}
			}

			// 죽은 경우 cell 감소
			if (arr[x][y].second * -1 == arr[x][y].first) {
				cell--;
			}
			else { // 죽지 않은 경우 다시 푸시
				active[nidx].push({ x,y });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T; cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M >> K;
		
		for (int i = 0; i < 700; i++) {
			for (int j = 0; j < 700; j++) {
				arr[i][j] = {0, 0};
			}
		}

		for (int i = 0; i < 2; i++) {
			while (!inactive[i].empty()) inactive[i].pop();
			while (!active[i].empty()) active[i].pop();
		}

		cell = 0;
		for (int row = st; row < st + N; row++) {
			for (int col = st; col < st + M; col++) {
				int tmp; cin >> tmp;
				arr[row][col] = { tmp, tmp };
				
				if (tmp != 0) {
					inactive[0].push({ row, col });
					cell++;
				}
			}
		}

		solve();

		cout << "#" << test_case << ' ' << cell << '\n';
	}

	return 0;
}