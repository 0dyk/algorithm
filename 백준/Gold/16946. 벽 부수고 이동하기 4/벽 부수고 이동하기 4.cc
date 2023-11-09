#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// dir
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

// map size
int N, M;

// input 배열
int arr[1001][1001];

// 정답 배열
int res[1001][1001];

int umIdx;
unordered_map<int, int> um;

// INPUT
void input() {
	cin >> N >> M;
	char tmp;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> tmp;
			arr[i][j] = tmp - '0';
		}
	}
}

// 각 그룹 당 개수 체크
void unions() {
	umIdx = 1;
	// umIdx -> 2부터 시작
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] != 0) continue;

			int cnt = 1;
			arr[i][j] = ++umIdx;

			queue<pair<int, int>> q;
			q.push({ i,j });

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != 0) continue;
					q.push({ nx,ny });
					++cnt;
					arr[nx][ny] = umIdx;
				}
			}

			um[umIdx] = cnt;
		}
	}
}

// 계산
void solve() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			// 벽일 경우 지우고 체크하기
			if (arr[i][j] == 1) {
				int cnt = 1;
				
				unordered_set<int> us;

				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 1) continue;

					// 없는 친구면
					if (us.find(arr[nx][ny]) == us.end()) {
						us.insert(arr[nx][ny]);
						cnt += um[arr[nx][ny]];
					}
				}
				
				res[i][j] = cnt % 10;
			}
		}
	}
}

// res 출력
void output() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << res[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();
	unions();
	solve();
	output();

	return 0;
}